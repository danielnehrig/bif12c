#include <stdio.h>
#include "settings.h"
#include "func.h"

/*
 * Render the Game Field
 * @param {char} fieldArr
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
 */
char temp = '-';
void move(char *fieldArr, char choose, int *posX, int *posY, int *player, int *turns, int BOARD_SIZE) { 

  switch(choose) {
    case 'w': *(fieldArr + *posY * BOARD_SIZE + *posX) = temp;
              (*posY)--;
              temp = *(fieldArr + *posY * BOARD_SIZE + *posX);
              if (*player == 1) {
                *(fieldArr + *posY * BOARD_SIZE + *posX) = PLAYER1_MOV_SYM;
              } else {
                *(fieldArr + *posY * BOARD_SIZE + *posX) = PLAYER2_MOV_SYM;
              }
              break;
    case 'a': *(fieldArr + *posY * BOARD_SIZE + *posX) = temp;
              (*posX)--;
              temp = *(fieldArr + *posY * BOARD_SIZE + *posX);
              if (*player == 1) {
                *(fieldArr + *posY * BOARD_SIZE + *posX) = PLAYER1_MOV_SYM;
              } else {
                *(fieldArr + *posY * BOARD_SIZE + *posX) = PLAYER2_MOV_SYM;
              }
              break;
    case 's': *(fieldArr + *posY * BOARD_SIZE + *posX) = temp;
              (*posY)++;
              temp = *(fieldArr + *posY * BOARD_SIZE + *posX);
              if (*player == 1) {
                *(fieldArr + *posY * BOARD_SIZE + *posX) = PLAYER1_MOV_SYM;
              } else {
                *(fieldArr + *posY * BOARD_SIZE + *posX) = PLAYER2_MOV_SYM;
              }
              break;
    case 'd': *(fieldArr + *posY * BOARD_SIZE + *posX) = temp;
              (*posX)++;
              temp = *(fieldArr + *posY * BOARD_SIZE + *posX);
              if (*player == 1) {
                *(fieldArr + *posY * BOARD_SIZE + *posX) = PLAYER1_MOV_SYM;
              } else {
                *(fieldArr + *posY * BOARD_SIZE + *posX) = PLAYER2_MOV_SYM;
              }
              break;
    case 'p': *(fieldArr + *posY * BOARD_SIZE + *posX) = temp;
              place(&player,fieldArr,posX,posY); (*turns)++;
              temp = *(fieldArr + *posY * BOARD_SIZE + *posX);
              break;
  }

  if(*posX < 0) *posX = BOARD_SIZE-1;
  if(*posX > BOARD_SIZE-1) *posX = 0;
  if(*posY < 0) *posY = BOARD_SIZE-1;
  if(*posY > BOARD_SIZE-1) *posY = 0;
  printf("At position [%d][%d] Currently\n", *posY, *posX);
}
