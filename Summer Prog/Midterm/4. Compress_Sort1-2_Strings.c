#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void Alphabetical_Order(char* a, char* b);
void sort_each_char(char* str);
void compressed_letters(char* str);

int main(void) {
    char fName[50], mName[50], Lname[50];
    
    printf("Input First Name: ");
    scanf("%[^\n]", fName);
    getchar();
    printf("Input Middle Name: ");
    scanf("%[^\n]", mName);
    getchar();
    printf("Input Last Name: ");
    scanf("%[^\n]", Lname);

    Alphabetical_Order(fName, mName);
    Alphabetical_Order(mName, Lname);
    Alphabetical_Order(Lname, fName); 

    printf("\nNames Sorted Alphabetically:\n");
    printf("1. %s\n", fName);
    printf("2. %s\n", mName);
    printf("3. %s\n", Lname);
    
    sort_each_char(fName);
    sort_each_char(mName);
    sort_each_char(Lname);
    
    printf("\nNames Sorted Alphabetically by Characters (Lowercase):\n");
    printf("1. %s\n", fName);
    printf("2. %s\n", mName);
    printf("3. %s\n", Lname);

    compressed_letters(fName);
    compressed_letters(mName);
    compressed_letters(Lname);

    printf("\nCompressed letters:\n");
    printf("1. %s\n", fName);
    printf("2. %s\n", mName);
    printf("3. %s\n", Lname);
}

void Alphabetical_Order(char* a, char* b) {
    if (strcmp(a, b) < 0) {
        char* temp = a;
        a = b;
        b = temp;

        char tempStr[strlen(a)];
        strcpy(tempStr, a);
        strcpy(a, b);
        strcpy(b, tempStr);
    }
}

void sort_each_char(char* str) {
    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        str[i] = tolower(str[i]); 
    }

    for (int i = 0; i < len; i++) {
        for (int j = i + 1; j < len; j++) {
            if (str[i] > str[j]) {
                char temp = str[i];
                str[i] = str[j];
                str[j] = temp;
            }
        }
    }
}

void compressed_letters(char* str) {
    int len = strlen(str);
    int k = 0, count = 1;

    for (int i = 0; i < len - 1; i++) {
        if (str[i] == str[i + 1]) {
            count++;
        } else {
            str[k++] = str[i]; // Place the character in the new position
            if (count > 1) {
                str[k++] = count + '0'; // Append the count
                count = 1; // Reset the count
            }
        }
    }

    // Handle the last character separately
    str[k++] = str[len - 1]; // Place the last character
    if (count > 1) {
        str[k++] = count + '0'; // Append the count if applicable
    }

    str[k] = '\0';
}
