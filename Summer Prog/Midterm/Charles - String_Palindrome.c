#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

/* 3.) Given a string input determine if the given string is a palindrome or not. 

A palindrome is a word where if read backwards produces the same word 

Examples of Palindromes:
Mom
Dad
Pop
Nurses Run
Radar
Rotator */

bool palindrome (char* str) {
    int len = strlen(str), count = 0;
    char* newStr = (char*) malloc (sizeof(char) * len + 1);

    int j = len - 1;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] != str[j--]) {
            return true;
        }
    }
}

void display (int* arr) {
    printf("Output: ");
    for (int i = 1; i < 10; i++) {
        printf("%d ",arr[i]);
    }
}

int main () {
    char str[50];

    printf("Input: ");
    scanf("%s", str);
    
    if (palindrome(str)) {
        printf("It is not a palindrome.");
    } else {
        printf("It is a palindrome.");
    }
}
