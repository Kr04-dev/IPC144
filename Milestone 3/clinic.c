/*/////////////////////////////////////////////////////////////////////////
                        Assignment 1 - Milestone 3
Full Name  : Timothy LEe
Student ID#: 177133212
Email      : glee89@myseneca.ca
Section    : IPC144NRA

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

// include the user library "core" so we can use those functions
#include "core.h"
// include the user library "clinic" where the function prototypes are declared
#include "clinic.h"


//////////////////////////////////////
// DISPLAY FUNCTIONS
//////////////////////////////////////

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Display's the patient table header (table format)
void displayPatientTableHeader(void){
    printf("Pat.# Name            Phone#\n"
        "----- --------------- --------------------\n");
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Displays a single patient record in FMT_FORM | FMT_TABLE format
void displayPatientData(const struct Patient* patient, int fmt){
    if (fmt == FMT_FORM){
        printf("Name  : %s\n"
            "Number: %05d\n"
            "Phone : ", patient->name, patient->patientNumber);
        displayFormattedPhone(patient->phone.number);
        printf(" (%s)\n", patient->phone.description);
    } else {
        printf("%05d %-15s ", patient->patientNumber,
            patient->name);
        displayFormattedPhone(patient->phone.number);
        printf(" (%s)\n", patient->phone.description);
    }
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Display's appointment schedule headers (date-specific or all records)
void displayScheduleTableHeader(const struct Date* date, int isAllRecords){
    printf("Clinic Appointments for the Date: ");

    if (isAllRecords){
        printf("<ALL>\n\n");
        printf("Date       Time  Pat.# Name            Phone#\n"
            "---------- ----- ----- --------------- --------------------\n");
    } else {
        printf("%04d-%02d-%02d\n\n", date->year, date->month, date->day);
        printf("Time  Pat.# Name            Phone#\n"
            "----- ----- --------------- --------------------\n");
    }
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Display a single appointment record with patient info. in tabular format
void displayScheduleData(const struct Patient* patient,
    const struct Appointment* appoint,
    int includeDateField)
{
    if (includeDateField)
    {
        printf("%04d-%02d-%02d ", appoint->date.year, appoint->date.month,
            appoint->date.day);
    }
    printf("%02d:%02d %05d %-15s ", appoint->time.hour, appoint->time.min,
        patient->patientNumber, patient->name);

    displayFormattedPhone(patient->phone.number);

    printf(" (%s)\n", patient->phone.description);
}


//////////////////////////////////////
// MENU & ITEM SELECTION FUNCTIONS
//////////////////////////////////////

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// main menu
void menuMain(struct ClinicData* data)
{
    int selection;

    do {
        printf("Veterinary Clinic System\n"
            "=========================\n"
            "1) PATIENT     Management\n"
            "2) APPOINTMENT Management\n"
            "-------------------------\n"
            "0) Exit System\n"
            "-------------------------\n"
            "Selection: ");
        selection = inputIntRange(0, 2);
        putchar('\n');
        switch (selection)
        {
        case 0:
            printf("Are you sure you want to exit? (y|n): ");
            selection = !(inputCharOption("yn") == 'y');
            putchar('\n');
            if (!selection)
            {
                printf("Exiting system... Goodbye.\n\n");
            }
            break;
        case 1:
            menuPatient(data->patients, data->maxPatient);
            break;
        case 2:
            menuAppointment(data);
            break;
        }
    } while (selection);
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Menu: Patient Management
void menuPatient(struct Patient patient[], int max)
{
    int selection;

    do {
        printf("Patient Management\n"
            "=========================\n"
            "1) VIEW   Patient Data\n"
            "2) SEARCH Patients\n"
            "3) ADD    Patient\n"
            "4) EDIT   Patient\n"
            "5) REMOVE Patient\n"
            "-------------------------\n"
            "0) Previous menu\n"
            "-------------------------\n"
            "Selection: ");
        selection = inputIntRange(0, 5);
        putchar('\n');
        switch (selection)
        {
        case 1:
            displayAllPatients(patient, max, FMT_TABLE);
            suspend();
            break;
        case 2:
            searchPatientData(patient, max);
            break;
        case 3:
            addPatient(patient, max);
            suspend();
            break;
        case 4:
            editPatient(patient, max);
            break;
        case 5:
            removePatient(patient, max);
            suspend();
            break;
        }
    } while (selection);
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Menu: Patient edit
void menuPatientEdit(struct Patient* patient)
{
    int selection;

    do {
        printf("Edit Patient (%05d)\n"
            "=========================\n"
            "1) NAME : %s\n"
            "2) PHONE: ", patient->patientNumber, patient->name);

        displayFormattedPhone(patient->phone.number);

        printf("\n"
            "-------------------------\n"
            "0) Previous menu\n"
            "-------------------------\n"
            "Selection: ");
        selection = inputIntRange(0, 2);
        putchar('\n');

        if (selection == 1)
        {
            printf("Name  : ");
            inputCString(patient->name, 1, NAME_LEN);
            printf("Patient record updated!\n\n");
        }
        else if (selection == 2)
        {
            inputPhoneData(&patient->phone);
            printf("Patient record updated!\n\n");
        }

    } while (selection);
}


// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Menu: Appointment Management
void menuAppointment(struct ClinicData* data)
{
    int selection;

    do {
        printf("Appointment Management\n"
            "==============================\n"
            "1) VIEW   ALL Appointments\n"
            "2) VIEW   Appointments by DATE\n"
            "3) ADD    Appointment\n"
            "4) REMOVE Appointment\n"
            "------------------------------\n"
            "0) Previous menu\n"
            "------------------------------\n"
            "Selection: ");
        selection = inputIntRange(0, 4);
        putchar('\n');
        switch (selection)
        {
        case 1:
            viewAllAppointments(data);  // ToDo: You will need to create this function!
            suspend();
            break;
        case 2:
            viewAppointmentSchedule(data);  // ToDo: You will need to create this function!
            suspend();
            break;
        case 3:
            addAppointment(data->appointments, data->maxAppointments,
                data->patients, data->maxPatient);  // ToDo: You will need to create this function!
            suspend();
            break;
        case 4:
            removeAppointment(data->appointments, data->maxAppointments,
                data->patients, data->maxPatient);  // ToDo: You will need to create this function!
            suspend();
            break;
        }
    } while (selection);
}


// ---------------------------------------------------------------------------
// !!! INSERT/COPY YOUR MS#2 FUNCTION DEFINITIONS BELOW... !!!
// Note: Maintain the same order/sequence as it is listed in the header file
//       Properly organize/categorize any new functions accordingly
// ---------------------------------------------------------------------------


// Display's all patient data in the FMT_FORM | FMT_TABLE format
// (Copy your code from MS#2)
void displayAllPatients(const struct Patient patient[], int max, int fmt)
{
    int i, flag = 0;

    if (fmt == FMT_TABLE) {
        displayPatientTableHeader();
    }
    for (i = 0; i < max; i++) {
        if (patient[i].patientNumber != 0) {
            displayPatientData(&patient[i], fmt);
            flag = 1;
        }
    }
    if (flag == 0) {
        printf("*** No records found ***\n");
    }
    putchar('\n');
}

// Search for a patient record based on patient number or phone number
// (Copy your code from MS#2)
void searchPatientData(const struct Patient patient[], int max)
{
    int selection;
    do
    {
        printf("Search Options\n"
            "==========================\n"
            "1) By patient number\n"
            "2) By phone number\n"
            "..........................\n"
            "0) Previous menu\n"
            "..........................\n"
            "Selection: ");

        selection = inputIntRange(0, 2);
        putchar('\n');

        if (selection == 1) {
            searchPatientByPatientNumber(patient, max);
            suspend();
        }
        else if (selection == 2) {
            searchPatientByPhoneNumber(patient, max);
            suspend();
        }

    } while (selection != 0);

}

// Add a new patient record to the patient array
// (Copy your code from MS#2)
void addPatient(struct Patient patient[], int max)
{
    /*int i, index = -1;
    for (i = 0; index == -1 && i < max; i++) {
        if (patient[i].patientNumber == 0) {
            index = i;
        }
    }*/
    int index = -1;
    index = findPatientIndexByPatientNum(0, patient, max);

    //add patient can use findPatientIndexByPatientNum(input, patient, max); with input as 0
    if (index >= 0 && index <= max) {
        patient[index].patientNumber = nextPatientNumber(patient, max);

        inputPatient(&patient[index]);

        printf("*** New patient record added ***\n\n");
    }
    else {
        printf("ERROR: Patient listing is FULL!\n\n");
    }
}

