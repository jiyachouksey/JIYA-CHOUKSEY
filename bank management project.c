#include <stdio.h>
#include <string.h>

#define MAX_ACCOUNTS 10

typedef struct {
    int account_number;
    char account_holder[50];
    float balance;
} Account;

Account accounts[MAX_ACCOUNTS];
int num_accounts = 0;

void create_account() {
    if (num_accounts < MAX_ACCOUNTS) {
        printf("Enter account number: ");
        scanf("%d", &accounts[num_accounts].account_number);
        printf("Enter account holder's name: ");
        scanf("%s", accounts[num_accounts].account_holder);
        accounts[num_accounts].balance = 0.0;
        num_accounts++;
        printf("Account created successfully!\n");
    } else {
        printf("Maximum number of accounts reached!\n");
    }
}

void deposit_money() {
    int account_number;
    float amount;
    printf("Enter account number: ");
    scanf("%d", &account_number);
    for (int i = 0; i < num_accounts; i++) {
        if (accounts[i].account_number == account_number) {
            printf("Enter amount to deposit: ");
            scanf("%f", &amount);
            accounts[i].balance += amount;
            printf("Deposit successful!\n");
            return;
        }
    }
    printf("Account not found!\n");
}

void withdraw_money() {
    int account_number;
    float amount;
    printf("Enter account number: ");
    scanf("%d", &account_number);
    for (int i = 0; i < num_accounts; i++) {
        if (accounts[i].account_number == account_number) {
            printf("Enter amount to withdraw: ");
            scanf("%f", &amount);
            if (accounts[i].balance >= amount) {
                accounts[i].balance -= amount;
                printf("Withdrawal successful!\n");
            } else {
                printf("Insufficient balance!\n");
            }
            return;
        }
    }
    printf("Account not found!\n");
}

void check_balance() {
    int account_number;
    printf("Enter account number: ");
    scanf("%d", &account_number);
    for (int i = 0; i < num_accounts; i++) {
        if (accounts[i].account_number == account_number) {
            printf("Account balance: %.2f\n", accounts[i].balance);
            return;
        }
    }
    printf("Account not found!\n");
}

void display_accounts() {
    printf("Account Information:\n");
    for (int i = 0; i < num_accounts; i++) {
        printf("Account Number: %d, Account Holder: %s, Balance: %.2f\n",
               accounts[i].account_number, accounts[i].account_holder, accounts[i].balance);
    }
}

int main() {
    int choice;
    while (1) {
        printf("Bank Management System\n");
        printf("1. Create Account\n");
        printf("2. Deposit Money\n");
        printf("3. Withdraw Money\n");
        printf("4. Check Balance\n");
        printf("5. Display Accounts\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                create_account();
                break;
            case 2:
                deposit_money();
                break;
            case 3:
                withdraw_money();
                break;
            case 4:
                check_balance();
                break;
            case 5:
                display_accounts();
                break;
            case 6:
                return 0;
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}