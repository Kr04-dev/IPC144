/*/////////////////////////////////////////////////////////////////////////
						  Workshop - #8 (P2)
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

#include <stdio.h>
#include "w8p2.h"

// ----------------------------------------------------------------------------
// PART-1

// 1. Get user input of int type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
int getIntPositive(int* intNumber) {

	int intInput;
	do {
		scanf(" %d", &intInput); 
		if (intInput <= 0) {
			printf("ERROR: Enter a positive value: ");
		}
	} while (intInput <= 0);

	if (intNumber != NULL){
		*intNumber = intInput;
	}
	return intInput;
}

// 2. Get user input of double type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
double getDoublePositive(double* floatNumber)
{
	double floatInput;

	do {
		scanf("%lf", &floatInput);
		if (floatInput <= 0) {
			printf("ERROR: Enter a positive value: ");
		}
	} while (floatInput <= 0);

	if (floatNumber != NULL) {
		*floatNumber = floatInput;
	}
	return floatInput;
}

// 3. Opening Message (include the number of products that need entering)
void openingMessage(const int maxproduct, const int gram)
{
	printf("Cat Food Cost Analysis\n"
		"======================\n\n");
	printf("Enter the details for %d dry food bags of product data for analysis.\n"
		"NOTE: A 'serving' is %dg\n", MAX_PRODUCT, SUGGEST_GRAM);
	printf("\n");
}

// 4. Get user input for the details of cat food product
struct catFoodInfo getCatFoodInfo(const int productCount){

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

	printf("\n");
	return info;
}

// 5. Display the formatted table header
void displayCatFoodHeader(void) {
	printf("SKU         $Price    Bag-lbs Cal/Serv\n");
	printf("------- ---------- ---------- --------\n");
}

// 6. Display a formatted record of cat food data
void displayCatFoodData(int sku, const double price, const double weight, int calories) {

	printf("%07d %10.2lf %10.1lf %8d\n", sku, price, weight, calories);
}


// ----------------------------------------------------------------------------
// PART-2

// 8. convert lbs: kg (divide by 2.20462)
double convertLbsKg(const double* weightLbs, double* lbsToKg) {
	double resultToKg = *weightLbs / LBS_TO_KG;

	if (lbsToKg != NULL) {
		*lbsToKg = resultToKg;
	}

	return resultToKg;

}

// 9. convert lbs: g (call convertKG, then * 1000)
int convertLbsG(const double* weightLbs, int* lbsToG) {
	int resultToGram = *weightLbs / LBS_TO_KG * 1000;

	if (lbsToG != NULL) {
		*lbsToG = resultToGram;
	}
	return resultToGram;
}

// 10. convert lbs: kg and g
void convertLbs(const double* weightLbs, double* lbsToKg, int* lbsToG) {
	double resultToKg = *weightLbs / LBS_TO_KG;
	int resultToGram = *weightLbs / LBS_TO_KG * 1000;

	if (lbsToKg != NULL && lbsToG != NULL) {
		*lbsToKg = resultToKg;
		*lbsToG = resultToGram;
	}
}

// 11. calculate: servings based on gPerServ
double calculateServings(const int suggestGram, const int totalGram, double* totalServing)
{
	double servings = ((double)totalGram) / suggestGram;

	if (totalServing != NULL)
	{
		*totalServing = servings;
	}
	return servings;
}


// 12. calculate: cost per serving
double calcultaeCostPerServing(const double price, const double serving, double* costServeResult) {
	double costPerServing = price / serving;

	if (costServeResult != NULL){
		*costServeResult = costPerServing;
	}

	return costPerServing;
}


// 13. calculate: cost per calorie
double calculateCostPerCal(const double price, const double calorie, const double serving, double* costCalorieResult)
{
	double costPerCalorie = price / calorie / serving;

	if (costCalorieResult != NULL)
	{
		*costCalorieResult = costPerCalorie;
	}

	return costPerCalorie;
}


// 14. Derive a reporting detail record based on the cat food product data
struct report calculateReportData(const struct catFoodInfo productInfo) {
	struct report report_data = { 0 };

	report_data.sku = productInfo.sku;
	report_data.price = productInfo.price;
	report_data.lbsWeight = productInfo.weight;
	report_data.calories = productInfo.calories;

	report_data.kgWeight = convertLbsKg(&report_data.lbsWeight, &report_data.kgWeight);
	report_data.gramWeight = convertLbsG(&report_data.lbsWeight, &report_data.gramWeight);
	report_data.serving = calculateServings(SUGGEST_GRAM, report_data.gramWeight, &report_data.serving);
	report_data.servingCost = calcultaeCostPerServing(report_data.price, report_data.serving, &report_data.servingCost);
	report_data.caloriesCost = calculateCostPerCal(report_data.price, report_data.calories, report_data.serving, &report_data.caloriesCost);

	return report_data;
}

void displayReportHeader(void)
{
	printf("Analysis Report (Note: Serving = %dg)\n", SUGGEST_GRAM);
	printf("---------------\n");
	printf("SKU         $Price    Bag-lbs     Bag-kg     Bag-g Cal/Serv Servings  $/Serv   $/Cal\n");
	printf("------- ---------- ---------- ---------- --------- -------- -------- ------- -------\n");
}

void displayReportData(struct report report)
{
	printf("%07d %10.2lf %10.1lf %10.4lf %9d %8d %8.1lf %7.2lf %7.5lf", report.sku, report.price, report.lbsWeight, report.kgWeight, report.gramWeight, report.calories, report.serving, report.servingCost, report.caloriesCost);
}

void displayFinalAnalysis(const struct report report){

	printf("Final Analysis\n"
		"--------------\n");
	printf("Based on the comparison data, the PURRR-fect economical option is:\n"
		"SKU:%07d Price: $%.2lf\n", report.sku, report.price);
	printf("\n");
	printf("Happy shopping!\n");
}

// ----------------------------------------------------------------------------
// 7. Logic entry point
void start(void){

	int i;
	struct catFoodInfo catFoodInfo[MAX_PRODUCT] = { { 0 } };
	struct report report_data[MAX_PRODUCT] = { {0} };

	double cheapestCost;

	openingMessage(MAX_PRODUCT, SUGGEST_GRAM);

	for (i = 0; i < MAX_PRODUCT; i++){
		catFoodInfo[i] = getCatFoodInfo(i + 1);
		report_data[i] = calculateReportData(catFoodInfo[i]);
	}

	displayCatFoodHeader();

	for (i = 0; i < MAX_PRODUCT; i++) {
		displayCatFoodData(catFoodInfo[i].sku, catFoodInfo[i].price, catFoodInfo[i].weight, catFoodInfo[i].calories);
	}
	printf("\n");

	displayReportHeader();

	cheapestCost = report_data[0].servingCost;
	for (i = 0; i < MAX_PRODUCT; i++) {
		if (report_data[i].servingCost < cheapestCost){
			cheapestCost = report_data[i].servingCost;
			cheapestCost = i;
		}
	}

	for (i = 0; i < MAX_PRODUCT; i++){
		displayReportData(report_data[i]);

		if (cheapestCost == i){
			printf(" ***\n");
		}
		else
		{
			printf("\n");
		}
	}
	printf("\n");

	for (i = 0; i < MAX_PRODUCT; i++){
		if (i == cheapestCost){
			displayFinalAnalysis(report_data[i]);
		}

	}

}