// Edit a patient record from the patient array
// (Copy your code from MS#2)
void editPatient(struct Patient patient[], int max)
{
    int pnum, index;
    printf("Enter the patient number: ");
    pnum = inputIntPositive();
    putchar('\n');

    index = findPatientIndexByPatientNum(pnum, patient, max);

    if (index == -1) {
        printf("ERROR: Patient record not found!\n");
    }
    else {
        menuPatientEdit(&patient[index]);
    }
}

// Remove a patient record from the patient array
// (Copy your code from MS#2)
void removePatient(struct Patient patient[], int max)
{
    printf("Enter the patient number: ");
    int pnum = inputIntPositive();
    putchar('\n');

    int index = findPatientIndexByPatientNum(pnum, patient, max);

    if (index == -1) {
        printf("ERROR: Patient record not found!\n");
    }
    else {
        displayPatientData(&patient[index], FMT_FORM);
        printf("\nAre you sure you want to remove this patient record? (y/n): ");

        char ch = inputCharOption("yn");

        //scanf(" %c", &ch);
        //clearInputBuffer();

        if (ch == 'y') {
            patient[index].patientNumber = 0;

            /*for (int i = index; i < max - 1; i++) {
                patient[i] = patient[i + 1];
            }

            patient[max - 1].patientNumber = 0;*/

            printf("Patient record has been removed!\n");
        }
        else {
            printf("Operation aborted.\n");
        }
    }
    putchar('\n');
}

// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
// Milestone #3 mandatory functions...
// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

// View ALL scheduled appointments
// Todo:
void viewAllAppointments(struct ClinicData* data)
{
    int i, j;

    displayScheduleTableHeader(&data->appointments->date, 1);

    sortAppointmentsByDate(data);

    for (i = 0; i < data->maxAppointments; i++) {
        if (isNotEmpty(&data->appointments[i])) {
            for (j = 0; j < data->maxPatient; j++) {
                if (data->patients[j].patientNumber == data->appointments[i].patientNumber) {
                    displayScheduleData(&data->patients[j], &data->appointments[i], 1);
                }
            }
        }
    }

    putchar('\n');
}

// View appointment schedule for the user input date
// Todo:
void viewAppointmentSchedule(struct ClinicData* data)
{
    int i, j;
    struct Date dateInput = { 0 };
    dateInput = isDateValid();
    putchar('\n');

    displayScheduleTableHeader(&dateInput, 0);

    sortAppointmentsByDate(data);

    for (i = 0; i < data->maxAppointments; i++) {
        if (isNotEmpty(&data->appointments[i])) {
            if ((dateInput.year == data->appointments[i].date.year) && (dateInput.month == data->appointments[i].date.month)
                && (dateInput.day == data->appointments[i].date.day)) {

                for (j = 0; j < data->maxPatient; j++) {
                    if (data->patients[j].patientNumber == data->appointments[i].patientNumber) {
                        displayScheduleData(&data->patients[j], &data->appointments[i], 0);
                    }
                }
            }
        }
    }
    putchar('\n');
}

// Add an appointment record to the appointment array
// Todo:
void addAppointment(struct Appointment* appoints, int maxAppointments, struct Patient* patients, int maxPatients)
{
    int i, flag = 0;
    struct Appointment newAppoints = { 0 };

    printf("Patient Number: ");
    newAppoints.patientNumber = inputIntPositive();

    while (!flag) {
        newAppoints.date = isDateValid();
        newAppoints.time = isTimeValid();

        int cnt = 0, match = 0;
        for (i = 0; i < maxAppointments; i++) {
            if (isNotEmpty(&appoints[i])) {
                cnt++;
                if (newAppoints.date.year == appoints[i].date.year && newAppoints.date.month == appoints[i].date.month
                    && newAppoints.date.day == appoints[i].date.day && newAppoints.time.hour == appoints[i].time.hour
                    && newAppoints.time.min == appoints[i].time.min) {
                    match = 1;
                }
            }
        }
        putchar('\n');

        if (match) {
            printf("ERROR: Appointment timeslot is not available!\n\n");
        }
        else {
            appoints[cnt].patientNumber = newAppoints.patientNumber;
            appoints[cnt].date = newAppoints.date;
            appoints[cnt].time = newAppoints.time;

            printf("*** Appointment scheduled! ***\n\n");
            flag = 1;
        }
    }
}

// Remove an appointment record from the appointment array
// Todo:
void removeAppointment(struct Appointment* appoints, int maxAppointments, struct Patient* patients, int maxPatients)
{
    int pnum, index = -1, dateIndex = -1;
    char ch = '\0';
    struct Date inputDate = { 0 };

    printf("Patient Number: ");
    pnum = inputIntPositive();
    index = findPatientIndexByPatientNum(pnum, patients, maxPatients);

    if (index == -1) {
        printf("ERROR: Patient record not found!\n\n");
    }
    else {
        inputDate = isDateValid();

        dateIndex = findIndexByDate(pnum, inputDate, appoints, maxAppointments);
        putchar('\n');
        //printf("index=%d\n", index);

        displayPatientData(&patients[index], FMT_FORM);

        printf("Are you sure you want to remove this appointment (y,n): ");
        ch = inputCharOption("yn");
        putchar('\n');

        if (ch == 'y') {
            appoints[dateIndex].patientNumber = 0;
            printf("Appointment record has been removed!\n\n");
        }
        else {
            printf("Operation aborted.\n\n");
        }
    }
}


