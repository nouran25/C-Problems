#include <stdio.h>
#include <stdlib.h>

int main()
{
    int message_code;

    // Display the available codes for the user
    printf("Enter the message code (0-2):\n");
    printf("0: The enemies are about to attack.\n");
    printf("1: The enemies are summoning new forces.\n");
    printf("2: The enemies are withdrawing their forces.\n");

    // Input message code
    printf("Enter the message code: ");
    scanf("%d", &message_code);

    // Decoding the message
    switch (message_code) {
        case 0:
            printf("The enemies are about to attack.\n");
            break;
        case 1:
            printf("The enemies are summoning new forces.\n");
            break;
        case 2:
            printf("The enemies are withdrawing their forces.\n");
            break;
        default:
            printf("Invalid message code.\n");
            break;
    }

    return 0;
}
