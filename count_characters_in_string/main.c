#include <stdio.h>
#include <stdlib.h>

void stringcount(char *s);

int main()
{
    char s[1000];

    printf("Enter the string: ");
    fgets(s, sizeof(s), stdin);

    // Remove the newline character that fgets may add
    s[strcspn(s, "\n")] = '\0';

    stringcount(s);

    return 0;
}

void stringcount(char *s)
{
    int i, alphabets = 0, digits = 0, specialcharacters = 0;

    for(i = 0; s[i]; i++)
    {
        if ((s[i] >= 65 && s[i] <= 90) || (s[i] >= 97 && s[i] <= 122))
            alphabets++;
        else if (s[i] >= 48 && s[i] <= 57)
            digits++;
        else
            specialcharacters++;
    }

    printf("Alphabets = %d\n", alphabets);
    printf("Digits = %d\n", digits);
    printf("Special characters = %d\n", specialcharacters);
}
