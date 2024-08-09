#include "function.h"

// Medicine Management Menu
void medicineManagementMenu(string &medicineChoice, int &medicineChoiceInt)
{
    system("cls");
    centerText("------------------- Medicine Management Menu -------------------\n\n");
    centerText("1. Add a medicine.\n");
    centerText("2. Delete a medicine.\n");
    centerText("3. Find a medicine.\n");
    centerText("4. Return to the main menu.\n\n");

    centerText("Select one to continue the application.\n");
    centerText("Enter your choice (Choose a number from 1 to 4) : ");
    getline(cin, medicineChoice);

    while (!isInteger(medicineChoice) || stoi(medicineChoice) < 1 || stoi(medicineChoice) > 4)
    {
        cout << "\n";
        centerText("Warning : Invalid choice!\n");
        centerText("Please enter a number between 1 and 4.\n");
        centerText("Enter your choice (Choose a number from 1 to 4) : ");
        getline(cin, medicineChoice);
    }

    cout << "\n";
    system("cls");
    
    // Layer 2 menu
    medicineChoiceInt = stoi(medicineChoice);
    if (medicineChoiceInt == 1)
    {   
        // Add a medicine
        centerText("------------------- Add a medicine Menu -------------------\n\n");

        // Add a medicine
        centerText("Enter information to add a new medicine.\n\n");

        // Enter ID of medicine
        centerText("Enter ID of medicine (4 digits) : ");

        string id;
        getline(cin, id);
        while (!isInteger(id) || stoi(id) < 1000 || stoi(id) > 9999 || isIDOfMedicineUsed(stoi(id)))
        {
            cout << "\n";
            centerText("Warning : The ID is already used or you did not enter ID in the correct format!\n");
            centerText("Please enter a number. (In case you don't know ID. Enter \"Exit\" to return).\n");
            centerText("Enter ID of medicine (4 digits) : ");
            getline(cin, id);
            if (id == "Exit")
            {
                cout << "\n";
                return;
            }
        }

        // Enter name of medicine
        centerText("Enter name of medicine : ");
        string name;
        getline(cin, name);

        // Enter category of medicine
        centerText("Enter category of medicine : ");
        string category;
        getline(cin, category);

        // Enter Dosage Form of medicine
        centerText("Enter Dosage Form of medicine : ");
        string dosageForm;
        getline(cin, dosageForm);

        // Enter Strength(mg) of medicine
        centerText("Enter Strength(mg) Year of medicine : ");
        string Strength_mg;
        getline(cin, Strength_mg);
        while (!isInteger(Strength_mg) || stoi(Strength_mg) < 0)
        {
            cout << "\n";
            centerText("Warning : Invalid year!\n");
            centerText("Please enter a number.\n");
            centerText("Enter Strength(mg) of medicine : ");
            getline(cin, Strength_mg);
        }

        // Enter Indication of medicine
        centerText("Enter Indication of medicine : ");
        string Indication;
        getline(cin, Indication);

        // Enter Manufacturer of medicine
        centerText("Enter Manufacturer of medicine : ");
        string Manufacturer;
        getline(cin, Manufacturer);

        // Enter Remaining of medicine
        centerText("Enter Remaining of medicine : ");
        string remaining;
        getline(cin, remaining);
        while (!isInteger(remaining) || stoi(remaining) < 0)
        {
            cout << "\n";
            centerText("Warning : Invalid number!\n");
            centerText("Please enter a number.\n");
            centerText("Enter Remaining of medicine : ");
            getline(cin, remaining);
        }

        // Import this medicine to database and datastructure
        addOneMedicineToDatastructure(stoi(id), name, category, dosageForm, stoi(Strength_mg), Indication, Manufacturer, stoi(remaining));

        cout << "\n";
        centerText("Has been added successfully.\n");
        cout << "\n";

        system("pause");
    }
    else if (medicineChoiceInt == 2)
    {
        // Delete a medicine
        centerText("------------------- Delete a medicine Menu -------------------\n\n");

        // Enter ID of medicine to delete
        centerText("Enter ID of medicine to delete (4 digits) : ");
        string id;
        getline(cin, id);
        while (!isInteger(id) || stoi(id) < 1000 || stoi(id) > 9999 || !isIDOfMedicineUsed(stoi(id)))
        {
            cout << "\n";
            centerText("Warning : The ID is not found or you did not enter ID in the correct format!\n");
            centerText("Please enter a number. (In case you don't know ID. Enter \"Exit\" to return).\n");
            centerText("Enter ID of medicine to delete (4 digits) : ");
            getline(cin, id);
            if (id == "Exit")
            {
                cout << "\n";
                return;
            }
        }

        // Delete this medicine from database and datastructure (Restructure the database and data structure)
        deleteOneMedicineFromDatastructure(stoi(id));
        cout << "\n";
        centerText("Has been deleted successfully.\n");
        cout << "\n";

        system("pause");
    }
    else if (medicineChoiceInt == 3)
    {
        // Find a medicine
        centerText("------------------- Find a medicine Menu -------------------\n\n");

        centerText("1. Find a medicine by ID.\n");
        centerText("2. Find a medicine by Name.\n");
        centerText("3. Find a medicine by Category.\n");
        centerText("4. Find a medicine by Dosage Form.\n");
        centerText("5. Find a medicine by Strength(mg).\n");
        centerText("6. Find a medicine by Manufacturer.\n\n");

        centerText("Select one to continue the application.\n");
        centerText("Enter your choice (Choose a number from 1 to 6) : ");
        string findChoice;
        getline(cin, findChoice);
        while (!isInteger(findChoice) || stoi(findChoice) < 1 || stoi(findChoice) > 6)
        {
            cout << "\n";
            centerText("Warning : Invalid choice!\n");
            centerText("Please enter a number between 1 and 6.\n");
            centerText("Enter your choice (Choose a number from 1 to 6) : ");
            getline(cin, findChoice);
        }

        cout << "\n";
        system("cls");

        int findChoiceInt = stoi(findChoice);
        if (findChoiceInt == 1)
        {
            // Find a medicine by ID
            centerText("------------------- Find a medicine by ID Menu -------------------\n\n");

            // Enter ID of medicine to find
            centerText("Enter ID of medicine to find (4 digits) : ");
            string id;
            getline(cin, id);
            while (!isInteger(id) || stoi(id) < 1000 || stoi(id) > 9999 || !isIDOfMedicineUsed(stoi(id)))
            {
                cout << "\n";
                centerText("Warning : The ID is not found or you did not enter ID in the correct format!\n");
                centerText("Please enter a number. (In case you don't know ID. Enter \"Exit\" to return).\n");
                centerText("Enter ID of medicine to find (4 digits) : ");
                getline(cin, id);
                if (id == "Exit")
                {
                    cout << "\n";
                    return;
                }
            }

            // Find this medicine from database and datastructure
            cout << "\n";
            findOneMedicineFromDatastructureByID(stoi(id));
        }
        else if (findChoiceInt == 2)
        {
            // Find a medicine by name
            centerText("------------------- Find a medicine by Name Menu -------------------\n\n");

            // Enter name of medicine to find
            centerText("Enter name of medicine to find : ");
            string name;
            getline(cin, name);

            // Find this medicine from database and datastructure
            cout << "\n";
            findAllMedicinesFromDatastructureByName(name);
        }
        else if (findChoiceInt == 3)
        {
            // Find a medicine by category
            centerText("------------------- Find a medicine by Category Menu -------------------\n\n");

            // Enter category of medicine to find
            centerText("Enter category of medicine to find : ");
            string category;
            getline(cin, category);

            // Find this medicine from database and datastructure
            cout << "\n";
            findAllMedicinesFromDatastructureByCategory(category);
        }
        else if (findChoiceInt == 4)
        {
            // Find a medicine by dosage form
            centerText("------------------- Find a medicine by Dosage Form Menu -------------------\n\n");

            // Enter dosage form of medicine to find
            centerText("Enter dosage form of medicine to find : ");
            string dosageForm;
            getline(cin, dosageForm);

            // Find this medicine from database and datastructure
            cout << "\n";
            findAllMedicinesFromDatastructureByDosage_Form(dosageForm);
        }
        else if (findChoiceInt == 5)
        {
            // Find a medicine by Strength(mg)
            centerText("------------------- Find a medicine by Strength(mg) Menu -------------------\n\n");

            // Enter Strength(mg) of medicine to find
            centerText("Enter Strength(mg) of medicine to find : ");
            string Strength_mg;
            getline(cin, Strength_mg);
            while (!isInteger(Strength_mg) || stoi(Strength_mg) < 0)
            {
                cout << "\n";
                centerText("Warning : Invalid year!\n");
                centerText("Please enter a number.\n");
                centerText("Enter Strength(mg) of medicine to find : ");
                getline(cin, Strength_mg);
            }

            // Find this medicine from database and datastructure
            cout << "\n";
            findAllMedicinesFromDatastructureByStrength_mg(stoi(Strength_mg));
        }
        else
        {
            // Find a medicine by Manufacturer
            centerText("------------------- Find a medicine by Manufacturer Menu -------------------\n\n");

            // Enter Manufacturer of medicine to find
            centerText("Enter Manufacturer of medicine to find : ");
            string Manufacturer;
            getline(cin, Manufacturer);

            // Find this medicine from database and datastructure
            cout << "\n";
            findAllMedicinesFromDatastructureByManufacturer(Manufacturer);
        }
        cout << "\n";
    }
}