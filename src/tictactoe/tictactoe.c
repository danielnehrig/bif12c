#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include "settings.h"

/*
 * Validates if the Current Choosen Letter is applicable
 * @param {char} choose - The var which holds the letter which got choosen
 */
bool chooseValidation(char choose) {
  if (choose != 'a' && choose != 'w' && choose != 's' && choose != 'd' && choose != 'p' && choose != 'x') {
    printf("Use one of the Defined Characters to move and place\n");
    return true;
  }

  return false;
}

/*
 * Validates if the current index holds a Char which isn't supposed to be overwritten on placeing
 * @param {int} ***player the given player which currently is at turn
 * @param {char} *fieldArr the array which holds the game field
 * @param {int} *posX X axis
 * @param {int} *posY Y axis
 * @param {int} BOARD_SIZE
 */
bool placeValidation(int ***player,char **fieldArr,int *posX,int *posY,int BOARD_SIZE) {
  if (***player == 1 && (fieldArr[*posY][*posX] != PLAYER2_SYM && fieldArr[*posY][*posX] != PLAYER1_SYM)) {
    fieldArr[*posY][*posX] = PLAYER1_SYM;

    return true;
  }

  if (***player == 2 && (fieldArr[*posY][*posX] != PLAYER2_SYM && fieldArr[*posY][*posX] != PLAYER1_SYM)) {
    fieldArr[*posY][*posX] = PLAYER2_SYM;
    return true;
  }

  return false;
}

/*
 * Validates if Object can be placed and if current player turn is over
 * @param {int} player
 * @param {char} fieldArr
 * @param {int} posX
 * @param {int} posY
 */
void place(int **player,char **fieldArr,int *posX,int *posY,int BOARD_SIZE,int *turns) {
  bool placed = false;
  placed = placeValidation(&player,fieldArr,posX,posY,BOARD_SIZE);

  if (placed && **player == 1) {
    (*turns)++;
    (**player) = 2;
  } else if (placed && **player == 2) {
    (*turns)++;
    (**player) = 1;
  } else {
    printf("\nNo player change %d", **player);
  }
}


/*
 * Validates the winner of the Game
 * @param {char} fieldArr
 * @param {int} turns
 * @param {int} BOARD_SIZE
 * @param {int} winAmount
 */
