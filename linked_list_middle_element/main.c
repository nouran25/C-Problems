#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

// Function to print the middle element of the linked list
void printMiddle(struct node* head)
{
    // Check if the list is empty
    if (head == NULL) {
        printf("The list is empty. No middle element.\n");
        return;
    }

    int count = 0;
    struct node* mid = head;

    while (head != NULL) {
        if (count & 1)  // If count is odd, move the mid pointer
            mid = mid->next;

        ++count;
        head = head->next;
    }

    // Print the middle element
    if (mid != NULL)
        printf("The middle element is [%d]\n", mid->data);
}

// Function to add a new node at the beginning of the list
void push(struct node** head_ref, int new_data)
{
    struct node* new_node = (struct node*)malloc(sizeof(struct node));

    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

// Function to print the linked list
void printList(struct node* ptr)
{
    while (ptr != NULL) {
        printf("%d -> ", ptr->data);
        ptr = ptr->next;
    }
    printf("NULL\n");
}

// Function to free the memory allocated to the linked list
void freeList(struct node* head)
{
    struct node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);  // Free each node
    }
}

int main()
{
    struct node* head = NULL;
    int i;

    // Insert elements into the linked list
    for (i = 5; i > 0; i--) {
        push(&head, i);
        printList(head);
        printMiddle(head);
    }

    // Free the memory allocated to the linked list
    freeList(head);

    return 0;
}
