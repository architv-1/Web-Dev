#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct
{
    int accountNumber;
    char name[100];
    float balance;
} Account;

void createaccount(Account accounts[], int *numAccounts)
{
    Account newaccount;
    printf("Enter Account Number: ");
    scanf("%d", &newaccount.accountNumber);
    printf("Enter Name: ");
    scanf("%c", &newaccount.name);
    newaccount.balance = 0;

    accounts[*numAccounts] = newaccount;
    (*numAccounts)++;
    printf("Account Created Succesfully!\n");
}

void deposite(Account accounts[], int numAccounts)
{
    int accountnumber;
    float amount;
    printf("Enter Account Number: ");
    scanf("%d", &accountnumber);

    for (int i = 0; i <= numAccounts; i++)
    {
        if (accounts[i].accountNumber == accountnumber)
        {
            printf("Enter Amount to Deposite: ");
            scanf("%d", &amount);
            accounts[i].balance += amount;
            printf("Amount Deposited Succesfully!\n");
            return;
        }
    }
    printf("Account Not Found.\n");
}

void withdraw(Account accounts[], int numAccounts)
{
    int accountnumber;
    float amount;
    printf("Enter Account Number: ");
    scanf("%d", &accountnumber);

    for (int i = 0; i <= numAccounts; i++)
    {
        if (accounts[i].accountNumber == accountnumber)
        {
            printf("Enter Amount to Withdraw: ");
            scanf("%d", &amount);
            if (accounts[i].balance >= amount)
            {
                accounts[i].balance -= amount;
                printf("Amount Withdraw Succesfully!\n");
            }
            else
            {
                printf("Insufficient Balance.\n");
            }
            return;
        }
    }
    printf("Account Not Found.\n");
}

void checkbalance(Account accounts[], int numAccounts)
{
    int accountnumber;
    printf("Enter Account Number ");
    scanf("%d", &accountnumber);

    for (int i = 0; i < numAccounts; i++)
    {
        if (accounts[i].accountNumber == accountnumber)
        {
            printf("Balance is: %.3f\n", accounts[i].balance);
            return;
        }
    }
    printf("Account Not Found!\n");
}

int main()
{
    Account accounts[100];
    int numAccounts;
    int ch;

    while (1)
    {
        printf("\nBANK MANAGEMENT SYSTEM\n");
        printf("1. Create Account\n");
        printf("2. Deposite\n");
        printf("3. Withdraw Amount\n");
        printf("4. Check Balance\n");
        printf("5. Exit\n");
        printf("Enter Your Choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            createaccount(accounts, &numAccounts);
            break;
        case 2:
            deposite(accounts, &numAccounts);
            break;
        case 3:
            withdraw(accounts, &numAccounts);
            break;
        case 4:
            checkbalance(accounts, &numAccounts);
            break;
        case 5:
            exit(0);
            break;

        default:
            printf("Invalid Choice. Please Try Again!\n");
        }
    }

    return 0;
}
