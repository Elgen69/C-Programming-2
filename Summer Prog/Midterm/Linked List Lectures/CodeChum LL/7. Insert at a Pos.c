#include "node.h"
#include <stdio.h>
#include <stdlib.h>

struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode->value = value;
    newNode->next = NULL;
    return newNode;
}

void insertAtPos(struct Node* linkedList, int newValue, int pos) {
    struct Node* newNode = createNode(newValue);

    if (pos == 0) {
        newNode->next = linkedList;
        linkedList = newNode;
        return;
    }

    struct Node* current = linkedList;
    for (int i = 0; i < pos - 1 && current != NULL; i++) {
        current = current->next;
    }

    if (current == NULL) {
        printf("Position is out of bounds.\n");
        free(newNode);
        return;
    }

    newNode->next = current->next;
    current->next = newNode;
}

void printList(struct Node* head) {
    struct Node* current = head->next;

    while (current != NULL) {
        printf("%d", current->value);
        if (current->next != NULL) {
            printf(" -> ");
        }
        current = current->next;
    }
}