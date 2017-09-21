//#include "stdafx.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// Get Operator to do Calc
char operation() {
  char operand;
  printf("\nEnter a Operator (*;+;-;/) : ");
  scanf(" %c", &operand);
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
// Do more math
float mplus(float math) {
  char operand;
  float number1;
  // Loop Through until the operand is = and give result
  do {
    operand = operation();
    if(operand == '=') {
      return math;
    } else {
      number1 = enterNumber();
    }
    switch(operand) {
      case '*': math = math * number1; break;
      case '+': math = math  + number1; break;
      case '/': math = math / number1; break;
      case '-': math = math - number1; break;
    }
  }while(strcmp(&operand,"="));
  return math;
}
// Return the result
void returnValue(float result) {
  printf("\nErgebnis: %f\n", result);
}

// Main exec
int main() {
  float init, end;
  init = multiply(operation(), enterNumber(), enterNumber());
  end = mplus(init);
  returnValue(end);
  return 0;
}
