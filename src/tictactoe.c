#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "settings.h"

int BOARD_SIZE = 3;
char FIELD_REN_SYM = '-';
char PLAYER1_SYM = 'o';
char PLAYER2_SYM = 'x';
char PLAYER1_MOV_SYM = '1';
char PLAYER2_MOV_SYM = '2';

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
  for(int i=0;i<BOARD_SIZE;i++) {
    for(int k=0;k<BOARD_SIZE;k++) {

      printf("[ %c ]\t", fieldArr[i][k]);
    }
    printf("\n\n");
  }
}

bool placeValidation(int ***player,char *fieldArr,int *posX,int *posY) {
  if(***player == 1 && (*(fieldArr + *posY * BOARD_SIZE + *posX) == '-' || *(fieldArr + *posY * BOARD_SIZE + *posX) == '*')) {
    printf("\no Placed by Player 1\n");
    *(fieldArr + *posY * BOARD_SIZE + *posX) = PLAYER1_SYM;

    return true;
  }

  if(***player == 2 && (*(fieldArr + *posY * BOARD_SIZE + *posX) == '-' || *(fieldArr + *posY * BOARD_SIZE + *posX) == '*')) {
    printf("\nx Placed by Player 2\n");
    *(fieldArr + *posY * BOARD_SIZE + *posX) = PLAYER2_SYM;

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

int winValidation(char fieldArr[BOARD_SIZE][BOARD_SIZE], int *turns) {
  int winner = 0;
  char marker;

  if (*turns > 4) {
    // row check
    for (int i = 0; i < BOARD_SIZE; i++) {
      marker = fieldArr[i][0];
      if(marker != '-' && marker != '*') {
        if(fieldArr[i][1] == marker &&
           fieldArr[i][2] == marker) {
          printf("Row Win\n");
          if(marker == PLAYER1_SYM) {
            winner = 1;
          } else {
            winner = 2;
          }
        }
      }
    }

    // Column Check
    if (winner == 0) {
      for (int i = 0; i < BOARD_SIZE; i++) {
        marker = fieldArr[0][i];
        if(marker != '-' && marker != '*') {
          if(fieldArr[1][i] == marker &&
             fieldArr[2][i] == marker) {
            printf("Column Win\n");
            if(marker == PLAYER1_SYM) {
              winner = 1;
            } else {
              winner = 2;
            }
          }
        }
      }
    }

    // Left to Right Diag Check
    int countDiag = 0;
    int diag = 1;
    if (winner == 0) {
      for (int i = 0; i < BOARD_SIZE; i++) {
        marker = fieldArr[i][i];
        if(marker != '-' && marker != '*') {
          if(fieldArr[i+diag][i+diag] == marker) {
            countDiag++;
            if (countDiag == 2) {
              printf("Column Win\n");
              if (marker == PLAYER1_SYM) {
                winner = 1;
              } else {
                winner = 2;
              }
            }
          }
        }
      }
    }
  }

  return winner;
}

void move(char *fieldArr, char choose, int *posX, int *posY, int *player, int *turns) { 
  char temp = *(fieldArr + *posY * BOARD_SIZE + *posX);
  //*(fieldArr + *posY * 3 + *posX) = '-';


  switch(choose) {
    case 'w': (*posY)-- ; break;
    case 'a': (*posX)-- ; break;
    case 's': (*posY)++ ; break;
    case 'd': (*posX)++ ; break;
    case 'p': place(&player,fieldArr,posX,posY); (*turns)++ ; break;
  }

  if(*posX < 0) *posX = BOARD_SIZE-1;
  if(*posX > BOARD_SIZE-1) *posX = 0;
  if(*posY < 0) *posY = BOARD_SIZE-1;
  if(*posY > BOARD_SIZE-1) *posY = 0;

  printf("\n%c %d %d - player : %d\n", *(fieldArr + *posY * BOARD_SIZE + *posX),*posY,*posX,*player);
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
  fieldArr[posX][posY] = FIELD_REN_SYM;
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
  } while (choose != 'x' && winner == 0 && turns < BOARD_SIZE*BOARD_SIZE);

  (winner != 0) ? printf("The Winner is Player %d\n", winner): printf("No Winner in this Game\n");

  return 1;
}