//////////////////////////////////////
// UTILITY FUNCTIONS
//////////////////////////////////////

// Search and display patient record by patient number (form)
// (Copy your code from MS#2)
void searchPatientByPatientNumber(const struct Patient patient[], int max)
{
    int pnum;
    printf("Search by patient number: ");
    pnum = inputIntPositive();
    putchar('\n');

    int index = findPatientIndexByPatientNum(pnum, patient, max);
    if (index == -1) {
        printf("*** No records found ***\n");
    }
    else {
        displayPatientData(&patient[index], FMT_FORM);
    }

    putchar('\n');
}

// Search and display patient records by phone number (tabular)
// (Copy your code from MS#2)
void searchPatientByPhoneNumber(const struct Patient patient[], int max)
{
    char phone[PHONE_LEN + 1];
    printf("Search by phone number: ");
    inputCString(phone, PHONE_LEN, PHONE_LEN);

    int i, matchCount = 0;

    displayPatientTableHeader();
    for (i = 0; i < max; i++) {
        if (strcmp(patient[i].phone.number, phone) == 0) {
            displayPatientData(&patient[i], FMT_TABLE);
            matchCount++;
        }
    }

    if (matchCount == 0) {
        printf("\n*** No records found ***\n");
    }

    putchar('\n');
}

// Get the next highest patient number
// (Copy your code from MS#2)
int nextPatientNumber(const struct Patient patient[], int max)
{
    int i, maxNum = patient[0].patientNumber;
    for (i = 0; i < max; i++) {
        if (patient[i].patientNumber > maxNum) {
            maxNum = patient[i].patientNumber;
        }
    }

    return maxNum + 1;
}

// Find the patient array index by patient number (returns -1 if not found)
// (Copy your code from MS#2)
int findPatientIndexByPatientNum(int patientNumber, const struct Patient patient[], int max)
{
    int i, index = -1;

    for (i = 0; index == -1 && i < max; i++) {
        if (patient[i].patientNumber == patientNumber) {
            index = i;
        }
    }

    return index;
}


///////Add Customized Function
// Find the appointment array index by patient number and the date
int findIndexByDate(int patientNum, struct Date inputDate, const struct Appointment appoints[], int maxAppoints)
{
    int i, index = -1;

    for (i = 0; index == -1 && i < maxAppoints; i++) {
        if ((inputDate.year == appoints[i].date.year) && (inputDate.month == appoints[i].date.month) && (inputDate.day == appoints[i].date.day)) {
            if (appoints[i].patientNumber == patientNum) {
                index = i;
            }
        }
    }

    return index;
}

// Check if there still has data to read; if data is not empty return 1, otherwise return 0
int isNotEmpty(const struct Appointment* appoints)
{
    int result = 0;

    if (appoints->patientNumber != 0) {
        result = 1;
    }

    return result;
}

// Check the opening and closing hour and time interval
struct Time isTimeValid(void)
{
    int hour, min, result = 1;
    while (result) {
        printf("Hour (0-23)  : ");
        hour = inputIntRange(0, 23);

        printf("Minute (0-59): ");
        min = inputIntRange(0, 59);

        if (hour >= START_TIME && hour < END_TIME && min % TIME_INTERVAL == 0) {
            result = 0;
        }
        else if (hour == END_TIME && min == 0) {
            result = 0;
        }
        else {
            printf("ERROR: Time must be between %02d:00 and %02d:00 in %d minute intervals.\n\n", START_TIME, END_TIME, TIME_INTERVAL);
        }
    }
    struct Time time = { hour, min };

    return time;
}

// Check the range of year, month, day is correct
struct Date isDateValid(void) {
    int year, month, day;

    printf("Year        : ");
    year = inputIntRange(2024, 2027);

    printf("Month (1-12): ");
    month = inputIntRange(1, 12);

