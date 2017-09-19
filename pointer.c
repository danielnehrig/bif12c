#include <stdlib.h>
#include <stdio.h>
// Prototype
void math(float *sum1, float *sum2, float *sume);
float enter();
// Main Exec
int main() {
  float sum1, sum2, sume;
  sum1 = enter();
  sum2 = enter();
  math(&sum1,&sum2,&sume);
  printf("%0.2f", sume);
  return 0;
}

float enter() {
  float num;
  scanf("%f", &num);
  return num;
}

void math(float *sum1, float *sum2, float *sume) {
  *sume = *sum1 + *sum2;
}
