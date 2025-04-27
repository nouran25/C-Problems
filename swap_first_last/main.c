#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL;

void addNode(int data) {
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }
    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        struct node *current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

void swapFirstAndLast() {
    if (head == NULL || head->next == NULL) {
        return; // No swap needed if list is empty or has only one node
    }

    struct node *current = head, *prev = NULL, *last = head;

    // Find the last node and its previous node
    while (last->next != NULL) {
        prev = last;
        last = last->next;
    }

    if (head == last) {
        return; // If only one node in the list
    }

    // Swap the first and last node
    if (head->next == last) {
        // If there are only two nodes, just swap them
        head->next = NULL;
        last->next = head;
        head = last;
    } else {
        // Otherwise, swap normally
        prev->next = head;
        last->next = head->next;
        head->next = NULL;
        head = last;
    }
}

void display() {
    struct node *current = head;
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    int n, data;

    // Taking input from the user to create the linked list
    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Invalid input. List cannot be created.\n");
        return 0;
    }

    printf("Enter %d elements for the linked list:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &data);
        addNode(data);
    }

    printf("Original list:\n");
    display();

    swapFirstAndLast();

    printf("List after swapping the first node with last:\n");
    display();

    return 0;
}
