#include <stdio.h>
#include "headers/menu.h"

int showMenu()
{
  printf("==========================\n");
  printf("What would you like to do?\n");
  printf("1. Check Balance\n");
  printf("2. Deposit Money\n");
  printf("3. Withdraw Money\n");
  printf("4. View Transaction History\n");
  printf("5. Change Pin\n");
  printf("6. Exit\n");

  int choice;
  printf("Select Option: ");
  scanf("%d", &choice);

  return choice;
}