#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "functions.h"

//complete the structure for the name of the mage below
typedef struct {
    char fName[50];
    char lName[50];
    char MI;
} Fullname;

//complete the structure for the mage's profile below
typedef struct {
    Fullname name;
    int level;
    char uniqueSpell[50];
}Mage;


typedef struct {
    int minMana;
    int maxMana;
} Duel;

typedef struct School {
    Mage* students;
    int count;
    Duel range;
} MageCollege;

void Decipher(char *message, int key); //Helper Function
void enrollMages(MageCollege* college); //Helper Function

void factorial(int* level, int temp) {
    *level = 1;
    for (int i = 1; i <= temp; i++) {
        *level *= i;
    }
}

void getMana(Mage* student, int key) {
    int temp = 0;
    Decipher(student->uniqueSpell, key);
    
    for (int i = 0; student->uniqueSpell[i] != '\0'; i++) {
        if (student->uniqueSpell[i] == 'a' || student->uniqueSpell[i] == 'e' || student->uniqueSpell[i] == 'i' ||
            student->uniqueSpell[i] == 'o' || student->uniqueSpell[i] == 'u' || student->uniqueSpell[i] == 'I') {
            temp++;
        }
    }
    
    factorial(&student->level, temp);
}

void eligibleMage(MageCollege* eligible, MageCollege college, int key) {
    for (int i = 0; i < college.count; i++) {
        getMana(&college.students[i], key);
    }
    eligible->count = 0;
    eligible->students = (Mage*) malloc(sizeof(Mage) * college.count);
    
    for (int i = 0; i < college.count; i++) {
        if (college.students[i].level >= college.range.minMana && college.students[i].level <= college.range.maxMana) {
            eligible->students[eligible->count++] = college.students[i];
        }
    }
    
    eligible->students = realloc(eligible->students, sizeof(Mage) * eligible->count);
}

void PipersList(MageCollege eligible) {
    printf("\n ===DUELING MAGES===\n");
    Mage temp;
    for (int i = 0; i < eligible.count; i++) {
        for (int j = i + 1; j < eligible.count; j++) {
            if (eligible.students[i].level < eligible.students[j].level /*||
                (eligible.students[i].level == eligible.students[j].level &&
                 strcmp(eligible.students[i].name.fName, eligible.students[j].name.fName) > 0)*/) {
                temp = eligible.students[i];
                eligible.students[i] = eligible.students[j];
                eligible.students[j] = temp;
            } 
        }
    }
    
    for (int i = 0; i < eligible.count; i++) {
        printf("Mage: %s %c %s \n", eligible.students[i].name.fName, eligible.students[i].name.MI, eligible.students[i].name.lName);
        printf("- Mana Level: %d \n", eligible.students[i].level);
        printf("- Deciphered Spell: %s\n\n", eligible.students[i].uniqueSpell);
    }
}


int main(void) {
    int key = -4;
    MageCollege college;
    MageCollege eligible;

    printf("Input Lowest Mana Acceptable:");
    scanf("%d", &college.range.minMana);
    printf("\nInput Highest Mana Acceptable:");
    scanf("%d", &college.range.maxMana);
    enrollMages(&college);
    eligibleMage(&eligible, college, key);
    PipersList(eligible);

    free(eligible.students);  
}
