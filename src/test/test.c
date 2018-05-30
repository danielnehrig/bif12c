#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  int size = 3;
  char **arr;
  arr = malloc(size * sizeof(char));
  for (int i = 0; i < size; i++) {
    arr[i] = malloc(size * sizeof(char));
  }

  for (int i = 0; i < size; i++) {
    for (int k = 0; k < size; k++) {
      *(arr + i * size + k) = '-';
    }
  }

  for (int i = 0; i < size; i++) {
    for (int k = 0; k < size; k++) {
      printf("[ %c ] ", arr[i][k]);
    }
    printf("\n");
  }
  return 1;
}
