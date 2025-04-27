#include <stdio.h>
#include <stdlib.h>
#include <math.h>  // For sqrt and pow functions

int main()
{
    float radius, center_x, center_y, point_x, point_y, distance;

    // Input the radius of the circle
    printf("Enter the radius of the circle: ");
    scanf("%f", &radius);

    // Input the center coordinates of the circle
    printf("Enter the center of the circle (x, y): ");
    scanf("%f %f", &center_x, &center_y);

    while (1) {
        // Input the point coordinates to check its position
        printf("Enter the point to check its position (x, y): ");
        scanf("%f %f", &point_x, &point_y);

        // Calculate the distance from the point to the center of the circle
        distance = sqrt(pow((point_x - center_x), 2) + pow((point_y - center_y), 2));

        if (distance < radius) {
            // Point lies inside the circle
            printf("Point (%f, %f) lies within the circle\n", point_x, point_y);
            break;  // Exit the loop if the point is inside the circle
        } else if (distance > radius) {
            // Point lies outside the circle, prompt for a new point
            printf("Point (%f, %f) lies outside the circle. Try another point.\n", point_x, point_y);
        } else {
            // Point lies on the circle
            printf("Point (%f, %f) lies on the circle.\n", point_x, point_y);
            break;  // Exit the loop if the point is on the circle
        }
    }

    return 0;
}
