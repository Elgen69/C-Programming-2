#include <stdio.h>
#include <stdlib.h>

void arrayCleaning(int arr[], int count);
void display(int arr[], int cleanedCount);

int main() {
    int arr[100];
    int arrCount = 0;

    /* TODO: Ask user input for how many items in array */
    printf("Input how many items in the array: ");
    scanf("%d", &arrCount);

    /* TODO: Populate Array */
    printf("Input Array Values: ");
    for (int i = 0; i < arrCount; i++) {
        scanf("%d", &arr[i]);
    }

    arrayCleaning(arr, arrCount);

    return 0;
}

void arrayCleaning(int arr[], int count) {
    int cleanedArr[count];  // Temporary array to hold cleaned data
    int cleanedCount = 0;   // Counter for non-corrupted data in cleanedArr
    int i = 0;

    while (i < count) {
        if (arr[i] == -1) {
            // Skip over the first -1 in a pair
            i++;

            // Skip over the data until the next -1 in the pair
            while (i < count && arr[i] != -1) {
                i++;
            }

            // Skip over the second -1 in the pair
            i++;
        } else {
            cleanedArr[cleanedCount++] = arr[i++];
        }
    }

    if (cleanedCount == 0) {
        printf("\nOh no Data is fully corrupted and cannot be recovered!");
    } else {
        printf("Data has been recovered!\n");
        display(cleanedArr, cleanedCount);
    }
}

void display(int arr[], int cleanedCount) {
    printf("Cleaned Data: ");
    for (int i = 0; i < cleanedCount; i++) {
        printf("%d  ", arr[i]);
    }
    printf("\n");
}
