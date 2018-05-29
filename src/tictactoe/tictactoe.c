#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include "settings.h"
#include "func.h"

int main(int argc, char *argv[]) {
  srand(time(NULL));
  BOARD_SIZE = 3;
  char **fieldArr;
  char choose;
  int posX = 0, posY = 0;
  int player = 1;
  int turns = 0;
  int winner = 0;
  int coinflip = 0;

  // Dynamiclly allocate memory 2d array of chars
  printf("Enter Board Size : ");
  scanf(" %d", &BOARD_SIZE);
  // Single Array allocating
  fieldArr = malloc(BOARD_SIZE * sizeof(char*));
  for (int i = 0; i < BOARD_SIZE; i++) {
    // Allocate an array inside the array
    fieldArr[i] = malloc(BOARD_SIZE * sizeof(char));
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
    fieldRender(fieldArr);

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
    move(*fieldArr, choose, &posX, &posY, &player, &turns);
    winner = winValidation(fieldArr, &turns);
  } while (choose != 'x' && winner == 0 && turns < (BOARD_SIZE * BOARD_SIZE));

  (winner != 0) ? printf("The Winner is Player %d\n", winner) : printf("No Winner in this Game\n");

  for (int i = 0; i < BOARD_SIZE; i++) {
    free(fieldArr[i]);
  }
  free(fieldArr);

  return EXIT_SUCCESS;
}
