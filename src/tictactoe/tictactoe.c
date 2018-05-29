#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "settings.h"
#include "func.h"

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
    move(*fieldArr, choose, &posX, &posY, &player, &turns);
    winner = winValidation(fieldArr, &turns);
  } while (choose != 'x' && winner == 0 && turns < (BOARD_SIZE * BOARD_SIZE));

  (winner != 0) ? printf("The Winner is Player %d\n", winner): printf("No Winner in this Game\n");

  return EXIT_SUCCESS;
}
