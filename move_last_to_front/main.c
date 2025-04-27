#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

// Function to move the last node to the front
void moveLastToFront(struct node **head_ref)
{
    // If the list is empty or contains a single node, no movement is needed
    if (*head_ref == NULL || (*head_ref)->next == NULL)
    {
        return;
    }

    struct node *seclast = NULL;
    struct node *last = *head_ref;

    // Traverse to the last node
    while (last->next != NULL)
    {
        seclast = last;
        last = last->next;
    }

    // Make the second last node point to NULL and update the head
    seclast->next = NULL;
    last->next = *head_ref;
    *head_ref = last;
}

// Function to insert a new node at the beginning of the list
void push(struct node **head_ref, int new_data)
{
    struct node *new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

// Function to print the linked list
void print(struct node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

// Main driver function
int main()
{
    struct node *start = NULL;
    int n, data, i;

    // Get the number of elements for the linked list
    printf("Enter the number of elements in the linked list: ");
    scanf("%d", &n);

    // Ask the user for each element and insert it at the beginning of the list
    for(i = 0; i < n; i++)
    {
        printf("Enter element %d: ", i+1);
        scanf("%d", &data);
        push(&start, data);
    }

    // Print the linked list before moving the last node to the front
    printf("\nLinked list before moving last to front:\n");
    print(start);

    // Move the last node to the front
    moveLastToFront(&start);

    // Print the linked list after the operation
    printf("\nLinked list after moving last to front:\n");
    print(start);

    return 0;
}
