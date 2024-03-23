#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "headers/pin.h"

char pin[5] = "";

bool isPinSet()
{
  return strlen(pin) > 0;
}

void setPin()
{
  printf("Please set your 4 digit pin to continue\n");
  printf("Enter pin: ");
  scanf("%4s", pin);
}

void changePin()
{
  char currentPin[5];
  printf("Enter current pin: ");
  scanf("%4s", currentPin);

  if (verifyPin(currentPin))
  {
    printf("Enter new 4 digit pin: ");
    scanf("%4s", pin);
    printf("Pin updated successfully\n");
  }
  else
  {
    printf("Pin mismatched\n");
  }
}

bool verifyPin(char enteredPin[])
{
  return strcmp(enteredPin, pin) == 0;
}
