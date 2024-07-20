#include <stdio.h>
#include <stdlib.h>
#include "node.h"

int main(void) {
    // create the head node
    struct Node* linkedList = malloc(sizeof(struct Node));

    int n, a, b;

    printf("Enter number of pairs: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter pair %d:\n", i + 1);
        scanf("%d %d", &a, &b);
        printf("\n");

        addFront(linkedList, createPairNode(a, b));
    }

    printList(linkedList->next);
    struct Node* nextNode = linkedList->next;

    while (linkedList != NULL) {
        free(linkedList);

		linkedList = nextNode;

        if(nextNode != NULL) {
            nextNode = nextNode->next;
        }
    }
}