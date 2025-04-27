#include <stdio.h>
#include <stdlib.h>

// Function prototypes
void sort(int* arr, int size);
void print(int* arr, int size);

int main() {
    int size;

    // Ask for the size of the array
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    // Dynamic allocation of array based on the size
    int arr[size];

    // Ask the user for the array elements
    printf("Enter the elements of the array: ");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    // Sort the array
    sort(arr, size);

    // Print the sorted array
    printf("The ascending order of the array is: ");
    print(arr, size);

    return 0;
}

// Function to sort the array in ascending order (Bubble Sort)
void sort(int* arr, int size) {
    int temp;

    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Function to print the array
void print(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
