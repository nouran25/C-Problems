#include <stdio.h>
#include <stdlib.h>

int doreverse(int number);

int main()
{
    int number, reverse;

    printf("Enter a number: ");
    scanf("%d", &number);

    reverse = doreverse(number);

    printf("Reverse = %d\n", reverse);

    return 0;
}

int doreverse(int number)
{
    int reverse = 0;

    while (number != 0)
    {
        reverse = reverse * 10 + number % 10;
        number = number / 10;
    }

    return reverse;
}