int winValidation(char **fieldArr, int *turns, int BOARD_SIZE, int winAmount) {
  int winner = 0;
  int countDiag = 0;
  char marker;

  if (*turns > (winAmount * 2) - 1) {
    // row check
    for (int i = 0; i < BOARD_SIZE; i++) {
      for (int k = 1; k < BOARD_SIZE; k++) {
        marker = fieldArr[i][0];
        if (marker != '-' && (marker != PLAYER1_MOV_SYM && marker != PLAYER2_MOV_SYM)) {
          if (fieldArr[i][k] == marker) {
            countDiag++;
            if (marker == PLAYER1_SYM) {
              winner = 1;
            } else {
              winner = 2;
            }
          }
        }
      }
    }

    // Column Check
    if (winner == 0) {
      countDiag = 0;
      for (int i = 0; i < BOARD_SIZE; i++) {
        for (int k = 0; k < BOARD_SIZE; k++) {
          marker = fieldArr[0][i];
          if (marker != '-' && (marker != PLAYER1_MOV_SYM && marker != PLAYER2_MOV_SYM)) {
            if (fieldArr[k][i] == marker) {
              countDiag++;
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

    // Left to Right Diag Check
    if (winner == 0) {
      countDiag = 0;
      for (int i = 0; i < BOARD_SIZE; i++) {
        marker = fieldArr[i][i];
        if (marker != '-' && (marker != PLAYER1_MOV_SYM && marker != PLAYER2_MOV_SYM)) {
          if (fieldArr[i+1][i+1] == marker) {
            countDiag++;
            if (countDiag == BOARD_SIZE-1) {
              printf("Diag LR Win\n");
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

    //  Right to Left Diag Check
    if (winner == 0) {
      int i = BOARD_SIZE-1;
      countDiag = 0;
      for (int k = 0; k < BOARD_SIZE; i--, k++) {
        marker = fieldArr[k][i];
        if (marker != '-' && (marker != PLAYER1_MOV_SYM && marker != PLAYER2_MOV_SYM)) {
          if (fieldArr[k+1][i-1] == marker) {
            countDiag++;
            if (countDiag == BOARD_SIZE-1) {
              printf("Diag RL Win\n");
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

/*
 * Render the Game Field
 * @param {char} fieldArr
 * @param {int} BOARD_SIZE
 */
void fieldRender(char **fieldArr,int BOARD_SIZE) {
  for (int i=0; i < BOARD_SIZE; i++) {
    for (int k=0; k < BOARD_SIZE; k++) {
      printf("[ %c ]\t", fieldArr[i][k]);
    }
    printf("\n\n");
  }
}

/*
 * Move the Player Position or do your placement
 * @param {char} fieldArr
 * @param {char} choose
 * @param {int} posX
 * @param {int} posY
 * @param {int} player
 * @param {int} turns
 * @param {int} BOARD_SIZE
 */
char temp = '-';
void move(char **fieldArr, char choose, int *posX, int *posY, int *player, int *turns, int BOARD_SIZE) { 

  switch(choose) {
    case 'w': fieldArr[*posY][*posX] = temp;
              (*posY)--;
              temp = fieldArr[*posY][*posX];
              if (*player == 1) {
                fieldArr[*posY][*posX] = PLAYER1_MOV_SYM;
              } else {
                fieldArr[*posY][*posX] = PLAYER2_MOV_SYM;
              }
              break;
    case 'a': fieldArr[*posY][*posX] = temp;
              (*posX)--;
              temp = fieldArr[*posY][*posX];
              if (*player == 1) {
                fieldArr[*posY][*posX] = PLAYER1_MOV_SYM;
              } else {
                fieldArr[*posY][*posX] = PLAYER2_MOV_SYM;
              }
              break;
    case 's': fieldArr[*posY][*posX] = temp;
              (*posY)++;
              temp = fieldArr[*posY][*posX];
              if (*player == 1) {
                fieldArr[*posY][*posX] = PLAYER1_MOV_SYM;
              } else {
                fieldArr[*posY][*posX] = PLAYER2_MOV_SYM;
              }
              break;
    case 'd': fieldArr[*posY][*posX] = temp;
              (*posX)++;
              temp = fieldArr[*posY][*posX];
              if (*player == 1) {
                fieldArr[*posY][*posX] = PLAYER1_MOV_SYM;
              } else {
                fieldArr[*posY][*posX] = PLAYER2_MOV_SYM;
              }
              break;
    case 'p': fieldArr[*posY][*posX] = temp;
              place(&player,fieldArr,posX,posY,BOARD_SIZE,turns);
              temp = fieldArr[*posY][*posX];
              break;
  }

  // Note auslagern in andere funktion
  if(*posX < 0) {
      fieldArr[*posY][*posX] = temp;
      *posX = BOARD_SIZE-1;
      printf("\nReset 1\n");
      temp = fieldArr[*posY][*posX];
      if (*player == 1) {
        fieldArr[*posY][*posX] = PLAYER1_MOV_SYM;
      } else {
        fieldArr[*posY][*posX] = PLAYER2_MOV_SYM;
      }
  }
  if(*posX > BOARD_SIZE-1) {
      fieldArr[*posY][*posX] = temp;
      *posX = 0;
      printf("\nReset 2\n");
      temp = fieldArr[*posY][*posX];
      if (*player == 1) {
        fieldArr[*posY][*posX] = PLAYER1_MOV_SYM;
      } else {
        fieldArr[*posY][*posX] = PLAYER2_MOV_SYM;
      }
  }
  if(*posY < 0) {
      fieldArr[*posY][*posX] = temp;
      *posY = BOARD_SIZE-1;
      printf("\nReset 3\n");
      temp = fieldArr[*posY][*posX];
      if (*player == 1) {
        fieldArr[*posY][*posX] = PLAYER1_MOV_SYM;
      } else {
        fieldArr[*posY][*posX] = PLAYER2_MOV_SYM;
      }
  }
  if(*posY > BOARD_SIZE-1) {
      fieldArr[*posY][*posX] = temp;
      *posY = 0;
      printf("\nReset 4\n");
      temp = fieldArr[*posY][*posX];
      if (*player == 1) {
        fieldArr[*posY][*posX] = PLAYER1_MOV_SYM;
      } else {
        fieldArr[*posY][*posX] = PLAYER2_MOV_SYM;
      }
  }
}

int main(int argc, char *argv[]) {
  srand(time(NULL));
  int BOARD_SIZE = 3;
  char **fieldArr;
  char choose;
  int winAmount = 3;
  int posX = 0, posY = 0;
  int player = 1;
  int turns = 0;
  int winner = 0;
  int coinflip = 0;

  // Dynamiclly allocate memory 2d array of chars
  //do {
  //  printf("Enter Board Size Between 3 and 20 : ");
  //  scanf(" %d", &BOARD_SIZE);
  //} while ( BOARD_SIZE < 3 && BOARD_SIZE > 20 );

  //do {
  //  printf("\nEnter Win Amount Between 3 and 6 : ");
  //  scanf(" %d", &winAmount);
  //} while ( winAmount < 3 && winAmount > 6 );

  // Single Array allocating
  fieldArr = malloc(BOARD_SIZE * sizeof(char*));
  for (int i = 0; i < BOARD_SIZE; i++) {
    // Allocate an array inside the array
    fieldArr[i] = malloc(BOARD_SIZE * sizeof(char));
  }

  // Initilize Array fields with a symbol
  for (int i = 0; i < BOARD_SIZE; i++) {
    for (int k = 0; k < BOARD_SIZE; k++) {
      fieldArr[i][k] = FIELD_REN_SYM;
    }
  }

  coinflip = (rand() % 2) + 1;
  player = coinflip;
  char starting = (player == 1) ? PLAYER1_MOV_SYM: PLAYER2_MOV_SYM;
  fieldArr[0][0] = starting;

  do {
    printf("\n********************\n");
    printf("** TicTacToe Game **\n");
    printf("********************\n");
    printf("\nPress x to exit the game\n\n");
    fieldRender(fieldArr, BOARD_SIZE);

    if (turns == 0) {
      printf("Coinflip Player %d starts", coinflip);
    }

    do {
      if (player == 1) {
        printf("\nPlayer 1 Turn\n");
      } else {
        printf("\nPlayer 2 Turn\n");
      }

      printf("\nMove with W A S D and P to Place : ");
      scanf(" %c", &choose);
    } while (chooseValidation(choose));

    clrscr();
    move(fieldArr, choose, &posX, &posY, &player, &turns, BOARD_SIZE);
    winner = winValidation(fieldArr, &turns, BOARD_SIZE, winAmount);
    printf("\nTURNS = %d\n", turns);
  } while (choose != 'x' && winner == 0 && turns < (BOARD_SIZE * BOARD_SIZE));

  (winner != 0) ? printf("The Winner is Player %d\n", winner) : printf("No Winner in this Game\n");

  for (int i = 0; i < BOARD_SIZE; i++) {
    free(fieldArr[i]);
  }
  free(fieldArr);

  return EXIT_SUCCESS;
}
