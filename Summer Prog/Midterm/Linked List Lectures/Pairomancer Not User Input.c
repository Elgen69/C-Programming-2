#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
} Node, *NodePtr;

// Function to print closest pairs
void groupClosestPairs(NodePtr list) {
    printf("Closest pairs:\n");
    for (; list != NULL; list = list->next) {
        printf("(%d, ", list->data);
        (list->next->data == 0) ? printf("-)\n") : printf("%d)\n", list->next->data);
        list = list->next;
    }
}

// Function to sort the linked list
void sort(NodePtr list) {
    int temp = 0;
    
    for (NodePtr trav1 = list; trav1 != NULL; trav1 = trav1->next) {
        for (NodePtr trav2 = trav1->next; trav2 != NULL; trav2 = trav2->next) {
            if (trav1->data > trav2->data) {
                temp = trav1->data;
                trav1->data = trav2->data;
                trav2->data = temp;
            }
        }
    }
}

// Function to display the linked list
void display(NodePtr list) {
    NodePtr trav = list;
    
    while (trav != NULL) {
        printf("%d ", trav->data);
        trav = trav->next;
    }
    printf("\n");
}

int main() {
    // Hardcoded values
    NodePtr list = NULL;
    int values[] = {5, 3, 8, 6, 7, 9}; // Example values
    int numElements = sizeof(values) / sizeof(int); // Calculate the number of elements

    // Create and link nodes based on hardcoded values
    for (int i = 0; i < numElements; i++) {
        NodePtr newNode = malloc(sizeof(Node));
        newNode->data = values[i];
        newNode->next = list;
        list = newNode;
    }

    sort(list);

    display(list);

    groupClosestPairs(list);
}
