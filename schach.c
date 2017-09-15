#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// Prototypes
void printField(int *field);
void move(int *field, int *posX, int *posY, char zug);

int main() {
  int field[8][8] = { 0 }, posX=0, posY=0;
  char zug;

  // Init Chess Field with default position
  field[posY][posX] = 1;

  printf("\nBeenden mit x\n");

  // Loop Field rendering while a movement is made
  do {
    printField(&field[0][0]);
    printf("Zug [w hoch, a links, s runter, d rechts]: ");
    scanf("%c", &zug);
    move(&field[0][0], &posX, &posY, zug);
  }while(zug != 'x');

  return 0;
}
// Render Chess Field
void printField(int *field) {
  printf("\n");
  int i, j;

  for(i=0;i<8;i++) {
    for(j=0;j<8;j++) {
      printf("%d ", *(field+i*8+j));
    }
    printf("\n");
  }
}

// Movement Function
void move(int *field, int *posX, int *posY, char zug) {
  *(field + *posY * 8 + *posX) = 0;

  switch(zug) {
    case 'w': (*posY)--; break;
    case 'a': (*posX)--; break;
    case 's': (*posY)++; break;
    case 'd': (*posX)++; break;
  }

  if(*posX < 0) *posX = 7;
  if(*posX > 7) *posX = 0;
  if(*posY < 0) *posY = 7;
  if(*posY > 7) *posY = 0;

  *(field + *posY * 8 + *posX) = 1;
}
