#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#define clrscr() printf("\e[1;1H\e[2J");

// Validation stuff
bool chooseValidation(char choose) {
  if(choose != 'a' && choose != 'w' && choose != 's' && choose != 'd' && choose != 'p' && choose != 'x') {
    printf("Use one of the Defined Characters to move and place\n");
    return true;
  }
  return false;
}

// Game Logic
void fieldRender(char fieldArr[3][3]) {
  for(int i=0;i<3;i++) {
    for(int k=0;k<3;k++) {
      printf("[ %c ]\t", fieldArr[i][k]);
    }
    printf("\n\n");
  }
}

bool placeValidation(int ***player,char *fieldArr,int *posX,int *posY) {
  if(***player == 1 && *(fieldArr + *posY * 3 + *posX) == '-') {
    printf("\no Placed by Player 1\n");
    *(fieldArr + *posY * 3 + *posX) = 'o';
    return true;
  }
  if(***player == 2 && *(fieldArr + *posY * 3 + *posX) == '-') {
    printf("\nx Placed by Player 2\n");
    *(fieldArr + *posY * 3 + *posX) = 'x';
    return true;
  }
  return false;
}

void place(int **player,char *fieldArr,int *posX,int *posY) {
  bool placed = false;
  placed = placeValidation(&player,fieldArr,posX,posY);
  if(placed && **player == 1) {
    (**player) = 2;
  } else if(placed && **player == 2) {
    (**player) = 1;
  } else {
    printf("\nNo player change %d", **player);
  }
}

int winValidation(char fieldArr[3][3], int *turns) {
  int winner = 0;
  int counting = 0;
  int o = 0;
  int p = 0;
  if (*turns >= 5) {
    for (int i = 0; i < 3; i++) {
      for (int k = 0; k < 3; k++) {
        // Horizontal WinValidation
        printf("DEBUG %c and %c\n", fieldArr[i][k], fieldArr[i][k+o]);
        if (fieldArr[i][k] == fieldArr[i][k+o] && (fieldArr[i][k] == 'x' || fieldArr[i][k] == 'o')) {
          counting++;
          printf("DEBUG Count = %d\n", counting);
          k++;
          o--;
        }
      }
    }
  }
  if ( counting == 2 ) {
    winner = 1;
  }
  return winner;
}

void move(char *fieldArr, char choose, int *posX, int *posY, int *player, int *turns) { 
  //*(fieldArr + *posY * 3 + *posX) = '-';


  switch(choose) {
    case 'w': (*posY)-- ; break;
    case 'a': (*posX)-- ; break;
    case 's': (*posY)++ ; break;
    case 'd': (*posX)++ ; break;
    case 'p': place(&player,fieldArr,posX,posY); (*turns)++ ; break;
  }

  if(*posX < 0) *posX = 2;
  if(*posX > 2) *posX = 0;
  if(*posY < 0) *posY = 2;
  if(*posY > 2) *posY = 0;

  printf("\n%c %d %d - player : %d\n", *(fieldArr + *posY * 3 + *posX),*posY,*posX,*player);
  //*(fieldArr + *posY * 3 + *posX) = *player;
}

// **** //
// main //
// **** //
int main() {
  char fieldArr[3][3] = {
                          {'-','-','-'},
                          {'-','-','-'},
                          {'-','-','-'}
                        };
  char choose;
  int posX = 0, posY = 0;
  fieldArr[posX][posY] = '-';
  int player = 1;
  int turns = 0;
  int winner = 0;

  do {
    printf("\n********************\n");
    printf("** TicTacToe Game **\n");
    printf("********************\n");
    printf("\nPress x to exit the game\n\n");
    fieldRender(fieldArr);

    do {
      if(player == 1) {
        printf("\nPlayer 1 Turn\n");
      } else {
        printf("\nPlayer 2 Turn\n");
      }

      printf("\nMove with W A S D and P to Place : ");
      scanf(" %c", &choose);
    } while(chooseValidation(choose));

    clrscr();
    move(*fieldArr,choose,&posX,&posY,&player,&turns);
    winner = winValidation(fieldArr,&turns);

    if (winner == 1 || winner == 2) {
      break;
    }
  } while (choose != 'x');

  printf("The Winner is Player %d", winner);

  return 1;
}
