//#include "stdafx.h"
#include <stdlib.h>
#include <stdio.h>

char operation() {
  char operand;
  scanf("%c", &operand);
  return operand;
}
float eingabeZahl() {
  float eingabe;
  printf("\nEingabe Zahl: ");
  scanf("%f", &eingabe);
  return eingabe;
}
float multipliziere(char operand, float zahl1, float zahl2) {
  float math;
  switch(operand) {
    case '*': math = zahl1 * zahl2; break;
    case '+': math = zahl1 + zahl2; break;
    case '/': math = zahl1 / zahl2; break;
    case '-': math = zahl1 - zahl2; break;
  }
  return math;
}
void ausgabeErgebnis(float ergebnis) {
  printf("\nErgebnis: %f\n", ergebnis);
}

int main() {
  ausgabeErgebnis(multipliziere(operation(), eingabeZahl(), eingabeZahl()));
  return 0;
}
