#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode* next;
};

void append(struct ListNode** head, int val) {
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->val = val;
    newNode->next = NULL;
    
    if (*head == NULL) {
        *head = newNode;
    } else {
        struct ListNode* current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

void deleteNode(struct ListNode** head, int val) {
    struct ListNode* current = *head;
    struct ListNode* prev = NULL;
    
    while (current != NULL && current->val != val) {
        prev = current;
        current = current->next;
    }
    
    if (current == NULL) {
        printf("Not found\n");
        return;
    }
    
    if (prev == NULL) {
        *head = current->next;
    } else {
        prev->next = current->next;
    }
    
    free(current);
}

void printList(struct ListNode* head) {
    struct ListNode* current = head;
    while (current != NULL) {
        printf("%d -> ", current->val);
        // if (current->next != NULL) {
        //     printf(" -> ");
        // }
        current = current->next;
    }
    printf("\n");
}

void freeList(struct ListNode* head) {
    struct ListNode* current;
    while (head != NULL) {
        current = head;
        head = head->next;
        free(current);
    }
}

int main() {
    int N;
    printf("Enter size: ");
    scanf("%d", &N);
    
    struct ListNode* head = NULL;
    
    printf("Enter elements: ");
    for (int i = 0; i < N; i++) {
        int val;
        scanf("%d", &val);
        append(&head, val);
    }
    
    int valToRemove;
    while (1) {
        printf("Remove: ");
        scanf("%d", &valToRemove);
        if (valToRemove == 0) {
            break;
        }
        deleteNode(&head, valToRemove);
    }
    
    printList(head);
    freeList(head);
    
    return 0;
}
