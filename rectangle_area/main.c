#include <stdio.h>
#include <stdlib.h>

struct point
{
    int x, y;
};

struct rectangle
{
    struct point upper_left;
    struct point lower_right;
};

int area(struct rectangle r)
{
    int length, breadth;

    // Ensure length and breadth are always positive
    length = abs(r.lower_right.x - r.upper_left.x);
    breadth = abs(r.upper_left.y - r.lower_right.y);

    return length * breadth;
}

int main()
{
    struct rectangle r;

    printf("Enter the upper-left coordinates of the rectangle: ");
    scanf("%d %d", &r.upper_left.x, &r.upper_left.y);

    printf("Enter the lower-right coordinates of the rectangle: ");
    scanf("%d %d", &r.lower_right.x, &r.lower_right.y);

    printf("Area of the rectangle = %d\n", area(r));

    return 0;
}
