/*/////////////////////////////////////////////////////////////////////////
                        Assignment 1 - Milestone 3
Full Name  : Timothy LEe
Student ID#: 177133212
Email      : glee89@myseneca.ca
Section    : IPC144NRA

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include "core.h"

//////////////////////////////////////
// USER INTERFACE FUNCTIONS
//////////////////////////////////////

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
	printf("<ENTER> to continue...");
	clearInputBuffer();
	putchar('\n');
}


//////////////////////////////////////
// USER INPUT FUNCTIONS
//////////////////////////////////////

//
// Copy your work done from Milestone #2 (core.c) into this file
// - Organize your functions in the same order as they are listed in the core.h file
//



//////////////////////////////////////
// UTILITY FUNCTIONS
//////////////////////////////////////
int inputInt(void) {

	int val = 0;
	char val2 = '\0';

	do {
		scanf("%d%c", &val, &val2);
		if (val2 != '\n') {
			clearInputBuffer();
			printf("Error! Input a whole number: ");
			val = 0;
			val2 = '\0';
		}

	} while (val2 != '\n');

	return val;
}

int inputIntPositive(void) {

	int val = 0;

	do
	{
		val = inputInt();
		if (!(val > 0)) {
			printf("ERROR! Value must be > 0: ");
			val = 0;
		}
	} while (!(val > 0));

	return val;
}


int inputIntRange(int minB, int maxB) {

	int val = 0;
	int checkInt = 1;

	while (checkInt)
	{
		val = inputInt();
		if (!(val >= minB && val <= maxB)) {
			printf("ERROR! Value must be between %d and %d inclusive: ", minB, maxB);
		}
		else {
			checkInt = 0;
		}
	};

	return val;
}

char inputCharOption(const char str[]) {

	char ch = '\0';
	char charStr[10] = { 0 };
	int checkChar = 0;
	int i;
	do
	{
		//scanf(" %c", &ch);
		//clearInputBuffer();
		scanf("%[^\n]", charStr);
		clearInputBuffer();

		if (strlen(charStr) == 1) {
			for (i = 0; checkChar == 0 && str[i] != '\0'; i++) {
				if (str[i] == charStr[0]) {
					checkChar = 1;
					ch = charStr[0];
				}
			}
		}

		if (!checkChar) {
			printf("ERROR: Character must be one of [%s]: ", str);
		}

	} while (!checkChar);

	return ch;
}


void inputCString(char* str, int min, int max) {

	int checkStr = 0;
	char cStr[30];

	do
	{
		//scanf("%[^\n]", str);
		scanf("%[^\n]", cStr);

		if (strlen(cStr) >= min && strlen(cStr) <= max) {
			checkStr = 1;
		}

		if (!checkStr) {
			if (min == max) {
				printf("ERROR: String length must be exactly %d chars: ", min);
			}
			else if (strlen(cStr) > max) {
				printf("ERROR: String length must be no more than %d chars: ", max);
			}
			else {
				printf("ERROR: String length must be between %d and %d chars: ", min, max);
			}
		}
		clearInputBuffer();

	} while (!checkStr);

	strcpy(str, cStr);

	putchar('\n');
}


void inputCStringNum(char* str, int min, int max) {

	int checkStr = 0;
	char cStr[30];
	do
	{
		scanf("%[^\n]", cStr);

		if (strlen(cStr) >= min && strlen(cStr) <= max) {
			checkStr = 1;
		}

		if (!checkStr) {
			if (min == max) {
				printf("Invalid %d-digit number! Number: ", min);
			}
			else if (strlen(cStr) > max) {
				printf("ERROR: String length must be no more than %d chars: ", max);
			}
			else {
				printf("ERROR: String length must be between %d and %d chars: ", min, max);
			}
		}
		clearInputBuffer();


	} while (!checkStr);
	strcpy(str, cStr);

	putchar('\n');
}

void displayFormattedPhone(const char* carr) {

	int i = 0, j = 0, flag = 0;

	if (carr != NULL) {
		i = strlen(carr);
	}

	for (j = 0; j < i; j++) {
		if (!(carr[j] >= '0' && carr[j] <= '9')) {
			flag = 1;
		}
	}

	if (carr == NULL || flag == 1 || i != 10) {
		printf("(___)___-____");
	}
	else {
		printf("(");
		for (i = 0; i < 3; i++) {
			printf("%c", carr[i]);
		}
		printf(")");
		for (i = 3; i < 6; i++) {
			printf("%c", carr[i]);
		}
		printf("-");
		for (i = 6; i < 10; i++) {
			printf("%c", carr[i]);
		}
	}
}