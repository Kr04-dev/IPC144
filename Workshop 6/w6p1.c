/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #6 (P1)
Full Name  :Timothy Lee
Student ID#:177133212
Email      :glee89@myseneca.ca
Section    :NRA
Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MIN_INCOME 500.00
#define MAX_INCOME 400000.00
#define MIN_ITEMS 1
#define MAX_ITEMS 10
#define ITEMS 3

int main(void) {

    const double minCost = 100.00;
    int wishList, i, priority[MAX_ITEMS] = { 0 };
    double income, totalSum = 0, itemPrice[MAX_ITEMS] = { 0 };
    char finance[MAX_ITEMS] = { 0 };

    printf("+--------------------------+\n");
    printf("+   Wish List Forecaster   |\n");
    printf("+--------------------------+\n\n");

    do {
        printf("Enter your monthly NET income: $");
        scanf(" %lf", &income);
        if (income < MIN_INCOME) {
            printf("ERROR: You must have a consistent monthly income of at least $%.2lf\n", MIN_INCOME);
        }
        if (income > MAX_INCOME) {
            printf("ERROR: Liar! I'll believe you if you enter a value no more than $%.2lf\n", MAX_INCOME);
        }
        putchar('\n');
    } while (income < MIN_INCOME || income > MAX_INCOME);

    do {
        printf("How many wish list items do you want to forecast?: ");
        scanf(" %d", &wishList);
        if (wishList < MIN_ITEMS || wishList > MAX_ITEMS) {
            printf("ERROR: List is restricted to between 1 and 10 items.\n\n");
        }
    } while (wishList < MIN_ITEMS || wishList > MAX_ITEMS);
    putchar('\n');

    for (i = 0; i < ITEMS; i++) {
        printf("Item-%d Details:\n", i + 1);
        do {
            printf("   Item cost: $");
            scanf(" %lf", &itemPrice[i]);
            if (itemPrice[i] < minCost) {
                printf("      ERROR: Cost must be at least $%.2f\n", minCost);
            }
        } while (itemPrice[i] < minCost);

        totalSum += itemPrice[i];

        do {
            printf("   How important is it to you? [1=must have, 2=important, 3=want]: ");
            scanf(" %d", &priority[i]);
            if (priority[i] < 1 || priority[i] > 3) {
                printf("      ERROR: Value must be between 1 and 3\n");
            }
        } while (priority[i] < 1 || priority[i] > 3);

        do {
            printf("   Does this item have financing options? [y/n]: ");
            scanf(" %c", &finance[i]);
            if (!(finance[i] == 'y' || finance[i] == 'n')) {
                printf("      ERROR: Must be a lowercase 'y' or 'n'\n");
            }
        } while (!(finance[i] == 'y' || finance[i] == 'n'));
        putchar('\n');
    }

    printf("Item Priority Financed        Cost\n");
    printf("---- -------- -------- -----------\n");

    for (i = 0; i < ITEMS; i++) {
        printf("%3d  %5d    %5c    %11.2lf\n", i + 1, priority[i], finance[i], itemPrice[i]);
    }
    printf("---- -------- -------- -----------\n");
    printf("                      $ %.2lf\n\n", totalSum);
    printf("Best of luck in all your future endeavours!\n\n");

    return 0;
}