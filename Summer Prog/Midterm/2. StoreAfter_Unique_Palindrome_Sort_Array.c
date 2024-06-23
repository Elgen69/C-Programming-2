/* request 10 inputs specifically integers, only 0-5 
 On the first occurence of 3, you create another array only containing values 3 below and put them in on it - Malloc new array as well  */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void disp2(int* arr2, int size);
void unique_element(int* arr2, int size);
void make_palindrome(int* arr2, int size);
void sort(int* arr2, int size);

int main(void) {
    int* arr = malloc(10 * sizeof(int)); 
    int* arr2 = NULL;
    int s = 10, arr2_size = 0;

    printf("Input 10 elements (integers from 0 to 5): ");
    for (int i = 0; i < s; i++) {
        scanf("%d", &*(arr+i));
    }
    for (int i = 0; i < s; i++) {
        if (arr2 != NULL && arr[i] <= 3) {
            arr2[arr2_size] = arr[i];
            arr2_size++;
        }
        if (arr[i] == 3 && arr2 == NULL) {
            arr2 = malloc((s - i) * sizeof(int));  
            arr2[arr2_size] = arr[i]; 
            arr2_size++;
        }
    }
    disp2(arr2, arr2_size);
    unique_element(arr2, arr2_size);
}
void disp2(int* arr2, int size) {
    if (arr2 == NULL) {
        printf("Array 2 is empty.\n");
        return;
    }

    printf("First Occurences of 3 and After: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", *(arr2 + i));
    }
    printf("\n");
}

void unique_element(int* arr2, int arr2_size) {
    int count = 0;
    int* temp = malloc(arr2_size * sizeof(int));
    int found;

    printf("Unique elements: ");
    for (int i = 0; i < arr2_size; i++) {
        found = 0;
        for (int j = 0; j < count; j++) {
            if (*(arr2 + i) == *(temp + j)) {
                found = 1;
                break;
            }
        }
        if (!found) {
            *(temp + count) = *(arr2 + i);
            count++;
        }
    }

    arr2 = realloc(arr2, count * sizeof(int));
    for (int i = 0; i < count; i++) {
        *(arr2 + i) = *(temp + i);
        printf("%d ", *(arr2 + i));
    }

    free(temp);
    make_palindrome(arr2, count);
    printf("\n");
}

void make_palindrome(int* arr2, int size) {
    if (size == 1) {
        printf("\nPalindrome elements: %d\n", *(arr2+0));
        sort(arr2, size);
        return;
    }
    int new_size = 2 * size;
    int* reversedArr = malloc(size * sizeof(int));

    for (int i = 0; i < size; i++) {
        *(reversedArr + i) = *(arr2 + size - i - 1);
    }

    arr2 = realloc(arr2, new_size * sizeof(int));

    for (int i = 0; i < size; i++) {
        *(arr2 + size + i) = *(reversedArr + i);
    }

    printf("\nPalindrome elements: ");
    for (int i = 0; i < new_size; i++) {
        printf("%d ", *(arr2 + i));
    }

    sort(arr2, new_size);
    free(reversedArr);
}

void sort(int* arr2, int size) {
    int i, j;
    bool swapped;
    for (i = 0; i < size - 1; i++) {
        swapped = false;
        for (j = 0; j < size - i - 1; j++) {
            if (*(arr2 + j) > *(arr2 + j + 1)) {
                int temp = *(arr2 + j);
                *(arr2 + j) = *(arr2 + j + 1);
                *(arr2 + j + 1) = temp;
                swapped = true;
            }
        }
        if (swapped == false)
            break;
    }
    printf("\nSorted array: ");
    for (i = 0; i < size; i++) {
        printf("%d ", *(arr2 + i));
    }
    printf("\n");
}


/* For user input
#include <stdio.h>
#include <string.h>

void disp(int[], int, int);
int separate(int arr[], int even_cnt, int odd_cnt, int size);


int main(void){
    int sum, s = 8;
    int arr[s];
    printf("Input 8 elements: ");
    for(int i = 0; i < 8; i++){
        scanf("%i", &*(arr+i));
        sum += *(arr+i);
    }
    // *(arr+8) = sum;
    disp(arr, sum, s);
    
    
}

void disp(int arr[], int sum, int s){
    int even_count = 0, odd_count = 0;
    
    printf("Original array: ");
    for(int i = 0; i < s; i++){ // Corrected loop condition to match array size
        printf("%d ", arr[i]);
        if((arr[i] % 2) == 0){
            even_count++;
        } else {
            odd_count++;
        }
    }
    printf("\n");

    // Separate arrays and display them
    int even[even_count], odd[odd_count];
    int j = 0, k = 0;
    for(int i = 0; i < s; i++){
        if((arr[i] % 2) == 0){
            even[j++] = arr[i]; // Using array indexing
        } else {
            odd[k++] = arr[i]; // Using array indexing
        }
    }

    printf("Even only array: ");
    for(int i = 0; i < even_count; i++){
        printf("%d ", even[i]); // Using array indexing
    }
    printf("\nOdd only array: ");
    for(int i = 0; i < odd_count; i++){
        printf("%d ", odd[i]); // Using array indexing
    }
    
    // Check if sizes are equal and print sums
    if(even_count == odd_count){
        for(int i = 0; i < even_count; i++){
            printf("%d ", even[i] + odd[i]); 
        }
    } else {
        printf("Sizes are not equal.\n"); 
    }
}*/