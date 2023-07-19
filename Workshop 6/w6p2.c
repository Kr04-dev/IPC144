/*/////////////////////////////////////////////////////////////////////////
                      Workshop - #6 (P2)
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

int main(void) {

    const double minCost = 100.00;
    int wishList, i, priority[MAX_ITEMS] = { 0 }, forecast, year, month, placeholder, priority_input, priority_sum_1 = 0, priority_sum_2 = 0, priority_sum_3 = 0;
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
    printf("\n");

    for (i = 0; i < wishList; i++) {

        printf("Item-%d Details:\n", i + 1);
        do {
            printf("   Item cost: $");
            scanf(" %lf", &itemPrice[i]);

            if (itemPrice[i] < minCost) {
                printf("      ERROR: Cost must be at least $%.2f\n", minCost);
            }

        } while (!(itemPrice[i] > minCost));
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
        printf("\n");
    }

    printf("Item Priority Financed        Cost\n");
    printf("---- -------- -------- -----------\n");
    for (i = 0; i < wishList; i++) {
        printf("%3d  %5d    %5c    %11.2lf\n", i + 1, priority[i], finance[i], itemPrice[i]);
    }
    printf("---- -------- -------- -----------\n");
    printf("                      $ %.2lf\n\n", totalSum);

    do {
        printf("How do you want to forecast your wish list?\n");
        printf(" 1. All items (no filter)\n");
        printf(" 2. By priority\n");
        printf(" 0. Quit/Exit\n");
        printf("Selection: ");
        scanf(" %d", &forecast);

        if (forecast < 0 || forecast > 2) {
            printf("\n");
            printf("ERROR: Invalid menu selection.\n\n");
        }
        if (forecast = 1) {
            year = totalSum / 12 / income;
            month = (int)(totalSum / income) % 12;
            if ((totalSum / income) - (int)(totalSum / income) > 0) {
                month += 1;
            }
            printf("\n");
            printf("====================================================\n");
            printf("Filter:   All items\n");
            printf("Amount:   $%.2lf\n", totalSum);
            printf("Forecast: %d years, %d months\n", year, month);
            for (i = 0; i < finance[i]; i++)
            {
                if (finance[i] == 'y')
                {
                    placeholder = 1;
                }
            }
            if (placeholder == 1){
                printf("NOTE: Financing options are available on some items.\n");
                printf("      You can likely reduce the estimated months.\n");
                placeholder = 0;
            }
            printf("====================================================\n\n");
        }
        if (forecast = 2) {
            printf("\n");
            printf("What priority do you want to filter by? [1-3]: ");
            scanf(" %d", &priority_input);
            if (priority_input == 1) {
                year = priority_sum_1 / income / 12;
                month = (int)(priority_sum_1 / income) % 12;
                if ((priority_sum_1 / income) - (int)(priority_sum_1 / income) > 0) {
                    month = month + 1;
                }
                printf("\n====================================================\n");
                printf("Filter:   by priority (1)\n");
                printf("Amount:   $%1.2lf\n", (double)priority_sum_1);
                printf("Forecast: %d years, %d months\n", year, month);

                for (i = 0; i < finance[i]; i++) {
                    if (priority[i] == 1 && finance[i] == 'y') {
                        placeholder = 1;
                    }
                }

                if (placeholder== 1) {
                    printf("NOTE: Financing options are available on some items.\n");
                    printf("      You can likely reduce the estimated months.\n");
                }
                printf("====================================================\n\n");
            }
            if (priority_input == 1) {
                year = (int)priority_sum_1 / income / 12;
                month = (int)(priority_sum_1 / income) % 12;
                if ((priority_sum_1 / income) - (int)(priority_sum_1 / income) > 0) {
                    month = month + 1;
                }
                printf("\n====================================================\n");
                printf("Filter:   by priority (1)\n");
                printf("Amount:   $%1.2lf\n", (double)priority_sum_1);
                printf("Forecast: %d years, %d months\n", year, month);

                for (i = 0; i < finance[i]; i++) {
                    if (priority[i] == 1 && finance[i] == 'y') {
                        placeholder = 1;
                    }
                }

                if (placeholder == 1) {
                    printf("NOTE: Financing options are available on some items.\n");
                    printf("      You can likely reduce the estimated months.\n");
                }
                printf("====================================================\n\n");
            }
            if (priority_input == 2) {
                year = priority_sum_2 / income / 12;
                month = (int)(priority_sum_2 / income) % 12;
                if ((priority_sum_2 / income) - (int)(priority_sum_2 / income) > 0) {
                    month = month + 1;
                }
                printf("\n====================================================\n");
                printf("Filter:   by priority (2)\n");
                printf("Amount:   $%1.2lf\n", (float)priority_sum_2);
                printf("Forecast: %d years, %d months\n", year, month);

                for (i = 0; i < finance[i]; i++) {
                    if (priority[i] == 1 && finance[i] == 'y') {
                        placeholder = 1;
                    }
                }

                if (placeholder == 1) {
                    printf("NOTE: Financing options are available on some items.\n");
                    printf("      You can likely reduce the estimated months.\n");
                }
                printf("====================================================\n\n");
            }
            if (priority_input == 3) {
                year = priority_sum_3 / income / 12;
                month = (int)(priority_sum_3 / income) % 12;
                if ((priority_sum_3 / income) - (int)(priority_sum_3 / income) > 0) {
                    month = month + 1;
                }
                printf("\n====================================================\n");
                printf("Filter:   by priority (3)\n");
                printf("Amount:   $%1.2lf\n", (float)priority_sum_3);
                printf("Forecast: %d years, %d months\n", year, month);

                for (i = 0; i < finance[i]; i++) {
                    if (priority[i] == 1 && finance[i] == 'y') {
                        placeholder = 1;
                    }
                }

                if (placeholder == 1) {
                    printf("NOTE: Financing options are available on some items.\n");
                    printf("      You can likely reduce the estimated months.\n");
                }
                printf("====================================================\n\n");
            }

        }
    } while (!(forecast == 0));
    
    printf("\n");
    printf("Best of luck in all your future endeavours!\n");

    return 0;
}