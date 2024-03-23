# C Bank

C Bank is a simple banking system implemented in C language. It allows users to perform basic banking operations such as checking balance, depositing money, withdrawing money, and changing PIN.

## Features

- **Set PIN**: Users can set their 4-digit PIN when they first open the application.
- **Check Balance**: Users can check their current account balance.
- **Deposit Money**: Users can deposit money into their account.
- **Withdraw Money**: Users can withdraw money from their account.
- **Change PIN**: Users can change their PIN for security purposes.

## How to Run

```sh
gcc -o bank main.c menu.c operations.c pin.c && ./bank
```

## Usage

- When you first run the application, you will be prompted to set your PIN.
- After setting the PIN, you can use the main menu to perform banking operations.
- Follow the on-screen instructions to navigate through the menu and perform actions.
