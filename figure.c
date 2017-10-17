#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#ifdef _WIN32
#include <conio.h>
#else
#define clrscr() printf("\e[1;1H\e[2J");
#endif
//#define DEBUG

// Prototypes
void errorH(int);
void input(int *figure,int *books,int *heights);
void sortAsc(int arrlen,int *arr);
void cmrule(int arrlen,int *arr);
void output(int,int,int *arr);

// Main Exec
int main() {
    int figure,books,heights[255];
    int i;
    input(&figure,&books,heights);
    sortAsc(books,heights);
    cmrule(books,heights);
    output(figure,books,heights);
    return 0;
}


// Error handling Exit codes
void errorH(int n) {
    char yes;
    if ( n == 2 ) {
        printf("\nWant to restart the Program ? : ");
        scanf("%s", &yes);
        if (strcmp(&yes,"yes") == 0) {
            clrscr();
            main();
        } else {
            exit(-2);
        }
    }
    exit(-10);
}

// Sort a Array asc
void sortAsc(int arrlen, int *arr) {
    int i,j,a;
    for(i=0;i<arrlen-1;i++) {
        for(j=i+1;j<arrlen;j++) {
            if(arr[i] > arr[j]) {
                a = arr[i];
                arr[i] = arr[j];
                arr[j] = a;
            }
        }
    }
}

// apply 3cm rule to books in category
void cmrule(int arrlen,int *arr) {
    int i,max=3;
    char answer;
    for(i=0;i<arrlen;i++) {
        if((arr[i+1] - arr[i]) > max){
            char answer;
            printf("\nBook %d with hight %d is bigger then Book %d with height %d, hight difference is %d and max is %d",i+1,arr[i+1],i,arr[i], arr[i+1]-arr[i], max);
            printf("\nWant to Insert a different book ? : ");
            scanf("%s", &answer);
            if(strcmp(&answer, "yes") == 0) {
                printf("Input new book height : ");
                scanf("%d", &arr[i+1]);
            } else {
                exit(-3);
            }
        }
    }
}

// Output Of the categorys and the given books for the category
void output(int figure,int arrlen, int *arr) {
    clrscr();
    int i,j,o = 0;
    for(i=1;i<=figure+1;i++) {
        printf("\n\nAbschnit %d", i);
        printf("\n-----------");
        for(j=1;j<=arrlen/(figure+1);j++) {
            printf("\nBook Nr. %d\t Book Nr in Category.  %d\t Height : %d", o+1, j, arr[o]);
            o++;
        }
    }
    printf("\n");
}

// User Input and Validation
void input(int *figure,int *books, int *heights) {
    int i;
    printf("\nBooks on Shelf Programm\n\n");
    printf("\nAmount of Figures : ");
    scanf("%d", figure);
    printf("\nAmount of Books : ");
    scanf("%d", books);
    if(*books%( *figure+1 ) != 0 && *books<*figure+1) {
        printf("\nUneven amount of Books to Space between Figures");
        printf("\nUnable to Continue Book amount is lees then figure amount");
        errorH(2);
    } else if (*books%(*figure+1) != 0) {
        printf("\nUneven amount of Books to Space between Figures");
        errorH(2);
    } else {
        for(i=0;i<*books;i++) {
            clrscr();
            int height;
            printf("\nEnter Height of a Book Nr %d : ", i+1);
            scanf("%d", &height);
            heights[i] += height; 
        }
    }
}
