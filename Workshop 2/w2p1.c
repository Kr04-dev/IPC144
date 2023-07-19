/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #2 (P1)
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

int main(void)
{

    int numShirt, total, sub_total, taxPrice;
    double pS, pM, pL;

    const double TAX = 0.13;
    const char patSize = 'S';

    printf("Set Shirt Prices\n");
    printf("================\n");
    printf("Enter the price for a SMALL shirt: $");
    scanf("%lf", &pS);
    printf("Enter the price for a MEDIUM shirt: $");
    scanf("%lf", &pM);
    printf("Enter the price for a LARGE shirt: $");
    scanf("%lf", &pL);
    printf("\n");

    printf("Shirt Store Price List\n");
    printf("======================\n");
    printf("SMALL  : $%.2f\n", pS);
    printf("MEDIUM : $%.2f\n", pM);
    printf("LARGE  : $%.2f\n", pL);
    printf("\n");
    printf("Patty's shirt size is '%c'\n", patSize);
    printf("Number of shirts Patty is buying: ");
    scanf("%d", &numShirt);
    printf("\n");
    printf("Patty's shopping cart...\n");
    printf("Contains : %d shirts\n", numShirt);


    sub_total = (pS * numShirt) * 100;
    printf("Sub-total: $%8.4lf\n", (sub_total / 100.0));
    taxPrice = (sub_total * TAX) + 0.5;
    printf("Taxes    : $%8.4lf\n", (taxPrice / 100.0));
    total = sub_total + taxPrice;
    printf("Total    : $%8.4lf\n", (total / 100.0));

    return 0;
}
