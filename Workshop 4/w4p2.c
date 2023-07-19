/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #4 (P2)
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

    int apples, oranges, pears, tomatoes, cabbages, another_shopping;
    int apples_pick, oranges_pick, pears_pick, tomatoes_pick, cabbages_pick;

    do {

        printf("Grocery Shopping\n");
        printf("================\n");

        do {
            printf("How many APPLES do you need? : ");
            scanf(" %d", &apples);
            if (apples < 0) {
                printf("ERROR: Value must be 0 or more.\n");
            } else {
                printf("\n");
            }
        } while (apples < 0);

        do {
            printf("How many ORANGES do you need? : ");
            scanf(" %d", &oranges);
            if (oranges < 0) {
                printf("ERROR: Value must be 0 or more.\n");
            } else {
                printf("\n");
            }
        } while (oranges < 0);

        do {
            printf("How many PEARS do you need? : ");
            scanf(" %d", &pears);
            if (pears < 0) {
                printf("ERROR: Value must be 0 or more.\n");
            } else {
                printf("\n");
            }
        } while (pears < 0);

        do {
            printf("How many TOMATOES do you need? : ");
            scanf(" %d", &tomatoes);
            if (tomatoes < 0) {
                printf("ERROR: Value must be 0 or more.\n");
            } else {
                printf("\n");
            }
        } while (tomatoes < 0);

        do {
            printf("How many CABBAGES do you need? : ");
            scanf(" %d", &cabbages);
            if (cabbages < 0) {
                printf("ERROR: Value must be 0 or more.\n");
            } else {
                printf("\n");
            }
        } while (cabbages < 0);

        printf("--------------------------\n");
        printf("Time to pick the products!\n");
        printf("--------------------------\n\n");
        
        if (apples > 0) {
            do {
                printf("Pick some APPLES... how many did you pick? : ");
                scanf(" %d", &apples_pick);
                if (apples_pick <= 0) {
                    printf("ERROR: You must pick at least 1!\n");
                } else if (apples >= apples_pick) {
                    apples -= apples_pick;
                    if (apples != 0) {
                        printf("Looks like we still need some APPLES...\n");
                    }
                } else if (apples < apples_pick) {
                    printf("You picked too many... only %d more APPLE(S) are needed.\n", apples);
                } else {
                }
                if (apples == 0) {
                    printf("Great, that's the apples done!\n\n");
                }
            } while (!(apples == 0));
        }

        if (oranges > 0) {
            do {
                printf("Pick some ORANGES... how many did you pick? : ");
                scanf(" %d", &oranges_pick);
                if (oranges_pick <= 0) {
                    printf("ERROR: You must pick at least 1!\n");
                } else if (oranges >= oranges_pick) {
                    oranges -= oranges_pick;
                    if (oranges != 0) {
                        printf("Looks like we still need some ORANGES...\n");
                    }
                } else if (oranges < oranges_pick) {
                    printf("You picked too many... only %d more ORANGE(S) are needed.\n", oranges);
                } else {
                }
                if (oranges == 0) {
                    printf("Great, that's the oranges done!\n\n");
                }
            } while (!(oranges == 0));
        }

        if (pears > 0) {
            do {
                printf("Pick some PEARS... how many did you pick? : ");
                scanf(" %d", &pears_pick);
                if (pears_pick <= 0) {
                    printf("ERROR: You must pick at least 1!\n");
                } else if (pears >= pears_pick) {
                    pears -= pears_pick;
                    if (pears != 0) {
                        printf("Looks like we still need some PEARS...\n");
                    }
                } else if (pears < pears_pick) {
                    printf("You picked too many... only %d more PEAR(S) are needed.\n", pears);
                } else {
                }
                if (pears == 0) {
                    printf("Great, that's the pears done!\n\n");
                }
            } while (!(pears == 0));
        }

        if (tomatoes > 0) {
            do {
                printf("Pick some TOMATOES... how many did you pick? : ");
                scanf(" %d", &tomatoes_pick);
                if (tomatoes_pick <= 0) {
                    printf("ERROR: You must pick at least 1!\n");
                } else if (tomatoes >= tomatoes_pick) {
                    tomatoes -= tomatoes_pick;
                    if (tomatoes != 0) {
                        printf("Looks like we still need some TOMATOES...\n");
                    }
                } else if (tomatoes < tomatoes_pick) {
                    printf("You picked too many... only %d more TOMATO(ES) are needed.\n", tomatoes);
                } else {
                }
                if (tomatoes == 0) {
                    printf("Great, that's the tomatoes done!\n\n");
                }
            } while (!(tomatoes == 0));
        }

        if (cabbages > 0) {
            do {
                printf("Pick some CABBAGES... how many did you pick? : ");
                scanf(" %d", &cabbages_pick);
                if (cabbages_pick <= 0) {
                    printf("ERROR: You must pick at least 1!\n");
                } else if (cabbages >= cabbages_pick) {
                    cabbages -= cabbages_pick;
                    if (cabbages != 0) {
                        printf("Looks like we still need some CABBAGES...\n");
                    }
                } else if (cabbages < cabbages_pick) {
                    printf("You picked too many... only %d more CABBAGE(S) are needed.\n", cabbages);
                } else {
                }
                if (cabbages == 0) {
                    printf("Great, that's the cabbages done!\n\n");
                }
            } while (!(cabbages == 0));
        }

        printf("All the items are picked!\n\n");
        printf("Do another shopping? (0=NO): ");
        scanf(" %d", &another_shopping);
        printf("\n");
    } while (another_shopping == 1);
    printf("Your tasks are done for today - enjoy your free time!\n");
    return 0;
}