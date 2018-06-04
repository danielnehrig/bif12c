#include <stdio.h>
#include "settings.h"
#include "func.h"

/*
 * Render the Game Field
 * @param {char} fieldArr
 */
void fieldRender(char fieldArr[3][3]) {
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
 */
char temp = '-';
void move(char *fieldArr, char choose, int *posX, int *posY, int *player, int *turns) { 
  *(fieldArr + *posY * BOARD_SIZE + *posX) = temp;

  switch(choose) {
    case 'w': 
              (*posY)--;
              temp = *(fieldArr + *posY * BOARD_SIZE + *posX);
              break;
    case 'a': 
              (*posX)--;
              temp = *(fieldArr + *posY * BOARD_SIZE + *posX);
              break;
    case 's': 
              (*posY)++;
              temp = *(fieldArr + *posY * BOARD_SIZE + *posX);
              break;
    case 'd': 
              (*posX)++;
              temp = *(fieldArr + *posY * BOARD_SIZE + *posX);
              break;
    case 'p': 
              place(&player,fieldArr,posX,posY,turns);
              temp = *(fieldArr + *posY * BOARD_SIZE + *posX);
              break;
  }

  *(fieldArr + *posY * BOARD_SIZE + *posX) = temp;

  if(*posX < 0) {
    *posX = BOARD_SIZE-1;
  }
  if(*posX > BOARD_SIZE-1) {
    *posX = 0;
  }
  if(*posY < 0) {
    *posY = BOARD_SIZE-1;
  }
  if(*posY > BOARD_SIZE-1) {
    *posY = 0;
  }
  temp = *(fieldArr + *posY * BOARD_SIZE + *posX);

  if (choose != 'p') {
    if (*player == 1) {
      *(fieldArr + *posY * BOARD_SIZE + *posX) = PLAYER1_MOV_SYM;
    } else {
      *(fieldArr + *posY * BOARD_SIZE + *posX) = PLAYER2_MOV_SYM;
    }
  }
}