    if (month == 2) {
        if (year % 4 == 0) {
            printf("Day (1-29)  : ");
            day = inputIntRange(1, 29);
        }
        else {
            printf("Day (1-28)  : ");
            day = inputIntRange(1, 28);
        }
    }
    else if (month % 2 == 1 || month == 8) {
        printf("Day (1-31)  : ");
        day = inputIntRange(1, 31);
    }
    else if (month % 2 == 0) {
        printf("Day (1-30)  : ");
        day = inputIntRange(1, 30);
    }

    struct Date dates = { year, month, day };

    return dates;
}

// Sort appointments data based on the date
void sortAppointmentsByDate(struct ClinicData* data)
{
    int i, j;
    struct Appointment temp;

    /*for (i = 0; i < data->maxAppointments; i++) {
        if (isNotEmpty(&data->appointments[i])) {
            numAppointment++;
        }
    }*/

    for (i = data->maxAppointments - 1; i > 0; i--) {
        for (j = 0; j < i; j++) {
            struct Date date1 = data->appointments[j].date;
            struct Date date2 = data->appointments[j + 1].date;
            struct Time time1 = data->appointments[j].time;
            struct Time time2 = data->appointments[j + 1].time;

            if (date1.year > date2.year || (date1.year == date2.year && date1.month > date2.month) ||
                (date1.year == date2.year && date1.month == date2.month && date1.day > date2.day) ||
                (date1.year == date2.year && date1.month == date2.month && date1.day == date2.day && time1.hour > time2.hour) ||
                (date1.year == date2.year && date1.month == date2.month && date1.day == date2.day && time1.hour == time2.hour && time1.min > time2.min)) {

                temp = data->appointments[j];
                data->appointments[j] = data->appointments[j + 1];
                data->appointments[j + 1] = temp;
            }
        }
        data->appointments[i] = data->appointments[j];
    }
}

//////////////////////////////////////
// USER INPUT FUNCTIONS
//////////////////////////////////////

// Get user input for a new patient record
// (Copy your code from MS#2)
void inputPatient(struct Patient* patient)
{
    printf("Patient Data Input\n"
        "------------------\n");
    printf("Number: %05d\n", patient->patientNumber);
    printf("Name  : ");

    inputCString(patient->name, 1, NAME_LEN);
    /*scanf("%[^\n]", patient->name);
    clearInputBuffer();
    putchar('\n');*/
    inputPhoneData(&patient->phone);
}

// Get user input for phone contact information
// (Copy your code from MS#2)
void inputPhoneData(struct Phone* phone)
{
    int selection;

    printf("Phone Information\n"
        "-----------------\n"
        "How will the patient like to be contacted?\n"
        "1. Cell\n"
        "2. Home\n"
        "3. Work\n"
        "4. TBD\n"
        "Selection: ");

    selection = inputIntRange(1, 4);
    switch (selection)
    {
    case 1:
        strcpy(phone->description, "CELL");
        break;
    case 2:
        strcpy(phone->description, "HOME");
        break;
    case 3:
        strcpy(phone->description, "WORK");
        break;
    case 4:
        strcpy(phone->description, "TBD");
        *phone->number = 0;
        putchar('\n');
        break;
    }

    if (selection != 4) {
        printf("\nContact: %s\n", phone->description);
        printf("Number : ");
        //inputCString(phone->number, PHONE_LEN, PHONE_LEN);
        inputCStringNum(phone->number, PHONE_LEN, PHONE_LEN);
    }
}

//////////////////////////////////////
// FILE FUNCTIONS
//////////////////////////////////////

// Import patient data from file into a Patient array (returns # of records read)
/// ToDo:
int importPatients(const char* datafile, struct Patient patients[], int max)
{
    int i = 0;
    FILE* fp = NULL;
    fp = fopen(datafile, "r");

    if (fp != NULL) {
        while (i < max && fscanf(fp, "%d|%15[^|]|%4[^|]|%10[^\n]", &patients[i].patientNumber,
            patients[i].name, patients[i].phone.description, patients[i].phone.number) != EOF) {
            i++;
        }
        fclose(fp);
    }
    else
    {
        printf("ERROR!!");
    }

    return i;
}

// Import appointment data from file into an Appointment array (returns # of records read)
// ToDo:
int importAppointments(const char* datafile, struct Appointment appoints[], int max)
{
    int i = 0;
    FILE* fp = NULL;
    fp = fopen(datafile, "r");

    if (fp != NULL) {
        while (i < max && fscanf(fp, "%d,%d,%d,%d,%d,%d%*c", &appoints[i].patientNumber, &appoints[i].date.year,
            &appoints[i].date.month, &appoints[i].date.day, &appoints[i].time.hour, &appoints[i].time.min) != EOF) {
            i++;
        }
        fclose(fp);
    }

    return i;
}