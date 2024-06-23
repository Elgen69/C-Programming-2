/*split the array to odd or even, after splitting it, 
if they have the same size, add the contents of each index 
of each array, if not same size return an integer 0 to main , 
print 0 . if able to add print the array with the sum of each index */

#include <stdio.h>

// Function prototypes
void disp(int arr[], int sum, int s);
int separate(int arr[], int even_count, int odd_count, int s);

int main(void) {
    int s = 8;
    int arr[s+1]; //Extra space for sum in advance 
    int sum = 0;

  
    int predefined_arr[] = {1, 2, 3, 4, 5, 6, 7, 8}; 

    for (int i = 0; i < s; i++) {
        arr[i] = predefined_arr[i];
        sum += arr[i];
    }
    arr[s] = sum; // Add sum as the last element of the array, using s

    disp(arr, sum, s);

    return 0;
}

void disp(int arr[], int sum, int s) {
    int even_count = 0, odd_count = 0;

    printf("Original array: ");
    for (int i = 0; i <= s; i++) { 
        printf("%i ", arr[i]);
    }

    printf("\nEven: ");
    for (int i = 0; i <= s; i++) { 
        if (arr[i] % 2 == 0) {
            printf("%i ", arr[i]);
            even_count++;
        }
    }

    printf("\nOdd: ");
    for (int i = 0; i <= s; i++) { 
        if (arr[i] % 2 != 0) {
            printf("%i ", arr[i]);
            odd_count++;
        }
    }
    odd_count++; //extra code to make logic later work 
    
    printf("\n");

    int result = separate(arr, even_count, odd_count, s);

    if (result == 0) {
        printf("0, not same size counters\n");
    }
}

int separate(int arr[], int even_count, int odd_count, int s) {
    if (even_count != odd_count) {
        return 0; // Return 0 if even and odd counts are not the same
    }
    
    int even[even_count];
    int odd[odd_count];
    int e_idx = 0, o_idx = 0;
    
    //Code to test an add something to the odd array to make size for odd and even count the same thus executing the code
    if (odd_count > 0) { 
        odd[odd_count - 1] = 9; 
    }
    
    for (int i = 0; i <= s; i++) {
        if (arr[i] % 2 == 0) {
            even[e_idx++] = arr[i];
        } else {
            odd[o_idx++] = arr[i];
        }
    }

    printf("\nEven only array: ");
    for (int i = 0; i < even_count; i++) {
        printf("%i ", even[i]);
    }
    printf("\n");

    printf("Odd only array: ");
    for (int i = 0; i < odd_count; i++) {
        printf("%i ", odd[i]);
    }
    printf("\n");

    printf("\nSum of corresponding elements per index in both arrays: \n");
    for (int i = 0; i < even_count; i++) {
        printf("%i ", even[i] + odd[i]);
    }
    printf("\n");

    return 1;
}