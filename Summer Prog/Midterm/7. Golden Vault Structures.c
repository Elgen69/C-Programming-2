#include <stdio.h>
#include <stdbool.h>

#define NUM_CHESTS 5

typedef struct {
    int Chest[NUM_CHESTS];
    float Gold[NUM_CHESTS];
} GoldenVault;

void initializeVault(GoldenVault *vault);
void getLuckyChests(GoldenVault *vault, int luckyChests[], int *count);
void inquire(GoldenVault *vault, int chestNumber);
void deposit(GoldenVault *vault, int chestNumber, float amount);
void withdraw(GoldenVault *vault, int chestNumber, float amount);

int main() {
    GoldenVault vault;
    initializeVault(&vault);
    
    // Get lucky chests
    int luckyChests[NUM_CHESTS];
    int count;
    getLuckyChests(&vault, luckyChests, &count);
    printf("Lucky Chests (with even gold contents):\n");
    for (int i = 0; i < count; i++) {
        printf("Chest %d\n", luckyChests[i] + 1); // +1 to convert to 1-based index
    }
    
    printf("\n");
    // Retrieve and inquire about specific chests based on the given examples
    int chestNumbersToInquire[] = {4, 3, 6, 12};
    for (int i = 0; i < sizeof(chestNumbersToInquire) / sizeof(chestNumbersToInquire[0]); i++) {
        inquire(&vault, chestNumbersToInquire[i]);
    }

    // Handle deposit transactions and display the updated balance
    printf("\nHandling Deposits:\n");
    deposit(&vault, 2, 12);
    deposit(&vault, 4, -5);   // Invalid
    deposit(&vault, 8, 300);  // Invalid
    deposit(&vault, 11, 17);  // Invalid

    // Handle withdrawal transactions and display the updated balance
    printf("\nHandling Withdrawals:\n");
    withdraw(&vault, 10, 300);  // Invalid
    withdraw(&vault, 2, 100);   // Invalid
    withdraw(&vault, 4, -7);    // Invalid
    withdraw(&vault, 3, 10);    // Invalid
    return 0;
}

// Function to initialize the GoldenVault
void initializeVault(GoldenVault *vault) {
    int evenNumbers[NUM_CHESTS] = {2, 4, 6, 8, 10};
    float goldBalances[NUM_CHESTS] = {10.50, 150.60, 160.00, 240.00, 555.00};
    for (int i = 0; i < NUM_CHESTS; i++) {
        vault->Chest[i] = evenNumbers[i];
        vault->Gold[i] = goldBalances[i];
    }
}

// Function to find and return the location (index) of chests with even Gold contents
void getLuckyChests(GoldenVault *vault, int luckyChests[], int *count) {
    *count = 0;
    for (int i = 0; i < NUM_CHESTS; i++) {
        if ((int)(vault->Gold[i]) % 2 == 0) {
            luckyChests[(*count)++] = i;
        }
    }
}

// Function to print the balance of a given Chest number
void inquire(GoldenVault *vault, int chestNumber) {
    if (chestNumber >= 1 && chestNumber <= NUM_CHESTS) {
        printf("Balance of Chest %d: %.2f\n", chestNumber, vault->Gold[chestNumber - 1]);
    } else {
        printf("Invalid Chest Number: %d\n", chestNumber);
    }
}

// Function to deposit a specified Gold amount into a given Chest
void deposit(GoldenVault *vault, int chestNumber, float amount) {
    if (chestNumber >= 1 && chestNumber <= NUM_CHESTS) {
        if (amount > 0) {
            vault->Gold[chestNumber - 1] += amount;
            printf("Deposited %.2f gold to Chest %d. New balance: %.2f\n", amount, chestNumber, vault->Gold[chestNumber - 1]);
        } else {
            printf("Invalid deposit amount: %.2f\n", amount);
        }
    } else {
        printf("Invalid Chest Number: %d\n", chestNumber);
    }
}

// Function to withdraw a specified amount of Gold from a given Chest
void withdraw(GoldenVault *vault, int chestNumber, float amount) {
    if (chestNumber >= 1 && chestNumber <= NUM_CHESTS) {
        if (amount > 0) {
            if (vault->Gold[chestNumber - 1] >= amount) {
                vault->Gold[chestNumber - 1] -= amount;
                printf("Withdrew %.2f gold from Chest %d. New balance: %.2f\n", amount, chestNumber, vault->Gold[chestNumber - 1]);
            } else {
                printf("Insufficient balance in Chest %d for withdrawal of %.2f gold\n", chestNumber, amount);
            }
        } else {
            printf("Invalid withdrawal amount: %.2f\n", amount);
        }
    } else {
        printf("Invalid Chest Number: %d\n", chestNumber);
    }
}
