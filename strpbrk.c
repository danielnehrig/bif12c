#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main() {
  char string[] = "aa2aa5aa6aa";
  char spanset[] = "1234567890";

  char *ptr = string;
  int i, alpha, dig, oth;
  alpha = dig = oth = i = 0;


  while(string[i]!='\0') {
    if(
        ( string[i]>='a' && string[i]<='z' ) || (string[i]>='A' && string[i]<='Z') 
      )
        {
          alpha++;
        } else if (string[i]>='0' && string[i]<='9')
        {
          dig++;
        } else {
          oth++;
        }
    i++;
  }
  printf("%i", dig);
}
