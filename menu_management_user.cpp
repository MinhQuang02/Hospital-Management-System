#include "function.h"

// User Management Menu
void userManagementMenu(string &userChoice, int &userChoiceInt)
{   
    system("cls");
    centerText("------------------- Patient Management Menu -------------------\n\n");
    centerText("1. Add a patient.\n");
    centerText("2. Delete a patient.\n");
    centerText("3. Find a patient.\n");
    centerText("4. Show patients whose have that disease.\n");
    centerText("5. Return to Main Menu.\n\n");

    centerText("Select one to continue the application.\n");
    centerText("Enter your choice (Choose a number from 1 to 5) : ");
    
    getline(cin, userChoice);

    while (!isInteger(userChoice) || stoi(userChoice) < 1 || stoi(userChoice) > 5)
    {
        cout << "\n";
        centerText("Warning : Invalid choice!\n");
        centerText("Please enter a number between 1 and 5.\n");
        centerText("Enter your choice (Choose a number from 1 to 5) : ");
        getline(cin, userChoice);
    }

    cout << "\n";
    system("cls");

    // Layer 2 menu
    userChoiceInt = stoi(userChoice);
    if (userChoiceInt == 1)
    {
        // Add a user
        centerText("------------------- Add a patient information Menu -------------------\n\n");

        // Enter ID of user
        centerText("Enter ID of patient (4 digits) : ");
        string id;
        getline(cin, id);
        while (!isInteger(id) || stoi(id) < 1000 || stoi(id) > 9999 || isIDOfUserUsed(stoi(id)))
        {
            cout << "\n";
            centerText("Warning : The ID is already used or you did not enter ID in the correct format!\n");
            centerText("Please enter a number. (In case you don't know ID. Enter \"Exit\" to return).\n");
            centerText("Enter ID of patient (4 digits) : ");
            getline(cin, id);
            if (id == "Exit")
            {
                cout << "\n";
                return;
            }
        }

        // Enter name of user
        centerText("Enter name of patient : ");
        string name;
        getline(cin, name);

        // Import this user to database and datastructure
        addOneUserToDatastructure(stoi(id), name);

        cout << "\n";
        centerText("Has been added successfully.\n");
        cout << "\n";

        system("pause");
    }
    else if (userChoiceInt == 2)
    {
        // Delete a user
        centerText("------------------- Delete a patient information Menu -------------------\n\n");

        // Enter ID of user to delete
        centerText("Enter ID of patient to delete (4 digits) : ");
        string id;
        getline(cin, id);
        while (!isInteger(id) || stoi(id) < 1000 || stoi(id) > 9999 || !isIDOfUserUsed(stoi(id))) 
        {
            cout << "\n";
            centerText("Warning : The ID is not found or you did not enter ID in the correct format!\n");
            centerText("Please enter a number. (In case you don't know ID. Enter \"Exit\" to return).\n");
            centerText("Enter ID of patient to delete (4 digits) : ");
            getline(cin, id);
            if (id == "Exit")
            {
                cout << "\n";
                return;
            }
        }

        // Delete this user from database and datastructure (Restructure the database and data structure)
        deleteOneUserFromDatastructure(stoi(id));

        cout << "\n";
        centerText("Has been deleted successfully.\n");
        cout << "\n";
        system("pause");
    }
    else if (userChoiceInt == 3)
    {
        // Find a user
        centerText("------------------- Find a patient Menu -------------------\n\n");

        // Selection of finding a user
        centerText("1. Find a patient by ID\n");
        centerText("2. Find a patient by name\n\n");

        centerText("Select one to continue the application.\n");
        centerText("Enter your choice (Choose a number from 1 to 2) : ");
        string findChoice;
        getline(cin, findChoice);
        while (!isInteger(findChoice) || stoi(findChoice) < 1 || stoi(findChoice) > 2)
        {
            cout << "\n";
            centerText("Warning : Invalid choice!\n");
            centerText("Please enter a number between 1 and 2.\n");
            centerText("Enter your choice (Choose a number from 1 to 2) : ");
            getline(cin, findChoice);
        }

        cout << "\n";
        
        int findChoiceInt = stoi(findChoice);
        if (findChoiceInt == 1)
        {
            // Find a user by ID
            centerText("Enter ID of patient to find (4 digits) : ");
            string id;
            getline(cin, id);
            while (!isInteger(id) || stoi(id) < 1000 || stoi(id) > 9999 || !isIDOfUserUsed(stoi(id)))
            {
                cout << "\n";
                centerText("Warning : The ID is not found or you did not enter ID in the correct format!\n");
                centerText("Please enter a number. (In case you don't know ID. Enter \"Exit\" to return).\n");
                centerText("Enter ID of patient to find (4 digits) : ");
                getline(cin, id);
                if (id == "Exit")
                {
                    cout << "\n";
                    return;
                }
            }

            // Find this user from database and datastructure
            cout << "\n";
            findOneUserFromDatastructureByID(stoi(id));
        }
        else
        {
            // Find a user by name
            centerText("Enter name of patient to find : ");
            string name;
            getline(cin, name);

            // Find this user from database and datastructure
            cout << "\n";
            findAllUsersFromDatastructureByName(name);
        }
    }
    else if (userChoiceInt == 4)
    {
        // Show patients whose have that disease
        centerText("------------------- Show patients whose have that disease Menu -------------------\n\n");

        // Enter disease to find
        centerText("Enter disease to find : ");
        string disease;
        getline(cin, disease);

        // Show users whose have that disease
        cout << "\n";
        showUsersWhoseHaveThatDisease(disease);
    }
}