/*/////////////////////////////////////////////////////////////////////////
                        Assignment 1 - Milestone 2
Full Name  : Taehwa Hong
Student ID#: 132546227
Email      : thong14@myseneca.ca
Section    : IPC144NAA

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

//
// Copy your work done from Milestone #1 (core.c) into this file
// - Organize your functions in the same order as they are listed in the core.h file
// - Also copy the commented "sections" to help with finding functions quickly!
//
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#include "core.h"


// Function for Input Integer
int inputInt(void)
{
	int numberInput, validValue;
	char newLine = 'X';

	do
	{
		validValue = 1;

		scanf("%d%c", &numberInput, &newLine);

		if (!(newLine == '\n'))
		{
			validValue = 0;

			clearInputBuffer();
			printf("Error! Input a whole number: ");

		}
	} while (!validValue);

	return numberInput;
}

// Function for Input Positive Integer
int inputIntPositive(void)
{
	int positiveNumber, validValue;

	do
	{
		scanf("%d", &positiveNumber);

		validValue = 1;

		if (positiveNumber <= 0)
		{
			validValue = 0;
			printf("ERROR! Value must be > 0: ");
		}

	} while (!validValue);

	return positiveNumber;
}

// Range of Integer
int inputIntRange(int minNumber, int maxNumber)
{
	int numberInput, validValue;
	char newLine = 'X';

	do
	{
		validValue = 1;

		scanf("%d%c", &numberInput, &newLine);

		if (!(newLine == '\n'))
		{
			validValue = 0;

			clearInputBuffer();
			printf("Error! Input a whole number: ");
		}

		else if (numberInput < minNumber || numberInput > maxNumber)
		{
			validValue = 0;

			printf("ERROR! Value must be between %d and %d inclusive: ", minNumber, maxNumber);
		}

	} while (!validValue);

	return numberInput;
}

// Function for Input Character
char inputCharOption(char str[])
{
	int i, count, validValue;
	char letter;

	do
	{
		validValue = 1;
		count = 0;

		scanf(" %c", &letter);
		clearInputBuffer();

		for (i = 0; str[i] != '\0'; i++)
		{
			if (letter == str[i])
			{
				count++;
			}

		}
		if (count == 0)
		{
			validValue = 0;

			printf("ERROR: Character must be one of [%s]: ", str);
		}

	} while (!validValue);

	return letter;
}

// Function for Input Character String
void inputCString(char* cStringValue, int minLength, int maxLength)
{
	int i, validValue, count = 0;
	char sixCString[1000 + 1] = { 0 };

	do
	{
		validValue = 1;

		scanf("%[^\n]", sixCString);
		clearInputBuffer();

		for (i = 0; sixCString[i] != '\0'; i++)
		{
			count++;
		}

		if (count < minLength || count > maxLength)
		{
			validValue = 0;
			if (maxLength == minLength)
			{
				printf("ERROR: String length must be exactly %d chars: ", minLength);
			}
			else if (count > maxLength)
			{

				printf("ERROR: String length must be no more than %d chars: ", maxLength);
			}
			else if (count < minLength)
			{
				printf("ERROR: String length must be between %d and %d chars: ", minLength, maxLength);
			}
			count = 0;
		}
		else
		{
			validValue = 1;
		}

	} while (!validValue);

	for (i = 0; i <= count; i++)
	{
		cStringValue[i] = sixCString[i];
	}

}

//Functions for Display Phone Number
void displayFormattedPhone(const char* phoneNum)
{
	int i, count = 0;

	for (i = 0; (phoneNum != NULL) && (phoneNum != '\0') && ('0' <= phoneNum[i]) && (phoneNum[i] <= '9'); i++)
	{
		count++;
	}

	if (count == 10)
	{
		printf("%c", '(');
		for (i = 0; i < 3; i++)
		{
			printf("%c", phoneNum[i]);
		}
		printf("%c", ')');

		for (i = 3; i < 6; i++)
		{
			printf("%c", phoneNum[i]);
		}
		printf("%c", '-');
		for (i = 6; i < 10; i++)
		{
			printf("%c", phoneNum[i]);
		}
	}
	else
	{
		printf("(___)___-____");
	}

}


// Clear the standard input buffer
void clearInputBuffer(void)
{
	// Discard all remaining char's from the standard input buffer:
	while (getchar() != '\n')
	{
		; // do nothing! 
	}
}
// Wait for user to input the "enter" key to continue 
void suspend(void)
{
	printf("<ENTER> to continue..."); clearInputBuffer(); putchar('\n');
}