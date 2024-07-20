//https://pythontutor.com/render.html#code=%23include%20%3Cstdio.h%3E%0A%23include%20%3Cstdlib.h%3E%0A%0Astruct%20ListNode%20%7B%0A%20%20%20%20int%20val%3B%0A%20%20%20%20struct%20ListNode*%20next%3B%0A%7D%3B%0A%0A//%20Function%20to%20find%20the%20length%20of%20a%20linked%20list%0Aint%20getLength%28struct%20ListNode*%20head%29%20%7B%0A%20%20%20%20int%20length%20%3D%200%3B%0A%20%20%20%20struct%20ListNode*%20current%20%3D%20head%3B%0A%20%20%20%20while%20%28current%20!%3D%20NULL%29%20%7B%0A%20%20%20%20%20%20%20%20length%2B%2B%3B%0A%20%20%20%20%20%20%20%20current%20%3D%20current-%3Enext%3B%0A%20%20%20%20%7D%0A%20%20%20%20return%20length%3B%0A%7D%0A%0A//%20Function%20to%20find%20the%20intersection%20point%20of%20two%20linked%20lists%20at%20a%20specific%20index%0Astruct%20ListNode*%20getIntersectionNodeAtIndex%28struct%20ListNode*%20headA,%20struct%20ListNode*%20headB,%20int%20index%29%20%7B%0A%20%20%20%20if%20%28headA%20%3D%3D%20NULL%20%7C%7C%20headB%20%3D%3D%20NULL%29%0A%20%20%20%20%20%20%20%20return%20NULL%3B%0A%0A%20%20%20%20int%20lenA%20%3D%20getLength%28headA%29%3B%0A%20%20%20%20int%20lenB%20%3D%20getLength%28headB%29%3B%0A%0A%20%20%20%20struct%20ListNode*%20ptrA%20%3D%20headA%3B%0A%20%20%20%20struct%20ListNode*%20ptrB%20%3D%20headB%3B%0A%0A%20%20%20%20while%20%28lenA%20%3E%20lenB%29%20%7B%0A%20%20%20%20%20%20%20%20ptrA%20%3D%20ptrA-%3Enext%3B%0A%20%20%20%20%20%20%20%20lenA--%3B%0A%20%20%20%20%7D%0A%0A%20%20%20%20while%20%28lenB%20%3E%20lenA%29%20%7B%0A%20%20%20%20%20%20%20%20ptrB%20%3D%20ptrB-%3Enext%3B%0A%20%20%20%20%20%20%20%20lenB--%3B%0A%20%20%20%20%7D%0A%0A%20%20%20%20//%20Move%20both%20pointers%20to%20the%20index%20position%0A%20%20%20%20for%20%28int%20i%20%3D%200%3B%20i%20%3C%20index%3B%20i%2B%2B%29%20%7B%0A%20%20%20%20%20%20%20%20if%20%28ptrA%20%3D%3D%20NULL%20%7C%7C%20ptrB%20%3D%3D%20NULL%29%0A%20%20%20%20%20%20%20%20%20%20%20%20return%20NULL%3B%0A%20%20%20%20%20%20%20%20ptrA%20%3D%20ptrA-%3Enext%3B%0A%20%20%20%20%20%20%20%20ptrB%20%3D%20ptrB-%3Enext%3B%0A%20%20%20%20%7D%0A%0A%20%20%20%20//%20Iterate%20through%20both%20lists%20until%20the%20intersection%20point%20is%20found%0A%20%20%20%20while%20%28ptrA%20!%3D%20NULL%20%26%26%20ptrB%20!%3D%20NULL%29%20%7B%0A%20%20%20%20%20%20%20%20if%20%28ptrA%20%3D%3D%20ptrB%29%0A%20%20%20%20%20%20%20%20%20%20%20%20return%20ptrA%3B%0A%20%20%20%20%20%20%20%20ptrA%20%3D%20ptrA-%3Enext%3B%0A%20%20%20%20%20%20%20%20ptrB%20%3D%20ptrB-%3Enext%3B%0A%20%20%20%20%7D%0A%0A%20%20%20%20return%20NULL%3B%20//%20No%20intersection%20found%0A%7D%0A%0A//%20Function%20to%20create%20a%20new%20node%20in%20the%20linked%20list%0Astruct%20ListNode*%20createNode%28int%20val%29%20%7B%0A%20%20%20%20struct%20ListNode*%20newNode%20%3D%20%28struct%20ListNode*%29malloc%28sizeof%28struct%20ListNode%29%29%3B%0A%20%20%20%20newNode-%3Eval%20%3D%20val%3B%0A%20%20%20%20newNode-%3Enext%20%3D%20NULL%3B%0A%20%20%20%20return%20newNode%3B%0A%7D%0A%0Aint%20main%28%29%20%7B%0A%20%20%20%20//%20Hardcoded%20values%0A%20%20%20%20int%20sizeA%20%3D%203%3B%0A%20%20%20%20int%20sizeB%20%3D%203%3B%0A%20%20%20%20int%20val%3B%0A%20%20%20%20int%20index%20%3D%202%3B%20//%20Intersection%20starts%20at%20index%202%20%280-based%29%0A%0A%20%20%20%20//%20Create%20the%20first%20linked%20list%3A%201%20-%3E%202%20-%3E%203%0A%20%20%20%20struct%20ListNode*%20headA%20%3D%20createNode%281%29%3B%0A%20%20%20%20struct%20ListNode*%20nodeA1%20%3D%20createNode%282%29%3B%0A%20%20%20%20struct%20ListNode*%20nodeA2%20%3D%20createNode%283%29%3B%0A%20%20%20%20headA-%3Enext%20%3D%20nodeA1%3B%0A%20%20%20%20nodeA1-%3Enext%20%3D%20nodeA2%3B%0A%0A%20%20%20%20struct%20ListNode*%20headB%20%3D%20createNode%284%29%3B%0A%20%20%20%20struct%20ListNode*%20nodeB1%20%3D%20createNode%285%29%3B%0A%20%20%20%20struct%20ListNode*%20nodeB2%20%3D%20createNode%286%29%3B%0A%20%20%20%20headB-%3Enext%20%3D%20nodeB1%3B%0A%20%20%20%20nodeB1-%3Enext%20%3D%20nodeB2%3B%0A%0A%20%20%20%20//%20Create%20intersection%20at%20index%202%20in%20the%20first%20list%0A%20%20%20%20struct%20ListNode*%20currentA%20%3D%20headA%3B%0A%20%20%20%20for%20%28int%20i%20%3D%200%3B%20i%20%3C%20index%20%26%26%20currentA%20!%3D%20NULL%3B%20i%2B%2B%29%20%7B%0A%20%20%20%20%20%20%20%20currentA%20%3D%20currentA-%3Enext%3B%0A%20%20%20%20%7D%0A%0A%20%20%20%20if%20%28currentA%20!%3D%20NULL%29%20%7B%0A%20%20%20%20%20%20%20%20nodeB2-%3Enext%20%3D%20currentA%3B%0A%20%20%20%20%7D%0A%0A%20%20%20%20struct%20ListNode*%20intersectionNode%20%3D%20getIntersectionNodeAtIndex%28headA,%20headB,%20index%29%3B%0A%0A%20%20%20%20if%20%28intersectionNode%20!%3D%20NULL%29%20%7B%0A%20%20%20%20%20%20%20%20printf%28%22Intersection%20point%20is%3A%20%25d%5Cn%22,%20intersectionNode-%3Eval%29%3B%0A%20%20%20%20%7D%20else%20%7B%0A%20%20%20%20%20%20%20%20printf%28%22No%20intersection%20point%20found.%5Cn%22%29%3B%0A%20%20%20%20%7D%0A%0A%20%20%20%20struct%20ListNode*%20tmp%3B%0A%20%20%20%20while%20%28headA%20!%3D%20NULL%29%20%7B%0A%20%20%20%20%20%20%20%20tmp%20%3D%20headA%3B%0A%20%20%20%20%20%20%20%20headA%20%3D%20headA-%3Enext%3B%0A%20%20%20%20%7D%0A%20%20%20%20while%20%28headB%20!%3D%20NULL%29%20%7B%0A%20%20%20%20%20%20%20%20tmp%20%3D%20headB%3B%0A%20%20%20%20%20%20%20%20headB%20%3D%20headB-%3Enext%3B%0A%20%20%20%20%7D%0A%0A%20%20%20%20return%200%3B%0A%7D&cumulative=false&curInstr=120&heapPrimitives=nevernest&mode=display&origin=opt-frontend.js&py=c_gcc9.3.0&rawInputLstJSON=%5B%5D&textReferences=false
#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode* next;
};

