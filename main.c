#include <stdio.h>
#include <stdbool.h>
#include "headers/pin.h"
#include "headers/menu.h"
#include "headers/operations.h"

int main()
{
  printf("Welcome to C Bank!\n");
  printf("Call us at +000 000 000\n");

  if (!isPinSet())
  {
    setPin();
  }

  while (true)
  {
    int choice = showMenu();

    switch (choice)
    {
    case 1:
      getCurrentBalance();
      break;
    case 2:
      depositAmount();
      break;
    case 3:
      withdrawAmount();
      break;
    case 4:
      getTransactionHistory();
      break;
    case 5:
      changePin();
      return 0;
    case 6:
      exitMenu();
      return 0;
    default:
      printf("Wrong option selected\n");
      break;
    }
  }

  return 0;
}
