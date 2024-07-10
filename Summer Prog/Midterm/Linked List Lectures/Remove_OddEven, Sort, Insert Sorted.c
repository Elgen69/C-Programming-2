#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct Node{
    int data;
    struct Node* next;
} Node, *List;

void printlist(List);
void insertend(List*, int);
void even(List* head);
void odd(List* head);
void insertSorted(List* head, int data);
void sort(List head);

int main(void){
    List head = NULL;
    int data = 0, size = 0;
    char checker[10];
    
    printf("Enter the size of the linked list: ");
    scanf("%d", &size);

    for(int i = 0; i < size; i++){
        printf("Enter element %d: ", i+1);
        scanf("%d", &data);
        insertSorted(&head, data);
    }
    printf("\nLinked list contents: ");
    printlist(head);

    printf("\nType Even to remove odd nodes, Odd to remove even nodes: ");
    scanf("%s", checker);
    if(strcmp(checker, "Even") == 0){
        even(&head);
    }else{
        odd(&head);
    }
    
    printf("\nLinked list contents after deleting nodes accordingly: ");
    printlist(head);
}

void insertSorted(List* head, int data) {
    Node* newNode = malloc(sizeof(Node));
    Node* current = *head;
    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL || (*head)->data >= data) {
        newNode->next = *head;
        *head = newNode;
        return;
    }

    while (current->next != NULL && current->next->data < data) {
        current = current->next;
    }

    newNode->next = current->next;
    current->next = newNode;
}
void sort(List head) {
    int temp = 0;
    
    for (List trav1 = head; trav1 != NULL; trav1 = trav1->next) {
        for (List trav2 = trav1->next; trav2 != NULL; trav2 = trav2->next) {
            if (trav1->data > trav2->data) {
                temp = trav1->data;
                trav1->data = trav2->data;
                trav2->data = temp;
            }
        }
    }
}
void insertend(List* head, int data){
    List new = malloc(sizeof(Node));
    List curr = *head;
    new->data = data;
    new->next = NULL;

    if(*head == NULL){
        *head = new;
        return;
    }

    while(curr->next != NULL){
        curr = curr->next;
    }
    curr->next = new;
}

void even(List* head){
    List temp = *head;
    List prev = NULL;
    
    while (temp != NULL) {
        if (temp->data % 2 != 0) {
            if (temp == *head) {
                *head = temp->next;
                free(temp);
                temp = *head;
            } else {
                prev->next = temp->next;
                free(temp);
                temp = prev->next;
            }
        } else {
            prev = temp;
            temp = temp->next;
        }
    }
}

void odd(List* head){
    List temp = *head;
    List prev = NULL;
    
    while (temp != NULL) {
        if (temp->data % 2 == 0) {
            if (temp == *head) {
                *head = temp->next;
                free(temp);
                temp = *head;
            } else {
                prev->next = temp->next;
                free(temp);
                temp = prev->next;
            }
        } else {
            prev = temp;
            temp = temp->next;
        }
    }
}

void printlist(List head){
    List curr = head;
    
    if(head == NULL){
        printf("\nLinked List is Empty");
        return;
    }
    
    while(curr != NULL){
        printf("%d ", curr->data);
        curr = curr->next;
    }
    printf("\n");
}
