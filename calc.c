//#include "stdafx.h"
#include <stdlib.h>
#include <stdio.h>

// Get Operator to do Calc
char operation() {
  char operand;
  printf("Enter a Operator (*;+;-;/) : ");
  scanf("%c", &operand);
  return operand;
}
// Function to enter a Number
float enterNumber() {
  float enter;
  printf("\nEnter Number: ");
  scanf("%f", &enter);
  return enter;
}
// Do the math
float multiply(char operand, float number1, float number2) {
  float math;
  // Check wich Operator was chosen
  switch(operand) {
    case '*': math = number1 * number2; break;
    case '+': math = number1 + number2; break;
    case '/': math = number1 / number2; break;
    case '-': math = number1 - number2; break;
  }
  return math;
}
// Return the result
void returnValue(float result) {
  printf("\nErgebnis: %f\n", result);
}

// Main exec
int main() {
  returnValue(multiply(operation(), enterNumber(), enterNumber()));
  return 0;
}
