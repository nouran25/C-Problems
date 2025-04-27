#include <stdio.h>
#include <stdlib.h>

int main() {
    int i, j, row, col;

    // Get the number of rows and columns from the user
    printf("Enter the number of rows: ");
    scanf("%d", &row);
    printf("Enter the number of columns: ");
    scanf("%d", &col);

    int arr[row][col];  // Declare the 2D array

    // Input the elements of the 2D array
    for (i = 0; i < row; i++) {
        for (j = 0; j < col; j++) {
            printf("Enter element [%d][%d]: ", i, j);
            scanf("%d", &arr[i][j]);
        }
    }

    int count = 0, find;

    // Get the number to search for
    printf("Enter the number you want to check for its occurrence: ");
    scanf("%d", &find);

    // Count the occurrences of the number in the array
    for (i = 0; i < row; i++) {
        for (j = 0; j < col; j++) {
            if (arr[i][j] == find) {
                count++;
            }
        }
    }

    // Output the result
    printf("The number of occurrences of %d is %d\n", find, count);

    return 0;
}
