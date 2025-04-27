#include <stdio.h>
#include <stdlib.h>

int main()
{
    int resistance;
    float temperature;

    printf("Enter the resistance value: ");
    scanf("%d", &resistance);

    // Check if resistance is within the valid range
    if (resistance < 10000 && resistance > 973)
    {
        // Calculate the temperature
        temperature = -0.36 * resistance + 1009;
        printf("The corresponding temperature is: %.2f\n", temperature);
    }
    else
    {
        printf("Invalid range.\n");
    }

    return 0;
}
