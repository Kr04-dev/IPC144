#define _CRT_SECURE_NO_WARNINGS
#define BUFFER_SIZE 1024

#include <stdio.h>
#include "core.h"

int inputInt(void) {
    int numberInput, validValue = 0;
    char buffer[BUFFER_SIZE], newLine;

    while (!validValue) {
        fgets(buffer, BUFFER_SIZE, stdin);
        if (sscanf(buffer, "%d%c", &numberInput, &newLine) == 2 && newLine == '\n')
            validValue = 1;
        else
            printf("Error! Input a whole number: ");
    }

    return numberInput;
}

int inputIntPositive(void) {
    int positiveNumber, validValue = 0;

    while (!validValue) {
        positiveNumber = inputInt();
        if (positiveNumber > 0)
            validValue = 1;
        else
            printf("ERROR! Value must be > 0: ");
    }

    return positiveNumber;
}

int inputIntRange(int minNumber, int maxNumber) {
    int numberInput, validValue = 0;

    while (!validValue) {
        numberInput = inputInt();
        if (numberInput >= minNumber && numberInput <= maxNumber)
            validValue = 1;
        else
            printf("ERROR! Value must be between %d and %d inclusive: ", minNumber, maxNumber);
    }

    return numberInput;
}

char inputCharOption(char str[]) {
    char letter, buffer[BUFFER_SIZE];
    int validValue = 0;

    while (!validValue) {
        fgets(buffer, BUFFER_SIZE, stdin);
        if (sscanf(buffer, " %c", &letter) == 1 && strchr(str, letter) != NULL)
            validValue = 1;
        else
            printf("ERROR: Character must be one of [%s]: ", str);
    }

    return letter;
}

void inputCString(char* cStringValue, int minLength, int maxLength) {
    char sixCString[BUFFER_SIZE] = { 0 };
    int validValue = 0, count;

    while (!validValue) {
        fgets(sixCString, BUFFER_SIZE, stdin);
        sixCString[strcspn(sixCString, "\n")] = 0;  // remove newline
        count = strlen(sixCString);

        if (count >= minLength && count <= maxLength) {
            validValue = 1;
            strcpy(cStringValue, sixCString);
        } else {
            if (maxLength == minLength)
                printf("ERROR: String length must be exactly %d chars: ", minLength);
            else if (count > maxLength)
                printf("ERROR: String length must be no more than %d chars: ", maxLength);
            else  // count < minLength
                printf("ERROR: String length must be between %d and %d chars: ", minLength, maxLength);
        }
    }
}

void displayFormattedPhone(const char* phoneNum) {
    int i, count = 0;

    for (i = 0; (phoneNum != NULL) && (phoneNum != '\0') && ('0' <= phoneNum[i]) && (phoneNum[i] <= '9'); i++)
        count++;

    if (count == 10) {
        printf("%c", '(');
        for (i = 0; i < 3; i++)
            printf("%c", phoneNum[i]);
        printf("%c", ')');
        for (i = 3; i < 6; i++)
            printf("%c", phoneNum[i]);
        printf("%c", '-');
        for (i = 6; i < 10; i++)
            printf("%c", phoneNum[i]);
    }
    else {
        printf("(___)___-____");
    }
}

void clearInputBuffer(void) {
    while (getchar() != '\n') {}
}

void suspend(void) {
    printf("<ENTER> to continue...");
    clearInputBuffer();
    putchar('\n');
}
