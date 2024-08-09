#include "function.h"

// Data Management And Statistics Menu
void dataManagementAndStatisticsMenu(string &dataChoice, int &dataChoiceInt)
{
    system("cls");
    centerText("------------------- Data Management And Statistics Menu -------------------\n\n");
    centerText("1. Show all information about patient.\n");
    centerText("2. Show all disease diagnosis of patient.\n");
    centerText("3. Show all information about medicine.\n");
    centerText("4. Show all statistics about books.\n");
    centerText("5. Return to Main Menu.\n\n");

    centerText("Select one to continue the application.\n");
    centerText("Enter your choice (Choose a number from 1 to 5) : ");
    
    getline(cin, dataChoice);

    while (!isInteger(dataChoice) || stoi(dataChoice) < 1 || stoi(dataChoice) > 5)
    {
        cout << "\n";
        centerText("Warning : Invalid choice!\n");
        centerText("Please enter a number between 1 and 5.\n");
        centerText("Enter your choice (Choose a number from 1 to 5) : ");
        getline(cin, dataChoice);
    }

    cout << "\n";
    system("cls");

    // Layer 2 menu
    dataChoiceInt = stoi(dataChoice);
    if (dataChoiceInt == 1)
    {
        // Show all information about patient
        centerText("------------------- Show all information about patient Menu -------------------\n\n");
        for (int i = 0; i < k; i++)
        {   
            cout << "Patient " << i + 1 << " : " << endl;
            cout << "ID : " << infoUsers[i].id << endl;
            cout << "Name : " << infoUsers[i].name << endl;
            cout << "Age : " << infoUsers[i].age << endl;
            cout << "Gender : " << infoUsers[i].gender << endl;
            cout << "Race : " << infoUsers[i].race << endl;
            cout << "Diagnosis : " << infoUsers[i].diagnosis << endl;
            cout << "Body Part : " << infoUsers[i].body_part << endl;
            cout << "Disposition : " << infoUsers[i].disposition << endl;
            cout << "Location : " << infoUsers[i].location << endl;
            cout << "Product : " << infoUsers[i].product << endl;
            cout << "Stat Weight : " << infoUsers[i].stat_weight << endl;
            cout << "Stratum : " << infoUsers[i].stratum << endl;
            cout << "--------------------------------------------\n"; 
        }

        cout << "\n";
        system("pause");
    }
    else if (dataChoiceInt == 2)
    {
        // Show all users
        centerText("------------------- Show all patients Menu -------------------\n\n");
        for (int i = 0; i < m; i++)
        {   
            cout << "Patient " << i + 1 << " : " << endl;
            cout << users[i].id << " - " << users[i].name << " : ";
            for (int j = 0; j < users[i].medical_examinationsCount; j++)
            {
                cout << users[i].medical_examinations[j].first << " : " << users[i].medical_examinations[j].second.date << "/" << users[i].medical_examinations[j].second.month << "/" << users[i].medical_examinations[j].second.year << endl;
            }
            cout << "--------------------------------------------\n";
        }

        cout << "\n";
        system("pause");
    }
    else if (dataChoiceInt == 3)
    {
        // Show all information about medicine
        centerText("------------------- Show all information about medicine Menu -------------------\n\n");
        for (int i = 0; i < n; i++)
        {
            cout << "Medicine " << i + 1 << " : " << endl;
            cout << "ID : " << medicines[i].id << endl;
            cout << "Name : " << medicines[i].name << endl;
            cout << "Category : " << medicines[i].category << endl;
            cout << "Dosage Form : " << medicines[i].dosage_form << endl;
            cout << "Strength (mg) : " << medicines[i].strength_mg << endl;
            cout << "Indication : " << medicines[i].indication << endl;
            cout << "Manufacturer : " << medicines[i].manufacturer << endl;
            cout << "Remaining : " << medicines[i].remaining << endl;
            cout << "--------------------------------------------\n";
        }

        cout << "\n";
        system("pause");
    }
    else if (dataChoiceInt == 4)
    {
        // Shows all statistics about patients
        centerText("------------------- Shows all statistics about patients Menu -------------------\n\n");

        // Analysis all statistics about patients from database and datastructure and show them
        centerText("Total of patients : " + to_string(k) + " unique value(s)\n");
        centerText("Total of medicines : " + to_string(n) + " unique value(s)\n");
        showAllStatisticsInTheSystem();

        cout << "\n";
        system("pause");
    }
}