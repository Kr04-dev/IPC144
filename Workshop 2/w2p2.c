/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #2 (P2)
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

int main(void) {

    int numShirtPat, numShirtSal, numShirtTom, totalPat, totalSal, totalTom, sub_totalPat, sub_totalSal, sub_totalTom, taxPricePat, taxPriceTom, taxPriceSal, toonie_cal, loonie_cal, quarters_cal, dimes_cal, nickels_cal, pennies_cal;
    double pS, pM, pL, coin_cal, sub_totalD, totalD, taxPriceD;
    char pat, sal, tom;

    const double TAX = 0.13;

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
    printf("SMALL  : $%.2lf\n", pS);
    printf("MEDIUM : $%.2lf\n", pM);
    printf("LARGE  : $%.2lf\n", pL);
    printf("\n");

    printf("Patty's shirt size is 'S'\n");
    pat = 'S';
    printf("Number of shirts Patty is buying: ");
    scanf("%d", &numShirtPat);
    sub_totalPat = (pS * numShirtPat + 0.005) * 100;
    taxPricePat = (sub_totalPat * TAX) + 0.5;
    totalPat = sub_totalPat + taxPricePat;
    printf("\n");

    printf("Tommy's shirt size is 'L'\n");
    tom = 'L';
    printf("Number of shirts Tommy is buying: ");
    scanf("%d", &numShirtTom);
    sub_totalTom = (pL * numShirtTom + 0.005) * 100;
    taxPriceTom = (sub_totalTom * TAX) + 0.5;
    totalTom = sub_totalTom + taxPriceTom;
    printf("\n");

    printf("Sally's shirt size is 'M'\n");
    sal = 'M';
    printf("Number of shirts Sally is buying: ");
    scanf("%d", &numShirtSal);
    sub_totalSal = (pM * numShirtSal + 0.005) * 100;
    taxPriceSal = (sub_totalSal * TAX) + 0.5;
    totalSal = sub_totalSal + taxPriceSal;
    printf("\n");

    printf("Customer Size Price Qty Sub-Total       Tax     Total\n");
    printf("-------- ---- ----- --- --------- --------- ---------\n");
    printf("Patty    %-4c %5.2lf %3d %9.4lf %9.4lf %9.4lf\n", pat, pS, numShirtPat, sub_totalPat / 100.0, taxPricePat / 100.0, totalPat / 100.0);
    printf("Sally    %-4c %5.2lf %3d %9.4lf %9.4lf %9.4lf\n", sal, pM, numShirtSal, sub_totalSal / 100.0, taxPriceSal / 100.0, totalSal / 100.0);
    printf("Tommy    %-4c %5.2lf %3d %9.4lf %9.4lf %9.4lf\n", tom, pL, numShirtTom, sub_totalTom / 100.0, taxPriceTom / 100.0, totalTom / 100.0);
    printf("-------- ---- ----- --- --------- --------- ---------\n");
    sub_totalD = sub_totalPat + sub_totalSal + sub_totalTom;
    taxPriceD = taxPricePat + taxPriceSal + taxPriceTom;
    totalD = totalPat + totalSal + totalTom;
    printf("%33.4lf %9.4lf %9.4lf\n\n", sub_totalD / 100, taxPriceD / 100, totalD / 100);

    printf("Daily retail sales represented by coins\n");
    printf("=======================================\n\n");
    printf("Sales EXCLUDING tax\n");
    printf("Coin     Qty   Balance\n");
    printf("-------- --- ---------\n");
    printf("%22.4lf\n", sub_totalD / 100);
    coin_cal = sub_totalD;

    toonie_cal = coin_cal / 200;
    coin_cal -= toonie_cal * 200;
    printf("Toonies %4d %9.4lf\n", toonie_cal, coin_cal / 100);
    loonie_cal = coin_cal / 100;
    coin_cal -= loonie_cal * 100;
    printf("Loonies %4d %9.4lf\n", loonie_cal, coin_cal / 100);
    quarters_cal = coin_cal / 25;
    coin_cal -= quarters_cal * 25;
    printf("Quarters %3d %9.4lf\n", quarters_cal, coin_cal / 100);
    dimes_cal = coin_cal / 10;
    coin_cal -= dimes_cal * 10;
    printf("Dimes %6d %9.4lf\n", dimes_cal, coin_cal / 100);
    nickels_cal = coin_cal / 5;
    coin_cal -= nickels_cal * 5;
    printf("Nickels %4d %9.4lf\n", nickels_cal, coin_cal / 100);
    pennies_cal = coin_cal / 1;
    coin_cal -= pennies_cal * 1;
    printf("Pennies %4d %9.4lf\n\n", pennies_cal, coin_cal / 100);

    printf("Average cost/shirt: $%.4lf\n\n", (sub_totalD / (numShirtPat + numShirtSal + numShirtTom)) / 100);

    printf("Sales INCLUDING tax\n");
    printf("Coin     Qty   Balance\n");
    printf("-------- --- ---------\n");
    printf("%22.4lf\n", totalD / 100);
    coin_cal = totalD;

    toonie_cal = coin_cal / 200;
    coin_cal -= toonie_cal * 200;
    printf("Toonies %4d %9.4lf\n", toonie_cal, coin_cal / 100);
    loonie_cal = coin_cal / 100;
    coin_cal -= loonie_cal * 100;
    printf("Loonies %4d %9.4lf\n", loonie_cal, coin_cal / 100);
    quarters_cal = coin_cal / 25;
    coin_cal -= quarters_cal * 25;
    printf("Quarters %3d %9.4lf\n", quarters_cal, coin_cal / 100);
    dimes_cal = coin_cal / 10;
    coin_cal -= dimes_cal * 10;
    printf("Dimes %6d %9.4lf\n", dimes_cal, coin_cal / 100);
    nickels_cal = coin_cal / 5;
    coin_cal -= nickels_cal * 5;
    printf("Nickels %4d %9.4lf\n", nickels_cal, coin_cal / 100);
    pennies_cal = coin_cal / 1;
    coin_cal -= pennies_cal * 1;
    printf("Pennies %4d %9.4lf\n\n", pennies_cal, coin_cal / 1);
    printf("Average cost/shirt: $%.4lf\n", (totalD / (numShirtPat + numShirtSal + numShirtTom)) / 100);

    return 0;
}