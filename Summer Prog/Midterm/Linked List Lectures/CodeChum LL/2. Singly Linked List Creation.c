    #include "linkedList.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
}Node;

void printList(struct Node* head) {
     struct Node* curr = head;
    
    if(head == NULL){
        printf("\nLinked List is Empty");
        return;
    }
    
    while(curr != NULL){
        printf("%d ", curr->data);
        curr = curr->next;
    }
}

struct Node* createLinkedList(int values[], int n) {
    Node* head = NULL;

    for (int i = 0; i < n; i++) {
        Node* newNode = malloc(sizeof(Node));
        Node* current = head;
        newNode->data = values[i];
        newNode->next = NULL;

        if (head == NULL /*|| head->data >= values[i]*/) {
            newNode->next = head;
            head = newNode;
        } else {
            while (current->next != NULL /*&& current->next->data < values[i]*/) {
                current = current->next;
            }
            newNode->next = current->next;
            current->next = newNode;
        }
    }
    return head;
}
