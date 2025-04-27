#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int isarmstrong(int number);

int main()
{
    int number;

    printf("Enter a number: ");
    scanf("%d", &number);

    if (isarmstrong(number) == 1)
    {
        printf("The number is an Armstrong number.\n");
    }
    else
    {
        printf("The number is not an Armstrong number.\n");
    }

    return 0;
}

int isarmstrong(int number)
{
    int count = 0;
    int n = number;

    // Handle edge case for non-positive numbers
    if (number <= 0) return 0;

    // Count the number of digits in the number
    while (n != 0)
    {
        n = n / 10;
        count++;
    }

    int remainder, power = 0, original = number;

    // Check if the sum of digits raised to the power of count equals the number
    while (number != 0)
    {
        remainder = number % 10;
        power += (int)pow(remainder, count); // cast the result of pow to int
        number = number / 10;
    }

    // Return 1 if the number is Armstrong, otherwise return 0
    if (power == original)
        return 1;
    else
        return 0;
}
