#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct input
{
    char name[100];
    int salary, hours_of_work;
};

// Function to get employee information
struct input getinformation();

int main()
{
    int n, i;
    // Ask for the number of employees
    printf("Enter the number of employees: ");
    scanf("%d", &n);

    // Dynamically allocate memory for n employees
    struct input *temp = malloc(n * sizeof(struct input));

    // Get information for n employees
    for(i = 0; i < n; i++)
    {
        temp[i] = getinformation(); // Corrected function call
    }

    // Apply bonuses based on work hours and print the updated salary
    for(i = 0; i < n; i++)
    {
        if(temp[i].hours_of_work == 8)
        {
            temp[i].salary = temp[i].salary + 50;
            printf("\n%s: $%d\n", temp[i].name, temp[i].salary);
        }
        else if(temp[i].hours_of_work == 10)
        {
            temp[i].salary = temp[i].salary + 100;
            printf("\n%s: $%d\n", temp[i].name, temp[i].salary);
        }
        else if(temp[i].hours_of_work >= 12)
        {
            temp[i].salary = temp[i].salary + 150;
            printf("\n%s: $%d\n", temp[i].name, temp[i].salary);
        }
        else
        {
            printf("\n%s: $%d\n", temp[i].name, temp[i].salary);
        }
    }

    // Free the dynamically allocated memory
    free(temp);

    return 0;
}

// Function to get employee information
struct input getinformation()
{
    struct input temp;

    printf("\nEnter the name of the employee: ");
    getchar(); // Consume the leftover newline from previous input
    fgets(temp.name, 100, stdin);  // Read the name
    temp.name[strcspn(temp.name, "\n")] = '\0';  // Remove the newline character if present

    printf("Enter the number of worked hours: ");
    scanf("%d", &temp.hours_of_work);

    printf("Enter the salary of the employee: ");
    scanf("%d", &temp.salary);

    return temp;
}
