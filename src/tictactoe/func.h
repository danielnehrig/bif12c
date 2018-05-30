#include <stdbool.h>

#ifndef LOGIC_H
#define LOGIC_H

// Validation Prototype
bool chooseValidation(char);
bool placeValidation(int ***,char *,int *,int *);
void place(int **,char *,int *,int *);
int winValidation(char **, int *, int, int);

// Logic
void fieldRender(char **, int);
void move(char **, char , int *, int *, int *, int *, int);
#endif
