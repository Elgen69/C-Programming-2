#include <stdio.h>
#include <stdlib.h>

void groupClosestPairs(int arr[], int n) {
    int i = 0, j = 0;
    for( i = 1; i <= arr[0];i+=2){
        for( j = i + 1; j <= arr[0];j+=2){
            if(arr[i] <= arr[j]){
                printf("(%d, %d)\n", arr[i], arr[j]);
                break;
            }
        }
        if(j > n){
                printf("(%d, -)\n", arr[i]);
                break;
            }
    }
}
// 7 14 19 23 29 31
//1 3 4 5 8 9 10 -
int main() {
    int n;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    if(n <= 0){
        exit(0);
    }
    int arr[n];
    
    printf("Enter %d elements: \n", n);
    for(int i = 1; i <= n; i++){
        scanf("%d", &arr[i]);
    }
    for(int i = 1; i <= n - 1; i++){
        for(int j = i + 1; j <= n; j++){
            if(arr[i] > arr[j]){
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            }
        }
    }
    arr[0] = n;
    
    printf("Closest pairs:\n");
    groupClosestPairs(arr,n);

    return 0;
}