// Function to find the length of a linked list
int getLength(struct ListNode* head) {
    int length = 0;
    struct ListNode* current = head;
    while (current != NULL) {
        length++;
        current = current->next;
    }
    return length;
}

// Function to find the intersection point of two linked lists at a specific index
struct ListNode* getIntersectionNodeAtIndex(struct ListNode* headA, struct ListNode* headB, int index) {
    if (headA == NULL || headB == NULL)
        return NULL;

    int lenA = getLength(headA);
    int lenB = getLength(headB);

    struct ListNode* ptrA = headA;
    struct ListNode* ptrB = headB;

    // Adjust the starting point of the longer linked list
    while (lenA > lenB) {
        ptrA = ptrA->next;
        lenA--;
    }

    while (lenB > lenA) {
        ptrB = ptrB->next;
        lenB--;
    }

    // Move both pointers to the index position
    for (int i = 0; i < index; i++) {
        if (ptrA == NULL || ptrB == NULL)
            return NULL;
        ptrA = ptrA->next;
        ptrB = ptrB->next;
    }

    // Iterate through both lists until the intersection point is found
    while (ptrA != NULL && ptrB != NULL) {
        if (ptrA == ptrB)
            return ptrA;
        ptrA = ptrA->next;
        ptrB = ptrB->next;
    }

