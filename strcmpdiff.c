#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// Proto
char * stringCompareDif(char *string1, char *string2, char *result);
// exec main
int main() {
  char string1[] = "das ist ein test der abweichen soll";
  char string2[] = "eas ist ein Test der abkeichen s0ll";
  char result[100];
  printf("String 1: \t%s\n", string1);
  printf("String 2: \t%s\n", string2);
  stringCompareDif(string1,string2,result);
  printf("Unterschied: \t%s\n", result);
  return 0;
}
// Compare String Function output Diff
char * stringCompareDif(char *string1, char *string2, char *result) {
  int i, c=0;
  // Get string length
  int len1 = strlen(string1);
  int len2 = strlen(string2);
  // len versteh ich grad nicht
  int len = (len1 < len2)?len1:len2;
  // Loop through until i isn't smaller then len anymore
  for(i=0;i<len; i++) {
    // compare if strings aren't equal if so increment c and res result
    if(string1[i] != string2[i]) {
      result[c] = string2[i];
      c++;
    }
  }
  // set the end of the string
  result[c] = '\0';

  // return the result
  return result;
}
