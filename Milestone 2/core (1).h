/*/////////////////////////////////////////////////////////////////////////
                        Assignment 1 - Milestone 2
Full Name  : Taehwa Hong
Student ID#: 132546227
Email      : thong14@myseneca.ca
Section    : IPC144NAA

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/

// SAFE-GUARD: 
// It is good practice to apply safe-guards to header files
// Safe-guard's ensures only 1 copy of the header file is used in the project build
// The macro name should be mirroring the file name with _ for spaces, dots, etc.

// !!! DO NOT DELETE THE BELOW 2 LINES !!!
#ifndef CORE_H
#define CORE_H

// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
// 
// Copy your work done from Milestone #1 (core.h) into this file
// 
// NOTE:
// - Organize your functions into the below categories
// - Make sure the core.c file also lists these functions in the same order!
// - Be sure to provide a BRIEF comment for each function prototype
// - The comment should also be copied to the core.c function definition
//
// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!


//////////////////////////////////////
// USER INTERFACE FUNCTIONS
//////////////////////////////////////

// Clear the standard input buffer
void clearInputBuffer(void);

// Wait for user to input the "enter" key to continue
void suspend(void);






//////////////////////////////////////
// USER INPUT FUNCTIONS
//////////////////////////////////////


// Tester Function Definitions

// Function for Input Integer
int inputInt(void);

// Function for Input Positive Integer
int inputIntPositive(void);

// Range of Integer
int inputIntRange(int min, int max);

// Function for Input Character
char inputCharOption(char str[]);

// Function for Input Character String
void inputCString(char* cStringValue, int min, int max);

void displayFormattedPhone(const char* phoneNum);

// Clear the standard input buffer
void clearInputBuffer(void);

// Wait for user to input the "enter" key to continue
void suspend(void);











// !!! DO NOT DELETE THE BELOW LINE !!!
#endif // !CORE_H