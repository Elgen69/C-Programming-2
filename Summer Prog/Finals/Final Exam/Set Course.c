#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "functions.h"
#include <stdbool.h> // using STDBOOL and hamburger

// Function for Nobles. Delete Towns with...
void deleteCriminalTowns(Town** head) 
{
    Town* current = *head;
    Town* prev = NULL;

    while (current != NULL) 
    {
        int hasCriminal = 0;
        // Check if any VIP in the current town is a Bandit or Thief
        for (int i = 0; i < 3; i++) 
        {
            if ((strcmp(current->VIP[i].job, "Bandit") == 0) ||
                (strcmp(current->VIP[i].job, "Thief") == 0)) 
            {
                hasCriminal = 1;
                break;
            }
        }

        if (hasCriminal) 
        {
            // Node needs to be deleted
            Town* temp = current;
            if (prev == NULL) 
            {
                // Deleting the head node
                *head = current->next;
            } else 
            {
                // Deleting a non-head node
                prev->next = current->next;
            }
            current = current->next; // Move to the next node
            free(temp); // Free the memory of the deleted node
        } else 
        {
            // Node should not be deleted
            prev = current;
            current = current->next;
        }
    }
}

// Function for Knights. Delete Towns that do not have... but have...
void HuntCriminals(Town** head) 
{
    Town* current = *head;
    Town* prev = NULL;

    while (current != NULL) 
    {
        bool hasGuard = false;
        bool hasCriminal = false;
        
        // Check VIPs in the current town
        for(int i = 0; i < 3; i++)
        {
            if (strcmp(current->VIP[i].job, "Guard") == 0) 
            {
                hasGuard = true;
            }
            if ((strcmp(current->VIP[i].job, "Bandit") == 0) || (strcmp(current->VIP[i].job, "Thief") == 0)) 
            {
                hasCriminal = true;
            }
        }
        
        if (hasCriminal && !hasGuard) 
        {
            // Town matches the criteria, keep it
            prev = current;
            current = current->next;
        } else 
        {
            // Town does not match the criteria, delete it
            Town* temp = current;
            if (prev == NULL) 
            { // Deleting the head
                *head = current->next;
            } else 
            {
                prev->next = current->next;
            }
            current = current->next;
            free(temp);
        }
    }
}

// Function for Merchants.
void deleteHighGoldTowns(Town** head, int budget) 
{
    Town* current = *head;
    Town* prev = NULL;

    while(current != NULL) 
    {
        if (current->gold > budget) 
        {
            Town* temp = current;
            if (prev == NULL) 
            { // Deleting the head
                *head = current->next;
            } else 
            {
                prev->next = current->next;
            }
            current = current->next;
            free(temp);
        } else 
        {
            prev = current;
            current = current->next;
        }
    }
}

// Function to sort the list based on distance
void sortTownsByDistance(Town** head) 
{
    if (*head == NULL || (*head)->next == NULL) 
    {
        return; // List is empty or has only one node
    }

    Town* sorted = NULL;

    while (*head != NULL) 
    {
        Town* current = *head;
        *head = (*head)->next;

        if (sorted == NULL || atoi(current->distance) < atoi(sorted->distance)) 
        {
            current->next = sorted;
            sorted = current;
        } else 
        {
            Town* temp = sorted;
            while (temp->next != NULL && atoi(temp->next->distance) < atoi(current->distance)) 
            {
                temp = temp->next;
            }
            current->next = temp->next;
            temp->next = current;
        }
    }

    *head = sorted;
}

int main() 
{
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
