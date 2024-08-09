#ifndef _FUNCTION_H_
#define _FUNCTION_H_

#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <ctime>
#include <windows.h>
#include <conio.h>
#include <iomanip>

using namespace std;

// Define Info Users structure
struct InfoUsers
{
    int id;
    string name;
    int age;
    string gender;
    string race;
    int diagnosis;
    int body_part;
    int disposition;
    int location;
    int product;
    float stat_weight;
    string stratum; 
};

// Define DateMonthYear structure
struct DateMonthYear
{
    int date;
    int month;
    int year;
};

// Define UsersObject structure
struct UsersObject
{
    int id;
    string name;
    pair<string, DateMonthYear> medical_examinations[100];
    // max of 100 times
    int medical_examinationsCount = 0;
};

// Define MedicinesObject structure
struct MedicinesObject
{
    int id;
    string name;
    string category;
    string dosage_form;
    int strength_mg;
    string indication;
    string manufacturer;
    int remaining;
};

// Define temple string
extern string temple1;
extern string temple2;
extern string temple3;

// Define Info Users in variables
extern InfoUsers infoUsers[1000];
extern int k;

// Define csv file in variables
extern UsersObject users[1000];
extern int m;

// Define csv file in variables
extern MedicinesObject medicines[1000];
extern int n;

// Get current date
extern time_t now;
extern tm *ltm;

// Center text function
void centerText(const string& text);

// Import Info Users function
void importInfoUsers();

// Import Users function
void importUsers();

// Import Medicines function
void importMedicines();

// Check if a string is an integer
bool isInteger(string str);

// Check if a string is a float
bool isFloat(string str);

// Print all users whose have that disease
void showUsersWhoseHaveThatDisease(string disease);

// Add one patient to datastructure
void addOnePatientToDatastructure(int id, string name, int age, string gender, string race, int diagnosis, int body_part, int disposition, int location, int product, float stat_weight, string stratum);

// Delete one patient from datastructure
void deleteOnePatientFromDatastructure(int id);

// Find the index of patient in datastructure
int findIndexPatientInDatastructure(int id);

// Patient Health Management Menu
void patientHealthManagementMenu(string &patientChoice, int &patientChoiceInt);

// Add one user to datastructure
void addOneUserToDatastructure(int id, string name);

// Delete one user from datastructure
void deleteOneUserFromDatastructure(int id);

// Find one user from datastructure by ID
void findOneUserFromDatastructureByID(int id);

// Find all users from datastructure by name
void findAllUsersFromDatastructureByName(string name);

// Check if the ID of user has been used
bool isIDOfUserUsed(int id);

// User Management Menu
void userManagementMenu(string &userChoice, int &userChoiceInt);

// Check if the ID of medicine has been used
bool isIDOfMedicineUsed(int id);

// Add one medicine to datastructure
void addOneMedicineToDatastructure(int id, string name, string category, string Dosage_Form, int Strength_mg, string Indication, string Manufacturer, int remaining);

// Delete one medicine from datastructure
void deleteOneMedicineFromDatastructure(int id);

// Find one medicine from datastructure by ID
void findOneMedicineFromDatastructureByID(int id);

// Find all medicines from datastructure by name
void findAllMedicinesFromDatastructureByName(string name);

// Find all medicines from datastructure by category
void findAllMedicinesFromDatastructureByCategory(string category);

// Find all medicines from datastructure Dosage_Form
void findAllMedicinesFromDatastructureByDosage_Form(string Dosage_Form);

// Find all medicines from datastructure by Strength(mg)
void findAllMedicinesFromDatastructureByStrength_mg(int Strength_mg);

// Find all medicines from datastructure by Manufacturer
void findAllMedicinesFromDatastructureByManufacturer(string Manufacturer);

// Medicine Management Menu
void medicineManagementMenu(string &medicineChoice, int &medicineChoiceInt);

// Show all statistics in the system
void showAllStatisticsInTheSystem(); 

// Data Management And Statistics Menu
void dataManagementAndStatisticsMenu(string &dataChoice, int &dataChoiceInt);

// Setting Menu
void settingMenu(string &settingChoice, int &settingChoiceInt);

// Export all users from datastructre to data_information.csv
void exportInfoUsers();

// Import all users from datastructre to users_dataset.csv
void exportUsers();

// Import all medicines from datastructre to medicines_dataset.csv
void exportMedicines();

#endif