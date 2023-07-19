/*/////////////////////////////////////////////////////////////////////////
						  Workshop - #8 (P1)
Full Name  : Timothy Lee
Student ID#: 177133212
Email      : glee89@myseneca.ca
Section    : IPC144NRA
Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/

#define _CRT_SECURE_NO_WARNINGS

// System Libraries
#include <stdio.h>

// User Libraries
#include "w8p1.h"

// 1. Get user input of int type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
int getIntPositive(int* intNumber) {
	int intInput;
	do {
		scanf("%d", &intInput);

		if (intInput <= 0) {
			printf("ERROR: Enter a positive value: ");
		}

	} while (intInput <= 0);

	if (intNumber != NULL) {
		*intNumber = intInput;
	}
	return intInput;
}

// 2. Get user input of double type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
double getDoublePositive(double* floatNumber)
{
	double float_input;

	do {// loop for ERROR message
		scanf(" %lf", &float_input);
		if (float_input <= 0){
			printf("ERROR: Enter a positive value: ");
		}
	} while (float_input <= 0);

	if (floatNumber != NULL) {
		*floatNumber = float_input;
	}
	return float_input;
}

// 3. Opening Message (include the number of products that need entering)
void openingMessage(const int product, const int gram) {
	printf("Cat Food Cost Analysis\n");
	printf("======================\n\n");
	printf("Enter the details for %d dry food bags of product data for analysis.\n", product);
	printf("NOTE: A 'serving' is %dg\n", gram);
	printf("\n");
}

// 4. Get user input for the details of cat food product
struct catFoodInfo getCatFoodInfo(const int productCount) {
	struct catFoodInfo info = { 0 };

	printf("Cat Food Product #%d\n", productCount);
	printf("--------------------\n");

	printf("SKU           : ");
	getIntPositive(&info.sku);

	printf("PRICE         : $");
	getDoublePositive(&info.price);

	printf("WEIGHT (LBS)  : ");
	getDoublePositive(&info.weight);

	printf("CALORIES/SERV.: ");
	getIntPositive(&info.calories);

	putchar('\n');

	return info;
}

// 5. Display the formatted table header
void displayCatFoodHeader(void) {
	printf("SKU         $Price    Bag-lbs Cal/Serv\n");
	printf("------- ---------- ---------- --------\n");
}

// 6. Display a formatted record of cat food data
void displayCatFoodData(const int sku, const double* price, const double* weight, const int calories) {
	printf("%07d %10.2lf %10.1lf %8d\n", sku, *price, *weight, calories);
}

// 7. Logic entry point
void start(void) {
	int i;
	openingMessage(MAX_PRODUCT, SUGGEST_GRAM);
	struct catFoodInfo CatFoodData[MAX_PRODUCT];

	for (i = 0; i < MAX_PRODUCT; i++) {
		CatFoodData[i] = getCatFoodInfo(i + 1);
	}
	displayCatFoodHeader();

	for (i = 0; i < MAX_PRODUCT; i++){
		displayCatFoodData(CatFoodData[i].sku, &CatFoodData[i].price, &CatFoodData[i].weight, CatFoodData[i].calories);
	}
}