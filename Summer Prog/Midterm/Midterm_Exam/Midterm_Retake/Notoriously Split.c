#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
// #include "functions.h"

typedef struct {
    char fName[100];
    char MI;
    char lName[100];
} Fullname;

typedef struct {
    Fullname name;
    int gold;
    int level;
    char location[50];
} Creature;

typedef struct {
    Creature* persons;
    int count;
} Town;

// Function prototypes
void steal(Town* town);
void fight(Town* town, int level);
void track(Town* town);
void populateTown(Town* town);

int main(void) {
    Town town;
    populateTown(&town);

    char input[20];

    printf("Who are you today? (assassin, warrior, thief): ");
    scanf("%s", input);
    for (int i = 0; input[i]; i++) {
        input[i] = tolower(input[i]);
    }

    if (strcmp(input, "assassin") == 0) {
        printf("\nHunting Nobles....\n\n");
        track(&town);
    } else if (strcmp(input, "warrior") == 0) {
        printf("\nEager for a scrap...\n\n");
        int level;
        printf("So.. how tough are ya?: ");
        scanf("%d", &level);
        fight(&town, level);
    } else if (strcmp(input, "thief") == 0) {
        printf("\nOoooh Shiny...\n\n");
        steal(&town);
    } else {
        printf("Invalid role entered.\n");
    }

    free(town.persons);

    return 0;
}

void populateTown(Town* town) {
    // Populate the town with example data
    town->count = 12;
    town->persons = malloc(town->count * sizeof(Creature));

    // Example data
    Creature creatures[] = {
        {{"Vulkan", 'A', "Salamander"}, 12, 210, "Tavern"},
        {{"Roboute", 'U', "Guilliman"}, 100, 90, "Castle"},
        {{"Jaghatai", 'A', "Khan"}, 145, 82, "Stables"},
        {{"Sanguinis", 'I', "Bloodangel"}, 12, 82, "Castle"},
        {{"Rogal", 'E', "Dorn"}, 120, 77, "Castle"},
        {{"Perturabo", 'O', "Iron"}, 15, 22, "Castle"},
        {{"Fulgrim", 'A', "Chemos"}, 200, 12, "Tavern"},
        {{"Konrad", 'X', "Kurze"}, 9, 52, "Tavern"},
        {{"Mortarion", 'H', "Barbarus"}, 17, 17, "Tavern"},
        {{"Ferrus", 'R', "Manus"}, 20, 25, "Stables"},
        {{"Corvus", 'C', "Corax"}, 50, 111, "Stables"},
        {{"Alpharius", 'N', "Omegon"}, 101, 51, "Stables"}
    };

    for (int i = 0; i < town->count; i++) {
        town->persons[i] = creatures[i];
    }
}

void steal(Town* town) {
    // Find the location with the most gold
    int maxGold = 0;
    char location[50];

    for (int i = 0; i < town->count; i++) {
        int goldSum = 0;
        for (int j = 0; j < town->count; j++) {
            if (strcmp(town->persons[i].location, town->persons[j].location) == 0) {
                goldSum += town->persons[j].gold;
            }
        }
        if (goldSum > maxGold) {
            maxGold = goldSum;
            strcpy(location, town->persons[i].location);
        }
    }

    printf("Location with the most gold to steal: %s\n", location);
    printf("Total gold amount: %d\n", maxGold);
    printf("Target Persons in %s:\n\n", location);

    Creature* targets = malloc(town->count * sizeof(Creature));
    int targetCount = 0;

    for (int i = 0; i < town->count; i++) {
        if (strcmp(town->persons[i].location, location) == 0) {
            targets[targetCount++] = town->persons[i];
        }
    }

    // Bubble sort targets by gold in ascending order
    for (int i = 0; i < targetCount - 1; i++) {
        for (int j = 0; j < targetCount - i - 1; j++) {
            if (targets[j].gold > targets[j + 1].gold) {
                Creature temp = targets[j];
                targets[j] = targets[j + 1];
                targets[j + 1] = temp;
            }
        }
    }

    for (int i = 0; i < targetCount; i++) {
        printf("Name: %s %c %s\n", targets[i].name.fName, targets[i].name.MI, targets[i].name.lName);
        printf("- Gold: %d\n", targets[i].gold);
        printf("- Level: %d\n\n", targets[i].level);
    }

    free(targets);
}

void fight(Town* town, int level) {
    // Find the location with the most fighters below the given level
    int maxCount = 0;
    char location[50];

    for (int i = 0; i < town->count; i++) {
        int fighterCount = 0;
        for (int j = 0; j < town->count; j++) {
            if (strcmp(town->persons[i].location, town->persons[j].location) == 0 && town->persons[j].level < level) {
                fighterCount++;
            }
        }
        if (fighterCount > maxCount) {
            maxCount = fighterCount;
            strcpy(location, town->persons[i].location);
        }
    }

    printf("Location with the most fighters below Level %d: %s\n", level, location);
    printf("Target fighters count: %d\n", maxCount);
    printf("Persons in %s below Level %d:\n\n", location, level);

    Creature* targets = malloc(town->count * sizeof(Creature));
    int targetCount = 0;

    for (int i = 0; i < town->count; i++) {
        if (strcmp(town->persons[i].location, location) == 0 && town->persons[i].level < level) {
            targets[targetCount++] = town->persons[i];
        }
    }

    // Selection sort targets by level in descending order
    for (int i = 0; i < targetCount - 1; i++) {
        int maxIndex = i;
        for (int j = i + 1; j < targetCount; j++) {
            if (targets[j].level > targets[maxIndex].level) {
                maxIndex = j;
            }
        }
        Creature temp = targets[i];
        targets[i] = targets[maxIndex];
        targets[maxIndex] = temp;
    }

    for (int i = 0; i < targetCount; i++) {
        printf("Name: %s %c %s\n", targets[i].name.fName, targets[i].name.MI, targets[i].name.lName);
        printf("- Gold: %d\n", targets[i].gold);
        printf("- Level: %d\n\n", targets[i].level);
    }

    free(targets);
}

void track(Town* town) {
    // Find nobles (those with vowels as middle initial)
    char vowels[] = "AEIOUaeiou";

    Creature* nobles = malloc(town->count * sizeof(Creature));
    int nobleCount = 0;

    for (int i = 0; i < town->count; i++) {
        if (strchr(vowels, town->persons[i].name.MI) != NULL) {
            nobles[nobleCount++] = town->persons[i];
        }
    }

    // Bubble sort nobles by level in descending order
    for (int i = 0; i < nobleCount - 1; i++) {
        for (int j = 0; j < nobleCount - i - 1; j++) {
            if (nobles[j].level < nobles[j + 1].level) {
                Creature temp = nobles[j];
                nobles[j] = nobles[j + 1];
                nobles[j + 1] = temp;
            }
        }
    }

    printf("Nobles to hunt:\n\n");

    for (int i = 0; i < nobleCount; i++) {
        printf("Name: %s %c %s\n", nobles[i].name.fName, nobles[i].name.MI, nobles[i].name.lName);
        printf("- Gold: %d\n", nobles[i].gold);
        printf("- Level: %d\n", nobles[i].level);
        printf("- Location: %s\n\n", nobles[i].location);
    }

    free(nobles);
}
