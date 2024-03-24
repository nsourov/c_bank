#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>
#include "headers/pin.h"
#include "headers/operations.h"

#define MAX_TRANSACTION_LIMIT 100
#define MAX_STRING_LENGTH 256

float accountBalance = 0.00;
char transactionHistory[MAX_TRANSACTION_LIMIT][MAX_STRING_LENGTH];
int transactionHistorySize = 0;

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
      char message[MAX_STRING_LENGTH];
      sprintf(message, "Deposit amount $%f", depositAmount);
      addToTransactionHistory(message);
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
      char message[MAX_STRING_LENGTH];
      sprintf(message, "Withdraw amount $%f", withdrawAmount);
      addToTransactionHistory(message);
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

void addToTransactionHistory(const char *message)
{
  time_t now;
  time(&now);
  strftime(transactionHistory[transactionHistorySize], MAX_STRING_LENGTH, "Date: %a %b %d %Y %H:%M:%S %Z\n  Message: ", localtime(&now));
  strncat(transactionHistory[transactionHistorySize], message, MAX_STRING_LENGTH - strlen(transactionHistory[transactionHistorySize]) - 1);
  transactionHistorySize++;
}

void getTransactionHistory()
{
  if (transactionHistorySize < 1)
  {
    printf("No transaction history found\n");
  }
  else
  {
    printf("============TRANSACTION HISTORY============\n");
    int i;
    for (i = 0; i < transactionHistorySize; i++)
    {
      printf("- %s\n", transactionHistory[i]);
    }
  }
}