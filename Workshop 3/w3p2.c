/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #3 (P2)
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


int main() {

    const double GRAMS_IN_LBS = 453.5924;

    char coffee1, coffee2, coffee3;
    char coffee_with_cream1, coffee_with_cream2, coffee_with_cream3;
    int  coffee1L = 0, coffee1M = 0, coffee1R = 0, coffee_with_cream_cal1 = 0;
    int  coffee2L = 0, coffee2M = 0, coffee2R = 0, coffee_with_cream_cal2 = 0;
    int  coffee3L = 0, coffee3M = 0, coffee3R = 0, coffee_with_cream_cal3 = 0;
    int coffee_by_weight_1 = 0, coffee_by_weight_2 = 0, coffee_by_weight_3 = 0;
    int coffee_servings_input_1 = 0;
    double coffee_g1, coffee_g2, coffee_g3;


    printf("Take a Break - Coffee Shop\n");
    printf("==========================\n\n");

    printf("Enter the coffee product information being sold today...\n\n");

    printf("COFFEE-1...\n");
    printf("Type ([L]ight,[M]edium,[R]ich): ");
    scanf(" %c", &coffee1);
    coffee1L = ((coffee1 == 'L') || (coffee1 == 'l')) ? 1 : 0;
    coffee1M = ((coffee1 == 'M') || (coffee1 == 'm')) ? 1 : 0;
    coffee1R = ((coffee1 == 'R') || (coffee1 == 'r')) ? 1 : 0;
    printf("Bag weight (g): ");
    scanf(" %lf", &coffee_g1);
    printf("Best served with cream ([Y]es,[N]o): ");
    scanf(" %c", &coffee_with_cream1);
    coffee_with_cream_cal1 = ((coffee_with_cream1 == 'Y') || (coffee_with_cream1 == 'y')) ? 1 : 0;

    printf("\nCOFFEE-2...\n");
    printf("Type ([L]ight,[M]edium,[R]ich): ");
    scanf(" %c", &coffee2);
    coffee2L = ((coffee2 == 'L') || (coffee2 == 'l')) ? 1 : 0;
    coffee2M = ((coffee2 == 'M') || (coffee2 == 'm')) ? 1 : 0;
    coffee2R = ((coffee2 == 'R') || (coffee2 == 'r')) ? 1 : 0;

    printf("Bag weight (g): ");
    scanf(" %lf", &coffee_g2);
    printf("Best served with cream ([Y]es,[N]o): ");
    scanf(" %c", &coffee_with_cream2);
    coffee_with_cream_cal2 = ((coffee_with_cream2 == 'Y') || (coffee_with_cream2 == 'y')) ? 1 : 0;


    printf("\nCOFFEE-3...\n");
    printf("Type ([L]ight,[M]edium,[R]ich): ");
    scanf(" %c", &coffee3);
    coffee3L = ((coffee3 == 'L') || (coffee3 == 'l')) ? 1 : 0;
    coffee3M = ((coffee3 == 'M') || (coffee3 == 'm')) ? 1 : 0;
    coffee3R = ((coffee3 == 'R') || (coffee3 == 'r')) ? 1 : 0;

    printf("Bag weight (g): ");
    scanf(" %lf", &coffee_g3);
    printf("Best served with cream ([Y]es,[N]o): ");
    scanf(" %c", &coffee_with_cream3);
    coffee_with_cream_cal3 = ((coffee_with_cream3 == 'Y') || (coffee_with_cream3 == 'y')) ? 1 : 0;


    printf("\n");
    printf("---+------------------------+---------------+-------+\n");
    printf("   |    Coffee              |   Packaged    | Best  |\n");
    printf("   |     Type               |  Bag Weight   | Served|\n");
    printf("   +------------------------+---------------+ With  |\n");
    printf("ID | Light | Medium | Rich  |  (G) | Lbs    | Cream |\n");
    printf("---+------------------------+---------------+-------|\n");
    printf(" 1 |   %d   |   %d    |   %d   |  %.0lf |  %.3lf |   %d   |\n", coffee1L, coffee1M, coffee1R, coffee_g1, coffee_g1 / GRAMS_IN_LBS, coffee_with_cream_cal1);
    printf(" 2 |   %d   |   %d    |   %d   |  %.0lf |  %.3lf |   %d   |\n", coffee2L, coffee2M, coffee2R, coffee_g2, coffee_g2 / GRAMS_IN_LBS, coffee_with_cream_cal2);
    printf(" 3 |   %d   |   %d    |   %d   | %.0lf |  %.3lf |   %d   |\n\n", coffee3L, coffee3M, coffee3R, coffee_g3, coffee_g3 / GRAMS_IN_LBS, coffee_with_cream_cal3);

    printf("Enter how you like your coffee...\n\n");

    printf("Coffee strength ([L]ight, [M]edium, [R]ich): ");
    scanf(" %c", &coffee1);
    coffee1L = ((coffee1 == 'L') || (coffee1 == 'l')) * 1;
    coffee1M = ((coffee1 == 'M') || (coffee1 == 'm')) * 1;
    coffee1R = ((coffee1 == 'R') || (coffee1 == 'r')) * 1;

    coffee1L *= !coffee1M && !coffee1R;
    coffee1M *= !coffee1L && !coffee1R;
    coffee1R *= !coffee1L && !coffee1M;

    printf("Do you like your coffee with cream ([Y]es,[N]o): ");
    scanf(" %c", &coffee_with_cream1);
    coffee_with_cream_cal1 = ((coffee_with_cream1 == 'Y') || (coffee_with_cream1 == 'y')) ? 1 : 0;

    printf("Typical number of daily servings: ");
    scanf(" %d", &coffee_servings_input_1);
    coffee_by_weight_1 = (coffee_servings_input_1 > 0 && coffee_servings_input_1 <= 3) * 1;
    coffee_by_weight_2 = (coffee_servings_input_1 > 4 && coffee_servings_input_1 <= 8) * 1;
    coffee_by_weight_3 = (coffee_servings_input_1 > 9) * 1;

    coffee_by_weight_1 *= !coffee_by_weight_2 && !coffee_by_weight_3;
    coffee_by_weight_2 *= !coffee_by_weight_1 && !coffee_by_weight_3;
    coffee_by_weight_3 *= !coffee_by_weight_1 && !coffee_by_weight_2;

    printf("\n");

    printf("The below table shows how your preferences align to the available products:\n\n");
    
    printf("--------------------+-------------+-------+\n");
    printf("  |     Coffee      |  Packaged   | With  |\n");
    printf("ID|      Type       | Bag Weight  | Cream |\n");
    printf("--+-----------------+-------------+-------+\n");
    printf(" 1|       %d         |      %d      |   %d   |\n", coffee1L, coffee_by_weight_1, coffee_with_cream_cal1);
    printf(" 2|       %d         |      %d      |   %d   |\n", coffee2L, coffee_by_weight_2, coffee_with_cream_cal2);
    printf(" 3|       %d         |      %d      |   %d   |\n\n", coffee3L, coffee_by_weight_3, coffee_with_cream_cal3);

    printf("Enter how you like your coffee...\n\n");

    printf("Coffee strength ([L]ight, [M]edium, [R]ich): ");
    scanf(" %c", &coffee1);
    coffee3L = ((coffee1 == 'L') || (coffee1 == 'l')) * 1;
    coffee3M = ((coffee1 == 'M') || (coffee1 == 'm')) * 1;
    coffee3R = ((coffee1 == 'R') || (coffee1 == 'r')) * 1;

    coffee3L *= !coffee3M && !coffee3R;
    coffee3M *= !coffee3L && !coffee3R;
    coffee3R *= !coffee3L && !coffee3M;

    printf("Do you like your coffee with cream ([Y]es,[N]o): ");
    scanf(" %c", &coffee_with_cream1);
    coffee_with_cream_cal1 = ((coffee_with_cream1 == 'Y') || (coffee_with_cream1 == 'y')) ? 0 : 0;
    coffee_with_cream_cal2 = ((coffee_with_cream1 == 'Y') || (coffee_with_cream1 == 'y')) ? 0 : 1;
    coffee_with_cream_cal3 = ((coffee_with_cream1 == 'Y') || (coffee_with_cream1 == 'y')) ? 0 : 1;

    printf("Typical number of daily servings: ");
    scanf(" %d", &coffee_servings_input_1);
    coffee_by_weight_1 = (coffee_servings_input_1 > 0 && coffee_servings_input_1 <= 3) * 1;
    coffee_by_weight_2 = (coffee_servings_input_1 > 4 && coffee_servings_input_1 <= 8) * 1;
    coffee_by_weight_3 = (coffee_servings_input_1 > 9) * 1;

    coffee_by_weight_1 *= !coffee_by_weight_2 && !coffee_by_weight_3;
    coffee_by_weight_2 *= !coffee_by_weight_1 && !coffee_by_weight_3;
    coffee_by_weight_3 *= !coffee_by_weight_1 && !coffee_by_weight_2;

    printf("\n");

    printf("The below table shows how your preferences align to the available products:\n\n");

    printf("--------------------+-------------+-------+\n");
    printf("  |     Coffee      |  Packaged   | With  |\n");
    printf("ID|      Type       | Bag Weight  | Cream |\n");
    printf("--+-----------------+-------------+-------+\n");
    printf(" 1|       %d         |      %d      |   %d   |\n", coffee1M, coffee_by_weight_1, coffee_with_cream_cal1);
    printf(" 2|       %d         |      %d      |   %d   |\n", coffee2L, coffee_by_weight_2, coffee_with_cream_cal2);
    printf(" 3|       %d         |      %d      |   %d   |\n\n", coffee3M, coffee_by_weight_3, coffee_with_cream_cal3);

    printf("Hope you found a product that suits your likes!\n");

    return 0;
}