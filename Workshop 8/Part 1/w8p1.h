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

#define MAX_PRODUCT 3
#define SUGGEST_GRAM 64
// ----------------------------------------------------------------------------
// structures

struct catFoodInfo
{
    int sku;
    double price;
    int calories;
    double weight;
};


// ----------------------------------------------------------------------------
// function prototypes

// 1. Get user input of int type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
int getIntPositive(int* intNumber);

// 2. Get user input of double type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
double getDoublePositive(double* floatNumber);

// 3. Opening Message (include the number of products that need entering)
void openingMessage(const int product, const int gram);

// 4. Get user input for the details of cat food product
struct catFoodInfo getCatFoodInfo(const int);

// 5. Display the formatted table header
void cat_food_header(void);

// 6. Display a formatted record of cat food data
void display_cat_food_data(const int sku, const double* price, const double* weight, const int calories);

// 7. Logic entry point
void start(void);
