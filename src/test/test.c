#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  int size = 0;

  // Get Array Size square
  do {
    printf("Enter size between 3 - 20 : ");
    scanf(" %d", &size);
  } while (size < 3 || size > 20);

  // Create Array
  char **arr;
  arr = malloc(size * sizeof(char*));

  // Create 2D Array
  for (int i = 0; i < size; i++) {
    arr[i] = malloc(size * sizeof(char));
  }

  // Init Array with dash
  for (int i = 0; i < size; i++) {
    for (int k = 0; k < size; k++) {
      arr[i][k] = '-';
    }
  }

  arr[1][2] = '+';

  // Print Field
  for (int i = 0; i < size; i++) {
    for (int k = 0; k < size; k++) {
      printf("[ %c ] ", arr[i][k]);
    }
    printf("\n");
  }
  return 1;
}
