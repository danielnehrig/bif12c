// Inc
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// Proto
char * stringReplace(char *search, char *replace, char *string);
// Exec Main
int main() {
  char string[100] = "Die schoenen Sachen im Leben sind umsonst";
  char search[] = "Sachen";
  char replace[] = "Dinge";

  printf("vorher: \t%s\n", string);
  stringReplace(search, replace, string);
  printf("nacher: \t%s\n", string);
  return 0;
}
// Replacing Char Function
char * stringReplace(char *search, char *replace, char *string) {
  char *tempString, *searchStart;
  int len=0;
  
  // Search inside a string for a search pattern which is "Sachen"
  searchStart = strstr(string, search);
  if(searchStart == NULL) {
    return NULL;
  }

  // Temporary save the string
  tempString = (char *) malloc(strlen(string) * sizeof(char));
  if(tempString == NULL) {
    return NULL;
  }

  // Copy string inside tempString
  strcpy(tempString, string);

  // Cut the string before the search "sachen" at this point it should look like "Die schoenen "
  len = searchStart - string;
  string[len] = '\0';

  // Append the Replace "Dinge" at this point it should look like " Die schoenen Dinge"
  strcat(string, replace);

  // count the length of search and multiply it into len
  len += strlen(search);
  // Append rest of String which is saved into a Temp pointer
  strcat(string, (char *)tempString+len);

  // Free
  free(tempString);

  // Return the new String
  return string;
}
