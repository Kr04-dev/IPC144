#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void) {

    int z;
    int num;
    char letter;

    printf("+----------------------+\n");
    printf("Loop application STARTED\n");
    printf("+----------------------+\n\n");

    do {
        printf("D = do/while | W = while | F = for | Q = quit\n");
        printf("Enter loop type and the number of times to iterate (Quit=Q0): ");
        scanf(" %c %d", &letter, &num);

        if (letter == 'W' && (num > 2 && num < 21)) {
            printf("WHILE   : ");
            z = 0;

            while (z < num) {
                printf("%c", letter);
                z++;
            };
            printf("\n\n");
        }
        else if (letter == 'D' && (num > 2 && num < 21)) {
            printf("DO-WHILE: ");
            z = 0;

            do {
                z++;
                printf("%c", letter);

            } while (z < num);
            printf("\n\n");

        }
        else if (letter == 'F' && (num > 2 && num < 21)) {
            printf("FOR     : ");

            for (z = 0; z < num; z++) {
                printf("%c", letter);
            }
            printf("\n\n");

        }
        else if (letter == 'Q' && (num > 0 || num < 0)) {
            printf("ERROR: To quit, the number of iterations should be 0!\n\n");

        }
        else if ((letter == 'D' || letter == 'W' || letter == 'F') && (num < 3 || num > 20)) {
            printf("ERROR: The number of iterations must be between 3-20 inclusive!\n\n");

        }
        else if (!(letter == 'D' || letter == 'W' || letter == 'F') && !(letter == 'Q' && num == 0)) {
            printf("ERROR: Invalid entered value(s)!\n\n");
        }

        // or  ||
        // and &&

    } while (!(letter == 'Q' && num == 0)); 

    printf("\n+--------------------+\n");
    printf("Loop application ENDED\n");
    printf("+--------------------+\n");
    return 0;
}