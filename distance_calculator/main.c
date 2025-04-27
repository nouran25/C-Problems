#include <stdio.h>
#include <stdlib.h>

struct distance {
    int meter;
    int cmeter;
};

struct distance add_distances(struct distance d1, struct distance d2);
struct distance get_distance();
void print_distance(struct distance d);

int main() {
    int num_distances, i;
    struct distance total = {0, 0}; // Initialize total distance to 0
    struct distance current_distance;

    // Ask how many distances the user wants to add
    printf("Enter the number of distances to sum: ");
    if (scanf("%d", &num_distances) != 1 || num_distances <= 0) {
        printf("Invalid input. Please enter a positive number.\n");
        return 1;
    }

    // Collect and sum all distances
    for (i = 0; i < num_distances; i++) {
        printf("\nEnter distance #%d:\n", i + 1);
        current_distance = get_distance();
        total = add_distances(total, current_distance);
    }

    // Output the final total distance
    printf("\nTotal sum of distances: ");
    print_distance(total);

    return 0;
}

// Function to add two distances
struct distance add_distances(struct distance d1, struct distance d2) {
    struct distance sum;
    sum.meter = d1.meter + d2.meter;

    // Calculate total centimeters
    int total_cmeters = d1.cmeter + d2.cmeter;

    // Convert centimeters to meters if needed
    if (total_cmeters >= 100) {
        sum.meter += total_cmeters / 100;
        sum.cmeter = total_cmeters % 100;
    } else {
        sum.cmeter = total_cmeters;
    }

    return sum;
}

// Function to get a distance from the user
struct distance get_distance() {
    struct distance temp;

    printf("Enter meters: ");
    while (scanf("%d", &temp.meter) != 1 || temp.meter < 0) {
        printf("Invalid input. Please enter a non-negative integer for meters: ");
        while (getchar() != '\n'); // Clear the input buffer
    }

    printf("Enter centimeters: ");
    while (scanf("%d", &temp.cmeter) != 1 || temp.cmeter < 0 || temp.cmeter >= 100) {
        printf("Invalid input. Please enter a valid number of centimeters (0-99): ");
        while (getchar() != '\n'); // Clear the input buffer
    }

    return temp;
}

// Function to print a distance in a readable format
void print_distance(struct distance d) {
    printf("%d meters and %d centimeters\n", d.meter, d.cmeter);
}
