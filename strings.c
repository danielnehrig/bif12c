#include <stdlib.h>
#include <stdio.h>
#include <strings.h>

int main() {
  // Deklarieren eines Strings
  char string[] = "das ist ein kurzer satz.";
  printf("Denke dran, %s\n", string);
  // strlen zaehlt die characters in einem string
  int laenge = strlen(string);
  printf("laenge: %d Zeichen\n", laenge);
  // strcpy(char *dest, char *src)
  char string2[] = "abc";
  char string3[] = "abc";
  // Hier wird string2 xyz zugewiesen
  strcpy(string2, "xyz");
  printf("\nAus abc wird: %s", string2);
  // strncpy(char *dest, char *src, int n) eine bestimmte anzahl von zeichen kopieren
  strncpy(string2, string3, 1);
  printf("\nAus xyz wird: %s", string2);
  // strcat(char *dest, char *src); Strings verketten
  char test[10] = "testo";
  char test2[10] = "123";
  strcat(test, test2);
  printf("\n\nis: %s\n\n", test);

  char textA[10] = "abc";
  char textB[10] = "defxyz";

  printf("Text A: %s\nText B: %s\n\n", textA, textB);

  // haenge 3 Zeichen aus textB der Zeichenkette textA an
  strncat(textA, textB, 3);
  
  printf("Text A: %s\nText B: %s\n\n", textA, textB);

  return 0;
}