    return NULL; // No intersection found
}

// Function to create a new node in the linked list
struct ListNode* createNode(int val) {
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}

int main() {
    int sizeA, sizeB, val, index;
    printf("Enter the size of first linked list: ");
    scanf("%d", &sizeA);

    struct ListNode* headA = NULL;
    struct ListNode* tailA = NULL;

    printf("Enter the elements of first linked list: ");
    for (int i = 0; i < sizeA; i++) {
        scanf("%d", &val);
        struct ListNode* newNode = createNode(val);
        if (headA == NULL) {
            headA = newNode;
            tailA = newNode;
        } else {
            tailA->next = newNode;
            tailA = newNode;
        }
    }

    printf("Enter the size of second linked list: ");
    scanf("%d", &sizeB);

    struct ListNode* headB = NULL;
    struct ListNode* tailB = NULL;

    printf("Enter the elements of second linked list: ");
    for (int i = 0; i < sizeB; i++) {
        scanf("%d", &val);
        struct ListNode* newNode = createNode(val);
        if (headB == NULL) {
            headB = newNode;
            tailB = newNode;
        } else {
            tailB->next = newNode;
            tailB = newNode;
        }
    }

    printf("Enter the index of the node at which the intersection of two linked lists begins (-1 if no intersection): ");
    scanf("%d", &index);

    if (index != -1) {
        struct ListNode* currentA = headA;
        for (int i = 0; i < index && currentA != NULL; i++) {
            currentA = currentA->next;
        }

        if (currentA != NULL) {
            tailB->next = currentA;
        }
    }

    struct ListNode* intersectionNode = getIntersectionNodeAtIndex(headA, headB, index);

    if (intersectionNode != NULL) {
        printf("Intersection point is: %d\n", intersectionNode->val);
    } else {
        printf("No intersection point found.\n");
    }

    struct ListNode* tmp;
    while (headA != NULL) {
        tmp = headA;
        headA = headA->next;
    }
    while (headB != NULL) {
        tmp = headB;
        headB = headB->next;
    }

    return 0;
}
