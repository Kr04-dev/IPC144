/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #5 (P1)
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
#define MIN_YEAR 2012 
#define MAX_YEAR 2022 

int main() {

    const int JAN = 1;
    const int DEC = 12;
    int year, month, date = 1;
    char* monthName;

    printf("General Well-being Log\n");
    printf("======================\n");

    do {
        printf("Set the year and month for the well-being log (YYYY MM): ");
        scanf(" %d %d", &year, &month);

        if (year < MIN_YEAR || year > MAX_YEAR) {
            printf("   ERROR: The year must be between %d and %d inclusive\n", MIN_YEAR, MAX_YEAR);
        }
        if (month < JAN || month > DEC) {
            printf("   ERROR: Jan.(%d) - Dec.(%d)\n", JAN, DEC);
        }
        if (year >= MIN_YEAR && year <= MAX_YEAR && month >= JAN && month <= DEC) {
            printf("\n");
        }
    } while (!(year >= MIN_YEAR && year <= MAX_YEAR && month >= JAN && month <= DEC));

    printf("*** Log date set! ***\n\n");

    switch (month) {
        case 1: monthName = "JAN"; break;
        case 2: monthName = "FEB"; break;
        case 3: monthName = "MAR"; break;
        case 4: monthName = "APR"; break;
        case 5: monthName = "MAY"; break;
        case 6: monthName = "JUN"; break;
        case 7: monthName = "JUL"; break;
        case 8: monthName = "AUG"; break;
        case 9: monthName = "SEP"; break;
        case 10: monthName = "OCT"; break;
        case 11: monthName = "NOV"; break;
        case 12: monthName = "DEC"; break;
    }

    printf("Log starting date: %d-%s-0%d\n", year, monthName, date);

    return 0;
}

