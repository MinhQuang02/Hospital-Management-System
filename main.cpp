#include "function.h"

// Define all variables
string temple1;
string temple2;
string temple3;
InfoUsers infoUsers[1000];
int k = 0;
UsersObject users[1000];
int m = 0;
MedicinesObject medicines[1000];
int n = 0;
time_t now = time(nullptr);
tm *ltm = localtime(&now);

int main() 
{
    // Import all info users from data_information.csv to database and datastructure
    importInfoUsers();

    // Import all users from data_users.csv to database and datastructure
    importUsers();

    // Import all medicine from data_medicines.csv to database and datastructure
    importMedicines();

    // Main menu
    while (true)
    {
        centerText("------------------- Hospital Management Menu -------------------\n");
        cout << "\n";
        centerText("1. Patient Health Management.\n");
        centerText("2. Medical Visits Management.\n");
        centerText("3. Medicine Management.\n");
        centerText("4. Data Management And Statistics.\n");
        centerText("5. Setting.\n");
        centerText("6. Exit.\n");
        cout << "\n";
        
        centerText("Select one to continue the application.\n");
        centerText("Enter your choice (Choose a number from 1 to 6) : ");

        string choice;
        getline(cin, choice);
        
        while (!isInteger(choice) || stoi(choice) < 1 || stoi(choice) > 6)
        {
            cout << "\n";
            centerText("Warning : Invalid choice!\n");
            centerText("Please enter a number between 1 and 6.\n");
            centerText("Enter your choice (Choose a number from 1 to 6) : ");
            getline(cin, choice);
        }

        cout << "\n";
        
        // Layer 1 menu
        int choiceInt = stoi(choice);
        if (choiceInt == 1)
        {
            // Layer 1 menu
            string patientChoice;
            int patientChoiceInt;
            patientHealthManagementMenu(patientChoice, patientChoiceInt);
            while (patientChoiceInt != 4)
            {
                patientHealthManagementMenu(patientChoice, patientChoiceInt);
            }
        }
        else if (choiceInt == 2)
        {
            // Layer 1 menu
            string userChoice;
            int userChoiceInt;
            userManagementMenu(userChoice, userChoiceInt);
            while (userChoiceInt != 5)
            {
                userManagementMenu(userChoice, userChoiceInt);
            }
        }
        else if (choiceInt == 3)
        {
            string medicineChoice;
            int medicineChoiceInt;
            medicineManagementMenu(medicineChoice, medicineChoiceInt);
            while (medicineChoiceInt != 4)
            {
                medicineManagementMenu(medicineChoice, medicineChoiceInt);
            }
        }
        else if (choiceInt == 4)
        {
            // Layer 1 menu
            string dataChoice;
            int dataChoiceInt;
            dataManagementAndStatisticsMenu(dataChoice, dataChoiceInt);
            while (dataChoiceInt != 5)
            {
                dataManagementAndStatisticsMenu(dataChoice, dataChoiceInt);
            }
        }
        else if (choiceInt == 5)
        {
            // Layer 1 menu
            string settingChoice;
            int settingChoiceInt;
            settingMenu(settingChoice, settingChoiceInt);
            while (settingChoiceInt != 2)
            {
                settingMenu(settingChoice, settingChoiceInt);
            }
        }
        else
        {
            // Exit
            centerText("Exitting program.\n");
            centerText("Thank you for using the application!\n");
            cout << "\n";
            system("pause");
            break;
        }
    }
    
    // Export all medicines from datastructure to medicines_dataset.csv and data_users.csv
    exportMedicines();
    exportUsers();

    return 0;
}