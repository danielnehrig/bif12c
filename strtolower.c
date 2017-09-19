// Include
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
// Proto
char * stringToLower(char*);
// exec
int main() {
  // init string
  char string[] = "die schoenen Dinge im leben sind umsonst";
  printf("vorher : \t%s\n", string);
  // exec String Converting to Lowercase function
  stringToLower(string);
  printf("nacher : \t%s\n", string);
  return 0;
}
// Change the Input String to Lowercase chars
char * stringToLower(char *string) {
  int i;
  int len = strlen(string);
  // to make lowercase change A and Z to capital and change the - to +
  // to make uppercase change a and z to lowercase and the + to -
  for(i=0;i<len;i++) {
    if(string[i] >= 'A' && string[i] <= 'Z') {
      string[i] += 32;
    }
  }
  // return the string var
  return string;
}
