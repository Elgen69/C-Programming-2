#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "functions.h"


// Function for Nobles. Delete Towns with...
void deleteCriminalTowns(Town** head) {
    Town* current = *head;
    Town* prev = NULL;

    while (current != NULL) {
        int hasCriminal = 0;
        for (int i = 0; i < 3; i++) {
            if ((strcmp(current->VIP[i].job, "Bandit") == 0) ||
                (strcmp(current->VIP[i].job, "Thief") == 0)) {
                hasCriminal = 1;
                break;
            }
        }
        if (hasCriminal) {
            Town* temp = current;
            if (prev == NULL) {
                *head = current->next;
            } else {
                prev->next = current->next;
            }
            current = current->next;
            free(temp); 
        } else {
            prev = current;
            current = current->next;
        }
    }
}

// Function for Knights. Delete Towns that do not have... but have...
void HuntCriminals(Town** head) {
    Town* current = *head;
    Town* prev = NULL;

    while (current != NULL) {
        int hasGuard = 0;
        int hasCriminal = 0;
        
        for(int i = 0; i < 3; i++){
            if (strcmp(current->VIP[i].job, "Guard") == 0) {
                hasGuard = 1;
            }
            if ((strcmp(current->VIP[i].job, "Bandit") == 0) || (strcmp(current->VIP[i].job, "Thief") == 0)) {
                hasCriminal = 1;
            }
        }
        
        if (hasCriminal && !hasGuard) {
            prev = current;
            current = current->next;
        } else {
            Town* temp = current;
            if (prev == NULL) { 
                *head = current->next;
            } else {
                prev->next = current->next;
            }
            current = current->next;
            free(temp);
        }
    }
}

// Function for Merchants.
void deleteHighGoldTowns(Town** head, int budget) {
    Town* current = *head;
    Town* prev = NULL;

    while(current != NULL) {
        if (current->gold > budget) {
            Town* temp = current;
            if (prev == NULL) { 
                *head = current->next;
            } else {
                prev->next = current->next;
            }
            current = current->next;
            free(temp);
        } else {
            prev = current;
            current = current->next;
        }
    }
}

// Function to sort the list based on distance
void sortTownsByDistance(Town** head) {
    if (*head == NULL || (*head)->next == NULL) {
        return; // List is empty or has only one node
    }

    Town* sorted = NULL;

    while (*head != NULL) {
        Town* current = *head;
        *head = (*head)->next;

        if (sorted == NULL || strcmp(current->distance, sorted->distance) < 0) {
            current->next = sorted;
            sorted = current;
        } else {
            Town* temp = sorted;
            while (temp->next != NULL && strcmp(temp->next->distance, current->distance) < 0) {
                temp = temp->next;
            }
            current->next = temp->next;
            temp->next = current;
        }
    }

    *head = sorted;
}

int main() {
    Town* head = NULL;
    char input[20];

    populate(&head);

    printf("Prepare itinerary for? (Noble, Knight, Merchant): ");
    scanf("%s", input);

    for (int i = 0; input[i]; i++) {
        input[i] = tolower(input[i]);
    }

    if (strcmp(input, "noble") == 0) {
        printf("\nYour Travel Plans, m'lord...\n\n");
        deleteCriminalTowns(&head);
        printTownNames(head);
    } else if (strcmp(input, "knight") == 0) {
        printf("\nCriminals found here good sir...\n\n");
        HuntCriminals(&head);
        printTownNames(head);
    } else if (strcmp(input, "merchant") == 0) {
        printf("\nOoooh Investments...\n\n");
        int budget;
        printf("Your gold:");
        scanf("%d", &budget);
        deleteHighGoldTowns(&head, budget);
        printTownNames(head);
    } else {
        printf("Invalid role entered.\n");
        head = NULL;
    }

    sortTownsByDistance(&head);
    printf("\nFinal Itinerary:\n");
    displayTowns(head);

    return 0;
}
