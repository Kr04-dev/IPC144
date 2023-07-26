#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include "core.h"


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

int inputIntPositive(void)
{
	int positiveNumber, validValue;

	do{
		scanf("%d", &positiveNumber);
		validValue = 1;
		if (positiveNumber <= 0){
			validValue = 0;
			printf("ERROR! Value must be > 0: ");
		}

	} while (!validValue);

	return positiveNumber;
}

int inputIntRange(int minNumber, int maxNumber)
{
	int numberInput, validValue;
	char newLine = 'X';

	do{
		validValue = 1;
		scanf("%d%c", &numberInput, &newLine);

		if (!(newLine == '\n')){
			
			validValue = 0;

			clearInputBuffer();
			printf("Error! Input a whole number: ");
		
		} else if (numberInput < minNumber || numberInput > maxNumber) {
			validValue = 0;

			printf("ERROR! Value must be between %d and %d inclusive: ", minNumber, maxNumber);
		}

	} while (!validValue);

	return numberInput;
}

char inputCharOption(char str[]){
		
	int i, count, validValue;
	char letter;

	do{
		validValue = 1;
		count = 0;

		scanf(" %c", &letter);
		clearInputBuffer();

		for (i = 0; str[i] != '\0'; i++) {
			if (letter == str[i]){
				count++;
			}

		}
		if (count == 0) {
			validValue = 0;

			printf("ERROR: Character must be one of [%s]: ", str);
		}

	} while (!validValue);

	return letter;
}

void inputCString(char* cStringValue, int minLength, int maxLength){

	int i, validValue, count = 0;
	char sixCString[1000 + 1] = { 0 };

	do {
		validValue = 1;

		scanf("%[^\n]", sixCString);
		clearInputBuffer();

		for (i = 0; sixCString[i] != '\0'; i++){
			count++;
		}

		if (count < minLength || count > maxLength){
			validValue = 0;
			if (maxLength == minLength){
				printf("ERROR: String length must be exactly %d chars: ", minLength);
			} else if (count > maxLength){

				printf("ERROR: String length must be no more than %d chars: ", maxLength);
			} else if (count < minLength){
				printf("ERROR: String length must be between %d and %d chars: ", minLength, maxLength);
			}
			count = 0;
		}else{
			validValue = 1;
		}

	} while (!validValue);

	for (i = 0; i <= count; i++) {
		cStringValue[i] = sixCString[i];
	}

}

void displayFormattedPhone(const char* phoneNum)
{
	int i, count = 0;

	for (i = 0; (phoneNum != NULL) && (phoneNum != '\0') && ('0' <= phoneNum[i]) && (phoneNum[i] <= '9'); i++) {
		count++;
	}

	if (count == 10) {
		printf("%c", '(');
		for (i = 0; i < 3; i++) {
			printf("%c", phoneNum[i]);
		}
		printf("%c", ')');

		for (i = 3; i < 6; i++) {
			printf("%c", phoneNum[i]);
		}
		printf("%c", '-');
		for (i = 6; i < 10; i++) {
			printf("%c", phoneNum[i]);
		}
	}else {
		printf("(___)___-____");
	}

}

void clearInputBuffer(void)
{
	while (getchar() != '\n'){
		//nothing
	}
}

void suspend(void){
	printf("<ENTER> to continue..."); clearInputBuffer(); putchar('\n');
}