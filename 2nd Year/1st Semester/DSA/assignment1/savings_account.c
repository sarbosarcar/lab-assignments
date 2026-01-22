#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MIN_BALANCE 1000
#define MAX_BALANCE 100000
#define INTEREST_RATE 0.04

 struct SavingsAccount{
    char name[50];
    int acc;
    double balance;
};


void createAccount(struct SavingsAccount *account, int acc, char *name, double initial) {
    account->acc = acc;
    strcpy(account->name, name);
    account->balance = initial;
}


void deposit(struct SavingsAccount *account, double amount) {
    if (amount > 0) {
        account->balance += amount;
    }
}


void withdraw(struct SavingsAccount *account, double amount) {
    if (amount > 0 && account->balance - amount >= MIN_BALANCE) {
        account->balance -= amount;
       
    }
}



void calculateInterest(struct SavingsAccount *account) {
    double interest = account->balance * INTEREST_RATE;
    account->balance += interest;
}


double calculateTotalInterest(struct SavingsAccount accounts[], int n) {
    double totalint = 0.0; int i;
    for (i = 0; i < n; i++) {
        totalint += accounts[i].balance * INTEREST_RATE;
    }
    return totalint;
}

int main() {
    int n, i;
    printf("Enter number of accounts: ");
    scanf("%d", &n);
    struct SavingsAccount accounts[n];
    int accountNumber = 1;
    double totalInterest = 0.0;
    
    
    srand(time(NULL));
    getchar();
    
    
    for (i = 0; i < n; i++) {
        char name[50];
        printf("Enter name of account holder %d: ", i+1);
        fgets(name, 50, stdin);
        double initialBalance = (rand() % (MAX_BALANCE - MIN_BALANCE + 1)) + MIN_BALANCE;
        createAccount(&accounts[i], accountNumber++, name, initialBalance);
    }
    
    
    for (i = 0; i < n; i++) {
        calculateInterest(&accounts[i]);
    }
    
    
    totalInterest = calculateTotalInterest(accounts, n);
    
    
    for (i = 0; i < n; i++) { 
        printf("Account Number: %d\n", accounts[i].acc);
        printf("Name: %s\n", accounts[i].name);
        printf("Balance: %.2f\n\n", accounts[i].balance);
    }
    
    printf("Total interest paid to all accounts in one year: %.2f\n", totalInterest);

    return 0;
}








