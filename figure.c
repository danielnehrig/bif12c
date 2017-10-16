#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/types.h>
#ifdef _WIN32
#include <conio.h>
#else
#define clrscr() printf("\e[1;1H\e[2J");
#endif
//#define DEBUG
bool possible(int,int);
int error(int);

int main() {
    clrscr();
    int figure,books,max=3,heights[255];
    int a,i,j,k=0,o=1;
    // Input
    printf("\nBooks on Shelf Programm\n\n");
    printf("\nAmount of Figures : ");
    scanf("%d", &figure);
    printf("\nAmount of Books : ");
    scanf("%d", &books);
    if(books<figure) {
        printf("\nUnable to Continue Book amount is lees then figure amount");
        error(1);
    }
    if(books%figure != 0 ) {
        printf("\nUneven amount of Books to Space between Figures");
        error(2);
    }


    for(i=0;i<books;i++) {
        int height;
        printf("\nEnter Height of a certain Book : ");
        scanf("%d", &height);
        heights[i] += height; 
    }

    // Sort All Books Ascending
    for(i=0;i<books-1;i++) {
        for(j=i+1;j<books;j++) {
            if(heights[i] > heights[j]) {
                a = heights[i];
                heights[i] = heights[j];
                heights[j] = a;
            }
        }
    }
    // Make sure Every Section has a height range of 3cm
    for(i=0;i<books-1;i++) {
        for(j=0;j<books/(figure+1);j++) {
            if(heights[i] > heights[j]%(max+1-0)+0) {
                // do logic :)
            }
        }
    }

#ifdef DEBUG
    for(int k=0;k<books;k++) {
        printf("\n\nDEBUG Sorted : %d ", heights[k]);
    }
#endif

    // Output
    o = 0;
    clrscr();
    for(i=1;i<=figure+1;i++) {
        printf("\n\nAbschnit %d", i);
        printf("\n-----------");
        for(j=1;j<=books/(figure+1);j++) {
            printf("\nBook Nr. %d\t Book Nr in Category.  %d\t Height : %d", o+1, j, heights[o]);
            o++;
        }
    }
    printf("\n");

    return 0;
}

int error(int n) {
    char yes;
    if ( n == 2 ) {
        printf("\nWant to restart the Program ? : ");
        scanf("%s", &yes);
        if (strcmp(&yes,"yes") == 0) {
            main();
        } else {
            return 2;
        }
        return 10;
    }
    return 0;
}
