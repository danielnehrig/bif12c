#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#ifdef _WIN32
#include <conio.h>
#else
#define clrscr() printf("\e[1;1H\e[2J");
#endif
#define DEBUG

int main() {
    int figure,books,max=3,heights[255];
    int a,i,j,k=0;
    // Input
    printf("\nBooks on Shelf Programm\n\n");
    printf("\nAmount of Figures : ");
    scanf("%d", &figure);
    printf("\nAmount of Books : ");
    scanf("%d", &books);

    if(figure > books) {
        printf("\nUnable to Order Books becouse we are short on books");
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

#ifdef DEBUG
    for(int k=0;k<books;k++) {
        printf("\n\nDEBUG Sorted : %d ", heights[k]);
    }
#endif

    // Output
    for(i=1;i<figure+1;i++) {
        printf("\n\nAbschnit %d", i);
        printf("\n-----------");
        for(j=1;j<=books;j++) {
            printf("\nBook %d Hight : %d", j, heights[j-1]);
        }
    }

    return 0;
}
