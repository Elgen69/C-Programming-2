#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode* next;
};

struct ListNode* reverseLinkedList(struct ListNode* head, int left, int right) {
    if (head == NULL || left == right) {
        return head;
    }
    
    // Dummy node to simplify edge cases where left = 1
    struct ListNode dummy;
    dummy.next = head;
    
    struct ListNode* prev = &dummy;
    struct ListNode* curr = head;
    
    // Move prev to the node before the left index
    for (int i = 1; i < left; i++) {
        prev = curr;
        curr = curr->next;
    }
    
    // Reverse the sublist from left to right
    struct ListNode* tempPrev = prev;
    struct ListNode* tempCurr = curr;
    for (int i = left; i <= right; i++) {
        struct ListNode* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    
    // Connect the nodes before and after the reversed sublist
    tempPrev->next = prev;
    tempCurr->next = curr;
    
    return dummy.next;
}

struct ListNode* createNode(int x) {
    struct ListNode* node = (struct ListNode*)malloc(sizeof(struct ListNode));
    node->val = x;
    node->next = NULL;
    return node;
}

int main() {
    int n, val;
    printf("Enter the size of the linked list: ");
    scanf("%d", &n);

    struct ListNode* head = NULL;
    struct ListNode* tail = NULL;

    for (int i = 0; i < n; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &val);
        struct ListNode* node = createNode(val);
        if (head == NULL) {
            head = node;
            tail = node;
        } else {
            tail->next = node;
            tail = node;
        }
    }
    
    int left = 0, right = 0;
    printf("Enter left and right indices (1-indexed): ");
    scanf("%d %d", &left, &right);
    
    if (left < 1 || right < left) {
        printf("Invalid indices.\n");
        return 1;
    }
    
    struct ListNode* reversed = reverseLinkedList(head, left, right);
    printf("Linked list after reversing between %d and %d: ", left, right);
    while (reversed != NULL) {
        printf("%d ", reversed->val);
        reversed = reversed->next;
    }
    printf("\n");

    return 0;
}