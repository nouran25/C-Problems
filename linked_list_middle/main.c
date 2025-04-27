#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct node {
    int data;
    struct node* next;
} *head;

void Ini() {
    head = NULL;
}

void insert(int num) {
    struct node* newNode = (struct node*) malloc(sizeof(struct node));
    newNode->data  = num;
    newNode->next = head;
    head = newNode;
    printf("Inserted Element: %d\n", num);
}

void printMiddleNode(struct node *head) {
    if (head == NULL) {
        printf("Error: Invalid Input/Empty list.\n");
        return;
    }

    struct node *slow, *fast;
    slow = fast = head;

    while (fast != NULL && fast->next != NULL) {
        fast = fast->next->next;
        slow = slow->next;
    }

    printf("\nMiddle element: %d\n", slow->data);
}

void printLinkedList(struct node *nodePtr) {
    while (nodePtr != NULL) {
        printf("%d", nodePtr->data);
        nodePtr = nodePtr->next;
        if (nodePtr != NULL)
            printf(" --> ");
    }
    printf("\n");
}

int main() {
    Ini();
    int n;
    printf("Enter the number of elements: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Error: Invalid number of elements.\n");
        return 1;
    }

    int i, newData;
    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &newData);
        insert(newData);
    }

    printf("\nLinked List:\n");
    printLinkedList(head);

    printMiddleNode(head);

    return 0;
}
