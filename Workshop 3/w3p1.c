/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #3 (P1)
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

int main(void){

    const int product_1 = 111, product_2 = 222, product_3 = 111; 
    const char product_tax_1 =  'Y', product_tax_2 = 'N', product_tax_3 = 'N'; 
    const float product_price_1 = 111.49, product_price_2 = 222.99, product_price_3 = 334.49;
    const double testValue = 330.99;
    int result;
    float product_average; 
    // total of 11 variables

    printf("Product Information\n");
    printf("===================\n");
    printf("Product-1 (ID:%d)\n", product_1);
    printf("  Taxed: %c\n", product_tax_1);
    printf("  Price: $%.4f\n\n", product_price_1);
    printf("Product-2 (ID:%d)\n", product_2);
    printf("  Taxed: %c\n", product_tax_2);
    printf("  Price: $%.4f\n\n", product_price_2);
    printf("Product-3 (ID:%d)\n", product_3);
    printf("  Taxed: %c\n", product_tax_3);
    printf("  Price: $%.4f\n\n", product_price_3);

    product_average = (product_price_1 + product_price_2 + product_price_3) / 3;
    printf("The average of all prices is: $%.4f\n\n", product_average);

    printf("About Relational and Logical Expressions!\n");
    printf("========================================\n");
    printf("1. These expressions evaluate to TRUE or FALSE\n");
    printf("2. FALSE: is always represented by integer value 0\n");
    printf("3. TRUE : is represented by any integer value other than 0\n\n");
    

    printf("Some Data Analysis...\n");
    printf("=====================\n");
    printf("1. Is product 1 taxable? -> ");
    result = (product_tax_1 == 'Y') ? 1 : 0;
    printf("%d\n\n", result);

    printf("2. Are products 2 and 3 both NOT taxable (N)? -> ");
    result = (product_tax_2 == 'Y' && product_tax_3 == 'Y') ? 0 : 1;
    printf("%d\n\n", result);

    printf("3. Is product 3 less than testValue ($%.2f)? -> ", testValue);
    result = (testValue <= product_price_3) ? 0 : 1;
    printf("%d\n\n", result);

    printf("4. Is the price of product 3 more than both product 1 and 2 combined? -> ");
    result = (product_price_3 < (product_price_1 + product_price_2)) ? 0 : 1;
    printf("%d\n\n", result);

    printf("5. Is the price of product 1 equal to or more than the price difference\n");
    printf("   of product 3 LESS product 2? ->  ");
    result = (product_price_1 >= (product_price_2 + product_price_3)) ? 1 : 0;
    printf("%d (price difference: $%.2f)\n\n", result, product_price_2 - product_price_1);

    printf("6. Is the price of product 2 equal to or more than the average price? -> ");
    result = (product_price_2 >= product_average) ? 1 : 0;
    printf("%d\n\n", result);

    printf("7. Based on product ID, product 1 is unique -> ");
    result = (product_1 == product_2 || product_1 == product_3) ? 0 : 1;
    printf("%d\n\n", result);

    printf("8. Based on product ID, product 2 is unique -> ");
    result = (product_2 == product_1 || product_2 == product_3) ? 0 : 1;
    printf("%d\n\n", result);

    printf("9. Based on product ID, product 3 is unique -> ");
    result = (product_3 == product_1 || product_3 == product_2) ? 0 : 1;
    printf("%d\n\n", result);


    return 0;
}
