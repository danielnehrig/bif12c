// Includes
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
// Prototypes
int selectionbottle();
int insertAmount();
float getPrice(int bottle);
float pay(float wrap);
int moneyCheck(float money);
void givebottle(int bottle, int amount);
// Main Exec
int main() {

  printf("Getraenke Automat v0.4\n\n");

  int amount, bottle;
  float wrap, price;

  bottle = selectionbottle();
  price = getPrice(bottle);
  amount = insertAmount();
  wrap = price * amount;
  pay(wrap);
  givebottle(bottle, amount);
  printf("\n\nVielen Dank, bitte entnehmen sie ihre Getraenke.\n");

  return 1;
}
// Order Selection
int selectionbottle() {
  int bottle;
  printf("Waehlen sie ihr getreank aus:\n");
  printf("1) Wasser (0,50 Euro)\n");
  printf("2) Limonade (1,50 Euro)\n");
  printf("3) Bier (2,50 Euro)\n\n");
  printf("Geben sie 1, 2 oder 3 ein: ");
  scanf("%d", &bottle);
  return bottle;
}
// Insert Amount
int insertAmount() {
  int amount;
  printf("\nGeben sie die gewuenschte Menge ein: ");
  scanf("%d", &amount);
  return amount;
}
// Get Price
float getPrice(int bottle) {
  float price=0;
  float water=0.5,limo=1,beer=2.5;
  switch(bottle) {
    case 1: price = water; break;
    case 2: price = limo; break;
    case 3: price = beer; break;
  }
  return price;
}
// Payment
float pay(float wrap) {
  printf("--- Bezahlvorgang ---\n\n");
  printf("\nBezahlvorgang abbrechen mit 0\n");
  float money, paid=0;
  do {
    printf("\nEs fehlen noch %.2f Euro.", wrap);
    printf("\nBitte werden sie ein Geldstueck ein: ");
    scanf("%f", &money);
    if(money == 0) {
      break;
    }
    if(moneyCheck(money)) {
    wrap -= money;
    } else {
      printf("\nIhr Geldstueck ist ungueltig.");
    }
  } while(wrap > 0);

  return paid;
}
// Eject amount of orderd bottles
void givebottle(int bottle, int amount) {
  printf("\n--- Getaenkeausgabe ---\n");
  int i;
  for(i=0; i < amount; i++) {
    printf("\nFlasche %d von %d der Sorte %d wurde ausgegeben", i+1, amount, bottle);
  }
}
// Money Validation
int moneyCheck(float money) {
  int cent = money * 100;
  switch(cent) {
    case 5: return 1;
    case 10: return 1;
    case 20: return 1;
    case 50: return 1;
    case 100: return 1;
    case 200: return 1;
    default: return 0;
  }
}
