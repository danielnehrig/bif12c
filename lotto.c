#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <stdbool.h>
#include <ctype.h>

#ifdef _WIN32
#include <conio.h>
#else
#include <stdio.h>
#define clrscr() printf("\e[1;1H\e[2J")
#endif

void swap (int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

void bubbleSort (int arrlen, int *arr) {
  for(int i=0;i<arrlen;i++) {
    for(int k=i+1;k<arrlen;k++) {
      if(arr[i] > arr[k]) {
        swap(&arr[i],&arr[k]);
      }
    }
  }
}

void print (int *arr,int msg) {
  if(msg == 1) {
    printf("\n\nPrinting Automated Drawn Balls");
  } else {
    printf("\n\nPrinting Manual Drawn Numbers");
  }
  for(int i=0;i<=5;i++) {
    printf("\nNumber %d : %d", i+1, arr[i]);
  }
}

void drawnumbers (int *lottonumbers) {
  srand(time(0));
  printf("\nStarting Drawing the Lotto Numbers");
  for(int i=0;i<=5;i++) {
    lottonumbers[i] = 1 + (rand() % (49 - 1 + 1));
  }
  for(int i=0;i<=5;i++) {
    for(int k=0;k<i;k++) {
      if(lottonumbers[k] == lottonumbers[i]) {
        drawnumbers(lottonumbers);
      }
    }
  }
  bubbleSort(6,lottonumbers);
}

int compare (int *arr,int *arr2) {
  int correct = 0;
  for(int i=0;i<=5;i++) {
    for(int k=0;k<=5;k++) {
      if(arr[i] == arr2[k]) {
        correct++;
      }
    }
  }
  return correct;
}

bool numberValidation (int *number,int i) {
  if(number[i] > 49 || number[i] == 0) {
    printf("\nNumber above 49 or 0 retry");
    return true;
  } else if (i >= 1) {
    for(int k=0;k<i;k++) {
      if(number[k] == number[i]) {
        printf("\nFound same number in list retry");
        return true;
      }
    }
  }
  return false;
}

void self () {
  clrscr();
  int lottonumbers[6];
  int numbers[6];
  printf("\nStarting Self");
  for(int i=0;i<=5;i++) {
    do {
      printf("\nEnter a Number between 1-49 - %d: ", i+1);
      scanf(" %d", &numbers[i]);
    } while (numberValidation(numbers,i));
  }
  bubbleSort(6,numbers);
  drawnumbers(lottonumbers);
  print(numbers,2);
  print(lottonumbers,1);
  int correct = compare(numbers,lottonumbers);
  printf("\n\nYou have %d correct number(s)", correct);
  if(correct == 6) {
    printf("\n\nYou Won !!!");
  }
}

void simulation () {
  clrscr();
  srand(time(0));
  int players[1000][6];
  int lottonumbers[6];
  int correctAll = 0;
  int correct = 0;
  printf("\nStarting Simulation");
  for(int i=0;i<=999;i++) {
    for(int k=0;k<=5;k++) {
      players[i][k] = 1 + (rand() % (49 - 1 + 1));
    }
  }
  drawnumbers(lottonumbers);
  print(lottonumbers,1);
  for(int i=0;i<=999;i++) {
    for(int k=0;k<=5;k++) {
      for(int l=0;l<=5;l++) {
        if(players[i][k] == lottonumbers[l]) {
          correct++;
        }
      }
    }
    if(correct == 6) {
      printf("\n\nPlayer %d Won !!!", i);
      for(int o=0;o<=5;o++) {
        printf(" ; number %d : %d", o+1, players[i][o]);
      }
    } else {
      correctAll += correct;
      correct = 0;
    }
  }
  printf("\n\n%d correct numbers overall", correctAll);
}

int main() {
  char auswahl;
  clrscr();
  printf("\nLotto Game v1");
  printf("\nPlay by yourself (x) start Simulation (s) : ");
  scanf("%c", &auswahl);
  switch (auswahl) {
    case 'x' : self(); break;
    case 's' : simulation(); break;
  }
  printf("\n");
  printf("End");
  return 0;
}
