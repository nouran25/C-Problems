#include <stdio.h>
#include <stdlib.h>

struct student
{
    int roll_no, marks;
    char name[25];
} stud[100], t;

int main()
{
    int i, j, n;
    printf("Enter the number of students: ");
    scanf("%d", &n);

    printf("Enter student info as roll_no, name, marks:\n");
    for (i = 0; i < n; i++)
    {
        printf("Enter the info of student number %d: ", i + 1);
        scanf("%d", &stud[i].roll_no);
        getchar();  // To consume the leftover newline character
        fgets(stud[i].name, sizeof(stud[i].name), stdin);  // Safe input for name
        printf("Enter marks: ");
        scanf("%d", &stud[i].marks);
    }

    // Sorting based on marks in descending order
    for (i = 0; i < n - 1; i++)
    {
        int swapped = 0;  // Flag to check if swapping happened
        for (j = 0; j < n - 1 - i; j++)
        {
            if (stud[j].marks < stud[j + 1].marks)
            {
                t = stud[j];
                stud[j] = stud[j + 1];
                stud[j + 1] = t;
                swapped = 1;
            }
        }
        // If no swaps happened, the array is already sorted
        if (!swapped)
            break;
    }

    // Displaying the sorted student information
    printf("\nStudent info in terms of marks from highest to lowest:\n");
    printf("\nROLL_NO\tNAME\t\tMARKS\n");
    printf("------------------------------------------------------------\n");
    for (i = 0; i < n; i++)
    {
        // Adjusted for proper formatting
        printf("%d\t%-15s\t%d\n", stud[i].roll_no, stud[i].name, stud[i].marks);
    }

    return 0;
}
