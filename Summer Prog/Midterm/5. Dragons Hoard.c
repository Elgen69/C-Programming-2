#include <stdio.h>
#include <ctype.h>
#include <string.h>

// Function prototypes
void make_dragon_name(char str1[], char str2[], char str3[], char str4[], char str5[], char str6[], char result[]);
int count_words(char *strings[], int n);
int count_letter_r(char *strings[], int n);
int count_short_words(char *strings[], int n);
int count_vowels(char *strings[], int n);
int count_consonants(char *strings[], int n);
int count_spaces(char *strings[], int n);

int main() {
    // Strings
    char str1[] = "Dreaded doom darkening skies above"; 
    char str2[] = "Ravenous red raven a rising legend";
    char str3[] = "Ancient Arcane creature of great destruction";
    char str4[] = "Great Greedy source of upheaval";
    char str5[] = "Ominous Winged Overlord with scales of iron";
    char str6[] = "Nightmare of the realm and devourer of nations";

    // Array of strings
    char *strings[] = {str1, str2, str3, str4, str5, str6};
    int n = 6;

    char dragon_name[100];

    make_dragon_name(str1, str2, str3, str4, str5, str6, dragon_name);
    printf("Name of Dragon: %s\n", dragon_name);

    int word_count = count_words(strings, n);
    printf("Diamonds/Words: %d\n", word_count);

    int r_count = count_letter_r(strings, n);
    printf("Rubies/Number of letter r: %d\n", r_count);

    int short_word_count = count_short_words(strings, n);
    printf("Emeralds/Less than 4 letter words: %d\n", short_word_count);

    int vowel_count = count_vowels(strings, n);
    printf("Gold/Vowels: %d\n", vowel_count);

    int consonant_count = count_consonants(strings, n);
    printf("Silver/Consonants: %d\n", consonant_count);

    int space_count = count_spaces(strings, n);
    printf("Copper/Space Count: %d\n", space_count);

    return 0;
}

void make_dragon_name(char str1[], char str2[], char str3[], char str4[], char str5[], char str6[], char result[]) {
    result[0] = toupper(str1[0]);
    result[1] = toupper(str2[0]);
    result[2] = toupper(str3[0]);
    result[3] = toupper(str4[0]);
    result[4] = toupper(str5[0]);
    result[5] = toupper(str6[0]);
    result[6] = ' ';

    result[7] = toupper(strrchr(str1, ' ')[1]);
    result[8] = toupper(strrchr(str2, ' ')[1]);
    result[9] = toupper(strrchr(str3, ' ')[1]);
    result[10] = toupper(strrchr(str4, ' ')[1]);
    result[11] = toupper(strrchr(str5, ' ')[1]);
    result[12] = toupper(strrchr(str6, ' ')[1]);
    result[13] = '\0';
}

int count_words(char *strings[], int n) {
    int word_count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; strings[i][j] != '\0'; j++) {
            if ((j == 0 || strings[i][j-1] == ' ') && strings[i][j] != ' ') {
                word_count++;
            }
        }
    }
    return word_count;
}

int count_letter_r(char *strings[], int n) {
    int r_count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; strings[i][j] != '\0'; j++) {
            if (tolower(strings[i][j]) == 'r') {
                r_count++;
            }
        }
    }
    return r_count;
}

int count_short_words(char *strings[], int n) {
    int short_word_count = 0;
    for (int i = 0; i < n; i++) {
        char temp[100];
        strcpy(temp, strings[i]);
        char *token = strtok(temp, " ");
        while (token != NULL) {
            if (strlen(token) < 4) {
                short_word_count++;
            }
            token = strtok(NULL, " ");
        }
    }
    return short_word_count;
}


int count_vowels(char *strings[], int n) {
    int vowel_count = 0;
    char vowels[] = "aeiouAEIOU";
    for (int i = 0; i < n; i++) {
        for (int j = 0; strings[i][j] != '\0'; j++) {
            if (strchr(vowels, strings[i][j]) != NULL) {
                vowel_count++;
            }
        }
    }
    return vowel_count;
}

int count_consonants(char *strings[], int n) {
    int consonant_count = 0;
    char vowels[] = "aeiouAEIOU";
    for (int i = 0; i < n; i++) {
        for (int j = 0; strings[i][j] != '\0'; j++) {
            if (isalpha(strings[i][j]) && !strchr(vowels, strings[i][j])) {
                consonant_count++;
            }
        }
    }
    return consonant_count;
}

int count_spaces(char *strings[], int n) {
    int space_count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; strings[i][j] != '\0'; j++) {
            if (strings[i][j] == ' ') {
                space_count++;
            }
        }
    }
    return space_count;
}
