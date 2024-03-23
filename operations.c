#include <stdio.h>
#include <stdbool.h>
#include "headers/pin.h"
#include "headers/operations.h"

float accountBalance = 0.00;

void getCurrentBalance()
{
  char enteredPin[5];
  printf("Enter your 4 digit pin: ");
  scanf("%4s", enteredPin);

  if (verifyPin(enteredPin))
  {
    printf("Your current balance: %f\n", accountBalance);
  }
  else
  {
    printf("Incorrect pin\n");
  }
}

void depositAmount()
{
  float depositAmount;
  char enteredPin[5];
  printf("Enter your 4 digit pin: ");
  scanf("%4s", enteredPin);

  if (verifyPin(enteredPin))
  {
    printf("Enter deposit amount: ");
    scanf("%f", &depositAmount);

    if (depositAmount <= 0)
    {
      printf("Please add more than 0 amount\n");
    }
    else
    {
      accountBalance += depositAmount;
      printf("Balance added to your account!\n");
      printf("Your current balance: %f\n", accountBalance);
    }
  }
  else
  {
    printf("Incorrect pin\n");
  }
}

void withdrawAmount()
{
  float withdrawAmount;
  char enteredPin[5];
  printf("Enter your 4 digit pin: ");
  scanf("%4s", enteredPin);

  if (verifyPin(enteredPin))
  {
    printf("Enter amount to withdraw: ");
    scanf("%f", &withdrawAmount);

    if (accountBalance <= 0)
    {
      printf("Please withdraw more than 0 amount\n");
    }
    else if (withdrawAmount > accountBalance)
    {
      printf("Insufficient balance!\n");
    }
    else
    {
      accountBalance -= withdrawAmount;
      printf("Balance withdrawn from your account!\n");
      printf("Your current balance: %f\n", accountBalance);
    }
  }
  else
  {
    printf("Incorrect pin\n");
  }
}

void exitMenu()
{
  printf("Have a good day!\n");
  printf("Thanks for choosing our bank\n");
}
