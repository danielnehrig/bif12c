#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// Proto
char * stringRemoveChars(char *, char *);
// Main exec
int main() {
  char string[] = "8Die1schoenen4Dinge6im3Leben9sind0umsonst.5";
  char spanset[] = "1234567890";

  printf("vorher: \t%s\n", string);
  stringRemoveChars(string, spanset);
  printf("nacher: \t%s\n", string);
  return 0;
}
// Removeing Chars Function
char * stringRemoveChars(char *string, char *spanset) {
  // init pointer set equal to string
  char *ptr = string;
  // set pointer equal to the search of the spanset inside the pointer
  ptr = strpbrk(ptr, spanset);

  // Loop while pointer isn't NULL
  while(ptr != NULL) {
    // replace pointer with space
    *ptr = ' ';
    // set pointer equal to the search of the spanset inside the pointer
    ptr = strpbrk(ptr, spanset);
  }

  return string;
}
