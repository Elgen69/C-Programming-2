#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct{
    char itemName[30];
    int expYear;
} itemInfo;

typedef struct node{
    itemInfo item;
    struct node* next;
} Node;

void insertLast(Node** headref, char* item, int expiry);
void printLinkedList(Node* headref);
void remove_expired(Node** headref);

int main(void){
    Node* head = NULL;
    int size = 0, expiry = 0;
    char item[30];
    
    printf("Enter size of linked list: ");
    scanf("%d", &size);
    
    for (int i = 0; i < size; i++) {
        printf("Enter item Name: ");
        scanf("%s", item);
        printf("Enter expiry date: ");
        scanf("%d", &expiry);
        insertLast(&head, item, expiry);
    }
    printf("\nLinked List Original: \n");
    printLinkedList(head);
    
    remove_expired(&head);
    printf("\nLinked List Without Expiry: \n");
    printLinkedList(head);
    
    return 0;
}

void insertLast(Node** headref, char* item, int expiry){
    Node* newNode = malloc(sizeof(Node));
    strcpy(newNode->item.itemName, item);
    newNode->item.expYear = expiry;
    newNode->next = NULL;
    
    if (*headref == NULL) {
        *headref = newNode;
        return;
    }
    
    Node* temp = *headref;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    
    temp->next = newNode;
}

void printLinkedList(Node* head) {
    Node* curr = head;
    while (curr != NULL) {
        printf("%s %d\n", curr->item.itemName, curr->item.expYear); 
        curr = curr->next;
    }
    printf("\n");
}

void remove_expired(Node** headref){
    Node* temp = *headref;
    Node* prev = NULL;
    
    while (temp != NULL) {
        if (temp->item.expYear < 2024) {
            if (temp == *headref) {
                *headref = temp->next;
                free(temp);
                temp = *headref;
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
