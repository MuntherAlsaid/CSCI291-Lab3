#include <stdio.h>

#define SIZE 7 

void Transactions(int transactions[], int size, int initialBalance);
void printArray(int array[], int size);

int main() {
    int transactions[SIZE] = {200, -150, -500, 100, -50, -200, 300};
    int initialBalance = 1000;

    Transactions(transactions, SIZE, initialBalance);

    return 0;
}

void Transactions(int transactions[], int size, int initialBalance) {
    int balance = initialBalance;
    int unproccesed[SIZE]; 
    int unproccesedCount = 0;

    for (int i = 0; i < size; i++) {
        if (transactions[i] < 0 && -transactions[i] > balance) {
            printf("Invalid transaction: %d exceeds current balance. Transaction skipped.\n", transactions[i]);
            unproccesed[unproccesedCount++] = transactions[i];
            continue;
        }

        balance += transactions[i];

        if (balance < 0) {
            printf("Invalid transaction: %d leads to negative balance. Transaction skipped.\n", transactions[i]);
            balance -= transactions[i];
            unproccesed[unproccesedCount++] = transactions[i];
            continue;
        }

        if (balance == 0) {
            printf("Balance reached 0. No further transactions will be processed.\n");
            unproccesed[unproccesedCount++] = transactions[i];
            break;
        }

        

        printf("Transaction %d processed. Current balance: %d\n", transactions[i], balance);
    }

    printf("\nFinal balance: %d\n", balance);
    printf("Unprocessed transactions: ");
    printArray(unproccesed, unproccesedCount);
}

void printArray(int array[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d, ", array[i]);
    }
    printf("\n");
}
