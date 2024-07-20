#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node{
    int data;
    struct node* next;
}Node, *Nodeptr;

void insertend(Node** head, int val);
void printList(Node* head);
void removeList(Node** head);
int main(void){
    int size = 0, val = 0;
    Node* head = NULL;
    
    printf("Enter size: ");
    scanf("%d", &size);
    
    printf("Enter elements: ");
    for(int i = 0; i < size; i++){
        scanf("%d", &val);
        insertend(&head, val);
    }
    printf("Before: \n");
    printList(head);
    printf("\nAfter: \n");
    removeList(&head);
    printList(head);

}
void insertend(Node** head, int val){
    Node* newNode = malloc(sizeof(Node));
    newNode->data = val;
    newNode->next = NULL;

    // while (*head) {
    //     head = &(*(*head)).next;
    // }
    *head = newNode;
}

void printList(Node* head){
    Node* temp = head;
    
    while(temp != NULL){
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    
}

void removeList(Node** head){
    Node* curr = *head;

    while(curr != NULL){
        Node* temp = curr;
        curr = curr->next;
        free(temp);
    }
}