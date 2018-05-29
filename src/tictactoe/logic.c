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
void move(char *fieldArr, char choose, int *posX, int *posY, int *player, int *turns) { 
  char temp = *(fieldArr + *posY * BOARD_SIZE + *posX);
  //*(fieldArr + *posY * 3 + *posX) = '-';

  switch(choose) {
    case 'w': (*posY)--; break;
    case 'a': (*posX)--; break;
    case 's': (*posY)++; break;
    case 'd': (*posX)++; break;
    case 'p': place(&player,fieldArr,posX,posY); (*turns)++; break;
  }

  if(*posX < 0) *posX = BOARD_SIZE-1;
  if(*posX > BOARD_SIZE-1) *posX = 0;
  if(*posY < 0) *posY = BOARD_SIZE-1;
  if(*posY > BOARD_SIZE-1) *posY = 0;

  printf("\n%c %d %d - player : %d\n", *(fieldArr + *posY * BOARD_SIZE + *posX), *posY, *posX, *player);
  //*(fieldArr + *posY * 3 + *posX) = *player;
}
