/* Consider two points P(px,py) , Q(qx,qy) and . We consider the inversion or point
reflection, R(rx,ry) , of point P across point Q to be a 180 degree rotation of point P
around point Q */
#include <stdio.h>
#include <stdlib.h>

int main()
{
    float x1, y1, x2, y2, x3, y3;

    // Taking coordinates of point P
    printf("Enter the coordinates of the first point 'P' (px py): \n");
    scanf("%f %f", &x1, &y1);

    // Taking coordinates of point Q
    printf("Enter the coordinates of the second point 'Q' (qx qy): \n");
    scanf("%f %f", &x2, &y2);

    // Calculating the inversion point R (reflection of P across Q)
    x3 = 2 * x2 - x1; // x3 - x2 = x2 - x1
    y3 = 2 * y2 - y1; // y3 - y2 = y2 - y1

    // Displaying the reflection point R
    printf("The inversion point 'R' is: (%.2f, %.2f)\n", x3, y3);

    return 0;
}
