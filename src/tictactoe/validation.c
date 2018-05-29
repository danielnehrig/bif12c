#include <stdbool.h>
#include <stdio.h>
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
 */
bool placeValidation(int ***player,char *fieldArr,int *posX,int *posY,int BOARD_SIZE) {
  if (***player == 1 && (*(fieldArr + *posY * BOARD_SIZE + *posX) != 'x' && *(fieldArr + *posY * BOARD_SIZE + *posX) != 'o')) {
    *(fieldArr + *posY * BOARD_SIZE + *posX) = PLAYER1_SYM;

    return true;
  }

  if (***player == 2 && (*(fieldArr + *posY * BOARD_SIZE + *posX) != 'x' && *(fieldArr + *posY * BOARD_SIZE + *posX) != 'o')) {
    *(fieldArr + *posY * BOARD_SIZE + *posX) = PLAYER2_SYM;
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
void place(int **player,char *fieldArr,int *posX,int *posY,int BOARD_SIZE) {
  bool placed = false;
  placed = placeValidation(&player,fieldArr,posX,posY,BOARD_SIZE);

  if (placed && **player == 1) {
    (**player) = 2;
  } else if (placed && **player == 2) {
    (**player) = 1;
  } else {
    printf("\nNo player change %d", **player);
  }
}

/*
 * Validates the winner of the Game
 * @param {char} fieldArr
 * @param {int} turns
 */
int winValidation(char **fieldArr, int *turns, int BOARD_SIZE) {
  int winner = 0;
  char marker;

  if (*turns > 4) {
    // row check
    for (int i = 0; i < BOARD_SIZE; i++) {
      marker = fieldArr[i][0];
      if (marker != '-' && (marker != PLAYER1_MOV_SYM && marker != PLAYER2_MOV_SYM)) {
        if (fieldArr[i][1] == marker &&
           fieldArr[i][2] == marker) {
          printf("Row Win\n");
          if (marker == PLAYER1_SYM) {
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
        if (marker != '-' && (marker != PLAYER1_MOV_SYM && marker != PLAYER2_MOV_SYM)) {
          if (fieldArr[1][i] == marker &&
             fieldArr[2][i] == marker) {
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

    // Left to Right Diag Check
    int countDiag = 0;
    if (winner == 0) {
      for (int i = 0; i < BOARD_SIZE; i++) {
        marker = fieldArr[i][i];
        if (marker != '-' && (marker != PLAYER1_MOV_SYM && marker != PLAYER2_MOV_SYM)) {
          if (fieldArr[i+1][i+1] == marker) {
            countDiag++;
            if (countDiag == 2) {
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
    countDiag = 0;
    int i = 2;
    if (winner == 0) {
      for (int k = 0; k < BOARD_SIZE; i--, k++) {
        marker = fieldArr[k][i];
        if (marker != '-' && (marker != PLAYER1_MOV_SYM && marker != PLAYER2_MOV_SYM)) {
          if (fieldArr[k+1][i-1] == marker) {
            countDiag++;
            if (countDiag == 2) {
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
