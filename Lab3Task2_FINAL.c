#include <stdio.h> 

#define SIZE 7   // Define constant SIZE as 7 for array length


// Function prototypes
void Transactions(int transactions[], int size, int initialBalance); // Function to process transactions
void printArray(int array[], int size); // Function to print an array

int main() {
    int transactions[SIZE] = {200, -150, -500, 100, -50, -200, 300}; // Array of transactions
    int initialBalance = 1000; // Starting balance

    Transactions(transactions, SIZE, initialBalance); // Call Transactions function

    return 0; // End of main function
}

void Transactions(int transactions[], int size, int initialBalance) {
    int balance = initialBalance; // Initialize balance with initial balance value
    int unproccesed[SIZE]; // Array to store unprocessed transactions
    int unproccesedCount = 0; // Counter for unprocessed transactions

    // Loop through each transaction
    for (int i = 0; i < size; i++) {
        if (transactions[i] < 0 && -transactions[i] > balance) {
            printf("Invalid transaction: %d exceeds current balance. Transaction skipped.\n", transactions[i]);
            unproccesed[unproccesedCount++] = transactions[i]; // Store unprocessed transaction
            continue; // Skip to the next transaction
        }

        balance += transactions[i]; // Add transaction amount to balance

        // Check if balance becomes negative after transaction
        if (balance < 0) {
            printf("Invalid transaction: %d leads to negative balance. Transaction skipped.\n", transactions[i]);
            balance -= transactions[i]; // Revert transaction from balance
            unproccesed[unproccesedCount++] = transactions[i]; // Store unprocessed transaction
            continue; // Skip to the next transaction
        }

        // Check if balance reaches exactly 0
        if (balance == 0) {
            printf("Balance reached 0. No further transactions will be processed.\n");
            unproccesed[unproccesedCount++] = transactions[i]; // Store last processed transaction
            break; // Stop further processing
        }

        // Print processed transaction and current balance
        printf("Transaction %d processed. Current balance: %d\n", transactions[i], balance);
    }

    printf("\nFinal balance: %d\n", balance); // Print final balance after all transactions
    printf("Unprocessed transactions: ");
    printArray(unproccesed, unproccesedCount); // Print all unprocessed transactions
}

// Function to print elements of an array
void printArray(int array[], int size) {
    for (int i = 0; i < size; i++) { // Loop through each element in the array
        printf("%d, ", array[i]); // Print each element followed by a comma
    }
    printf("\n"); // Print newline at the end of array output
}
