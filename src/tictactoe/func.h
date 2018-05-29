#include <stdbool.h>

// Validation
bool chooseValidation(char);
bool placeValidation(int ***,char *,int *,int *);
void place(int **,char *,int *,int *);
int winValidation(char fieldArr[3][3], int *);

// Logic
void fieldRender(char fieldArr[3][3]);
void move(char *, char , int *, int *, int *, int *);
