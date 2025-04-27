#include <stdio.h>
#include <stdlib.h>

int hcf(int n1, int n2);

int main()
{
    int n1, n2, gcd;

    // Input validation: check if both numbers are positive
    do {
        printf("Enter two positive numbers: ");
        scanf("%d %d", &n1, &n2);

        if (n1 <= 0 || n2 <= 0)
            printf("Please enter positive integers only.\n");
    } while (n1 <= 0 || n2 <= 0);

    // Calling the function to find the GCD
    gcd = hcf(n1, n2);

    // Output the result
    printf("The G.C.D of %d and %d is %d\n", n1, n2, gcd);

    return 0;
}

// Function to find the GCD using recursion
int hcf(int n1, int n2)
{
    if (n2 != 0)
        return hcf(n2, n1 % n2);
    else
    {
        return n1;
    }
}
