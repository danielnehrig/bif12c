#include <stdbool.h>
#include <stdio.h>

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
bool placeValidation(int ***player,char *fieldArr,int *posX,int *posY) {
  if (***player == 1 && (*(fieldArr + *posY * BOARD_SIZE + *posX) == '-' || *(fieldArr + *posY * BOARD_SIZE + *posX) == '*')) {
    printf("\no Placed by Player 1\n");
    *(fieldArr + *posY * BOARD_SIZE + *posX) = PLAYER1_SYM;

    return true;
  }

  if (***player == 2 && (*(fieldArr + *posY * BOARD_SIZE + *posX) == '-' || *(fieldArr + *posY * BOARD_SIZE + *posX) == '*')) {
    printf("\nx Placed by Player 2\n");
    *(fieldArr + *posY * BOARD_SIZE + *posX) = PLAYER2_SYM;
    return true;
  }

  return false;
}

/*
 * Validates if Object can be placed and if currents player turn is over
 * @param {int} player
 * @param {char} fieldArr
 * @param {int} posX
 * @param {int} posY
 */
void place(int **player,char *fieldArr,int *posX,int *posY) {
  bool placed = false;
  placed = placeValidation(&player,fieldArr,posX,posY);

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
int winValidation(char fieldArr[BOARD_SIZE][BOARD_SIZE], int *turns) {
  int winner = 0;
  char marker;

  if (*turns > 4) {
    // row check
    for (int i = 0; i < BOARD_SIZE; i++) {
      marker = fieldArr[i][0];
      if (marker != '-' && marker != '*') {
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
        if (marker != '-' && marker != '*') {
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
    int diag = 1;
    if (winner == 0) {
      for (int i = 0; i < BOARD_SIZE; i++) {
        marker = fieldArr[i][i];
        if (marker != '-' && marker != '*') {
          if (fieldArr[i+diag][i+diag] == marker) {
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
