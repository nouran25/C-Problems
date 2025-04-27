#include <stdio.h>
#include <malloc.h>

int value;

struct node {
    int data;
    struct node *next;
} *new, *head, *tail, *temp, *current, *prev, *next;

// Function to create a new node with a user input value
void create() {
    new = (struct node*)malloc(sizeof(struct node)); // Allocating memory for a new node
    printf("Enter the value:\n");
    scanf("%d", &value); // Taking user input for the value
    new->data = value; // Assigning the input value to the node
    new->next = NULL; // The next pointer is NULL initially, as it's a new node
}

// Function to insert a new node at the end of the linked list
void insert() {
    create(); // Call create() to create a new node
    if (head == NULL) { // If the linked list is empty
        head = new; // The new node becomes the head of the list
        tail = new; // The new node also becomes the tail of the list
    } else {
        tail->next = new; // Link the current tail to the new node
        tail = new; // Update the tail to the new node
    }
}

// Function to display all the nodes in the linked list
void display() {
    printf("Updated linked list is:\n");
    temp = head; // Start from the head of the list
    while (temp != NULL) { // Traverse through all nodes
        printf("%d ", temp->data); // Print the data of the current node
        temp = temp->next; // Move to the next node
    }
}

// Function to insert a new node at the beginning of the list
void insertatbeg() {
    if (head == NULL) // If the linked list is empty
        printf("No Linked List found.\n");
    else {
        create(); // Create a new node
        new->data = value; // Assign the input value to the node
        new->next = head; // Make the new node point to the current head
        head = new; // Update the head to the new node
        display(); // Display the updated list
    }
}

// Function to insert a new node at the end of the list
void insertatend() {
    if (head == NULL) // If the linked list is empty
        printf("No Linked List found.\n");
    else {
        create(); // Create a new node
        new->data = value; // Assign the input value to the node
        tail->next = new; // Link the current tail to the new node
        new->next = NULL; // The new node will be the new tail
        tail = new; // Update the tail to the new node
        display(); // Display the updated list
    }
}

// Function to insert a new node at a specific position
void insertatmid() {
    if (head == NULL) // If the linked list is empty
        printf("No Linked List found.\n");
    else {
        create(); // Create a new node
        temp = head; // Start from the head of the list
        int pos, i;
        printf("Enter the position where new node is to be inserted:\n");
        scanf("%d", &pos); // Take the position input from the user

        // Traverse to the node just before the specified position
        for (i = 0; i < pos - 1; i++) {
            temp = temp->next;
        }

        new->data = value; // Assign the input value to the new node
        new->next = temp->next; // Link the new node to the next node in the list
        temp->next = new; // Link the previous node to the new node
        display(); // Display the updated list
    }
}

// Function to delete a node from the beginning of the list
void deleteatbeg() {
    if (head == NULL) // If the linked list is empty
        printf("No Linked List found.\n");
    else {
        temp = head; // Start from the head of the list
        head = head->next; // Update the head to the next node
        temp->next = NULL; // Disconnect the deleted node from the list
        display(); // Display the updated list
    }
}

// Function to delete a node from the end of the list
void deleteatend() {
    if (head == NULL) // If the linked list is empty
        printf("No Linked List found.\n");
    else {
        temp = head; // Start from the head of the list
        while (temp->next != tail) { // Traverse until the second-to-last node
            temp = temp->next;
        }
        temp->next = NULL; // Remove the tail node by setting the second-to-last node's next to NULL
        tail = temp; // Update the tail to the second-to-last node
        display(); // Display the updated list
    }
}

// Function to delete a node from a specific position
void deleteatmid() {
    if (head == NULL) // If the linked list is empty
        printf("No Linked List found.\n");
    else {
        temp = head; // Start from the head of the list
        int pos, i;
        printf("Enter the position which you want to delete:\n");
        scanf("%d", &pos); // Take the position input from the user

        // Traverse to the node just before the specified position
        for (i = 0; i < pos - 1; i++) {
            temp = temp->next;
        }

        temp->next = temp->next->next; // Bypass the node to be deleted
        display(); // Display the updated list
    }
}

// Function to count the total number of nodes in the list
void count() {
    if (head == NULL) // If the linked list is empty
        printf("No Linked List found.\n");
    else {
        int count = 0; // Initialize the counter
        temp = head; // Start from the head of the list
        while (temp != NULL) { // Traverse through the list
            count++; // Increment the counter for each node
            temp = temp->next; // Move to the next node
        }
        printf("\nTotal number of nodes is: %d\n", count); // Display the total count
    }
}

// Function to reverse the order of the linked list
void reverse() {
    if (head == NULL) // If the linked list is empty
        printf("No Linked List found.\n");
    else {
        current = head; // Start from the head of the list
        while (current != NULL) { // Traverse through the list
            next = current->next; // Store the next node
            current->next = prev; // Reverse the link to point to the previous node
            prev = current; // Move the previous pointer to the current node
            current = next; // Move to the next node
        }
        head = prev; // Update the head to the new first node
        display(); // Display the updated (reversed) list
    }
}

// Main function to provide a menu-driven interface
int main() {
    printf("Press:\n1.Insert a new value.\n2.Display all elements.\n3.Insert at beginning.\n4.Insert at End.\n5.Insert in middle.\n6.Delete at beginning.\n7.Delete at End.\n8.Delete in between.\n9.Count total number of nodes.\n10.Reverse\n11.Exit");

    int choice;
    do {
        printf("\nEnter your choice:\n");
        scanf("%d", &choice); // Take the user's choice

        switch (choice) {
            case 1:
                insert(); // Insert a new node at the end
                break;
            case 2:
                display(); // Display the list
                break;
            case 3:
                insertatbeg(); // Insert a new node at the beginning
                break;
            case 4:
                insertatend(); // Insert a new node at the end
                break;
            case 5:
                insertatmid(); // Insert a new node at a specific position
                break;
            case 6:
                deleteatbeg(); // Delete the node at the beginning
                break;
            case 7:
                deleteatend(); // Delete the node at the end
                break;
            case 8:
                deleteatmid(); // Delete the node at a specific position
                break;
            case 9:
                count(); // Count the number of nodes
                break;
            case 10:
                reverse(); // Reverse the linked list
                break;
            case 11:
                printf("Exited successfully\n"); // Exit the program
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 11); // Keep showing the menu until the user exits
}
