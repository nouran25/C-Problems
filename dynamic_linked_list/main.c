#include <stdio.h>
#include <stdlib.h>

int value;
struct node
{
    int data;
    struct node *next;
} *new, *head, *tail, *temp, *current, *prev = NULL, *next = NULL;

void create()
{
    new = (struct node *)malloc(sizeof(struct node));
    printf("Enter the value:\n");
    scanf("%d", &value);
    new->data = value;
    new->next = NULL;
}

void insert()
{
    create();
    if (head == NULL)
    {
        head = new;
        tail = new;
    }
    else
    {
        tail->next = new;
        tail = new;
    }
}

void display()
{
    printf("Updated linked list is:\n");
    temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void insertatbeg()
{
    if (head == NULL)
        printf("No Linked List found.\n");
    else
    {
        create();
        new->next = head;
        head = new;
        display();
    }
}

void insertatend()
{
    if (head == NULL)
        printf("No Linked List found.\n");
    else
    {
        create();
        tail->next = new;
        tail = new;
        display();
    }
}

void insertatmid()
{
    if (head == NULL)
        printf("No Linked List found.\n");
    else
    {
        create();
        temp = head;
        int pos, i;
        printf("Enter the position where new node is to be inserted:\n");
        scanf("%d", &pos);
        for (i = 0; i < pos - 1; i++)
        {
            if (temp == NULL)
            {
                printf("Position out of range.\n");
                return;
            }
            temp = temp->next;
        }
        new->next = temp->next;
        temp->next = new;
        display();
    }
}

void deleteatbeg()
{
    if (head == NULL)
        printf("No Linked List found.\n");
    else
    {
        temp = head;
        head = head->next;
        free(temp);
        display();
    }
}

void deleteatend()
{
    if (head == NULL)
        printf("No Linked List found.\n");
    else if (head->next == NULL) // Only one node
    {
        free(head);
        head = NULL;
        display();
    }
    else
    {
        temp = head;
        while (temp->next != tail)
        {
            temp = temp->next;
        }
        temp->next = NULL;
        free(tail);
        tail = temp;
        display();
    }
}

void deleteatmid()
{
    if (head == NULL)
        printf("No Linked List found.\n");
    else
    {
        temp = head;
        int pos, i;
        printf("Enter the position which you want to delete:\n");
        scanf("%d", &pos);
        for (i = 0; i < pos - 1; i++)
        {
            if (temp == NULL || temp->next == NULL)
            {
                printf("Position out of range.\n");
                return;
            }
            temp = temp->next;
        }
        struct node *toDelete = temp->next;
        temp->next = temp->next->next;
        free(toDelete);
        display();
    }
}

void count()
{
    if (head == NULL)
        printf("No Linked List found.\n");
    else
    {
        int count = 0;
        temp = head;
        while (temp != NULL)
        {
            count++;
            temp = temp->next;
        }
        printf("\nTotal number of nodes is: %d\n", count);
    }
}

void reverse()
{
    if (head == NULL)
        printf("No Linked List found.\n");
    else
    {
        current = head;
        prev = NULL;
        while (current != NULL)
        {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        head = prev;
        display();
    }
}

int main()
{
    printf("Press:\n1.Insert a new value.\n2.Display all elements.\n3.Insert at beginning.\n4.Insert at End.\n5.Insert in middle.\n6.Delete at beginning.\n7.Delete at End.\n8.Delete in between.\n9.Count total number of nodes.\n10.Reverse\n11.Exit\n");
    int choice;
    do
    {
        printf("\nEnter your choice:\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            insert();
            break;
        case 2:
            display();
            break;
        case 3:
            insertatbeg();
            break;
        case 4:
            insertatend();
            break;
        case 5:
            insertatmid();
            break;
        case 6:
            deleteatbeg();
            break;
        case 7:
            deleteatend();
            break;
        case 8:
            deleteatmid();
            break;
        case 9:
            count();
            break;
        case 10:
            reverse();
            break;
        case 11:
            printf("Exited successfully\n");
            break;
        default:
            printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 11);

    return 0;
}
