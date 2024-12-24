#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ACCOUNTS 100

typedef struct {
    char name[50];
    int accountNumber;
    float balance;
} Account;

void createAccount(Account *accounts, int *count);
void deposit(Account *accounts, int count);
void withdraw(Account *accounts, int count);
void displayAccounts(Account *accounts, int count);

int main() {
    Account accounts[MAX_ACCOUNTS];
    int count = 0;
    int choice;

    while (1) {
        printf("\n1. Create Account\n2. Deposit\n3. Withdraw\n4. Display Accounts\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: createAccount(accounts, &count); break;
            case 2: deposit(accounts, count); break;
            case 3: withdraw(accounts, count); break;
            case 4: displayAccounts(accounts, count); break;
            case 5: exit(0);
            default: printf("Invalid choice.\n");
        }
    }
}

void createAccount(Account *accounts, int *count) {
    if (*count >= MAX_ACCOUNTS) {
        printf("Cannot add more accounts.\n");
        return;
    }
    printf("Enter name: ");
    scanf(" %[^\n]", accounts[*count].name);
    printf("Enter account number: ");
    scanf("%d", &accounts[*count].accountNumber);
    accounts[*count].balance = 0;
    (*count)++;
}

void deposit(Account *accounts, int count) {
    int accountNumber;
    float amount;
    printf("Enter account number: ");
    scanf("%d", &accountNumber);
    for (int i = 0; i < count; i++) {
        if (accounts[i].accountNumber == accountNumber) {
            printf("Enter amount to deposit: ");
            scanf("%f", &amount);
            accounts[i].balance += amount;
            printf("Deposit successful. New balance: %.2f\n", accounts[i].balance);
            return;
        }
    }
    printf("Account not found.\n");
}

void withdraw(Account *accounts, int count) {
    int accountNumber;
    float amount;
    printf("Enter account number: ");
    scanf("%d", &accountNumber);
    for (int i = 0; i < count; i++) {
        if (accounts[i].accountNumber == accountNumber) {
            printf("Enter amount to withdraw: ");
            scanf("%f", &amount);
            if (amount > accounts[i].balance) {
                printf("Insufficient balance.\n");
            } else {
                accounts[i].balance -= amount;
                printf("Withdrawal successful. New balance: %.2f\n", accounts[i].balance);
            }
            return;
        }
    }
    printf("Account not found.\n");
}

void displayAccounts(Account *accounts, int count) {
    for (int i = 0; i < count; i++) {
        printf("Name: %s, Account Number: %d, Balance: %.2f\n", accounts[i].name, accounts[i].accountNumber, accounts[i].balance);
    }
}
