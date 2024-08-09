#include "function.h"

void patientHealthManagementMenu(string &patientChoice, int &patientChoiceInt)
{
    system("cls");
    centerText("------------------- Patient Information Management Menu -------------------\n\n");
    centerText("1. Add a patient information.\n");
    centerText("2. Delete a patient information.\n");
    centerText("3. Find and edit a patient information.\n");
    centerText("4. Return to Main Menu.\n\n");

    centerText("Select one to continue the application.\n");
    centerText("Enter your choice (Choose a number from 1 to 4) : ");
    
    getline(cin, patientChoice);

    while (!isInteger(patientChoice) || stoi(patientChoice) < 1 || stoi(patientChoice) > 4)
    {
        cout << "\n";
        centerText("Warning : Invalid choice!\n");
        centerText("Please enter a number between 1 and 4.\n");
        centerText("Enter your choice (Choose a number from 1 to 4) : ");
        getline(cin, patientChoice);
    }

    cout << "\n";
    system("cls");

    // Layer 2 menu
    patientChoiceInt = stoi(patientChoice);
    if (patientChoiceInt == 1)
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

        // Enter age of user
        centerText("Enter age of patient : ");
        string age;
        getline(cin, age);
        while (!isInteger(age) || stoi(age) < 0)
        {
            cout << "\n";
            centerText("Warning : Invalid age!\n");
            centerText("Please enter a number greater than or equal to 0.\n");
            centerText("Enter age of patient : ");
            getline(cin, age);
        }

        // Enter gender of user
        centerText("Enter gender of patient : ");
        string gender;
        getline(cin, gender);

        // Enter race of user
        centerText("Enter race of patient : ");
        string race;
        getline(cin, race); 

        // Enter diagnosis of user
        centerText("Enter diagnosis of patient : ");
        string diagnosis;
        getline(cin, diagnosis);
        while (!isInteger(diagnosis) || stoi(diagnosis) < 0)
        {
            cout << "\n";
            centerText("Warning : Invalid diagnosis!\n");
            centerText("Please enter a number greater than or equal to 0.\n");
            centerText("Enter diagnosis of patient : ");
            getline(cin, diagnosis);
        }

        // Enter body part of user
        centerText("Enter body part of patient : ");
        string body_part;
        getline(cin, body_part);
        while (!isInteger(body_part) || stoi(body_part) < 0)
        {
            cout << "\n";
            centerText("Warning : Invalid body part!\n");
            centerText("Please enter a number greater than or equal to 0.\n");
            centerText("Enter body part of patient : ");
            getline(cin, body_part);
        }

        // Enter disposition of user
        centerText("Enter disposition of patient : ");
        string disposition;
        getline(cin, disposition);
        while (!isInteger(disposition) || stoi(disposition) < 0)
        {
            cout << "\n";
            centerText("Warning : Invalid disposition!\n");
            centerText("Please enter a number greater than or equal to 0.\n");
            centerText("Enter disposition of patient : ");
            getline(cin, disposition);
        }

        // Enter location of user
        centerText("Enter location of patient : ");
        string location;
        getline(cin, location);
        while (!isInteger(location) || stoi(location) < 0)
        {
            cout << "\n";
            centerText("Warning : Invalid location!\n");
            centerText("Please enter a number greater than or equal to 0.\n");
            centerText("Enter location of patient : ");
            getline(cin, location);
        }

        // Enter product of user
        centerText("Enter product of patient : ");
        string product;
        getline(cin, product);
        while (!isInteger(product) || stoi(product) < 0)
        {
            cout << "\n";
            centerText("Warning : Invalid product!\n");
            centerText("Please enter a number greater than or equal to 0.\n");
            centerText("Enter product of patient : ");
            getline(cin, product);
        }

        // Enter stat_weight of user
        centerText("Enter stat_weight of patient : ");
        string stat_weight;
        getline(cin, stat_weight);
        while (!isFloat(stat_weight) || stof(stat_weight) < 0)
        {
            cout << "\n";
            centerText("Warning : Invalid stat_weight!\n");
            centerText("Please enter a number greater than or equal to 0.\n");
            centerText("Enter stat_weight of patient : ");
            getline(cin, stat_weight);
        }

        // Enter stratum of user
        centerText("Enter stratum of patient : ");
        string stratum;
        getline(cin, stratum);

        // Add this user to database and datastructure
        addOnePatientToDatastructure(stoi(id), name, stoi(age), gender, race, stoi(diagnosis), stoi(body_part), stoi(disposition), stoi(location), stoi(product), stof(stat_weight), stratum);

        cout << "\n";
        centerText("Has been added successfully.\n");
        cout << "\n";

        system("pause");
    }
    else if (patientChoiceInt == 2)
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
        deleteOnePatientFromDatastructure(stoi(id));

        cout << "\n";
        centerText("Has been deleted successfully.\n");
        cout << "\n";
        system("pause");
    }
    else if (patientChoiceInt == 3)
    {
        // Find a user
        centerText("------------------- Find and edit a patient information Menu -------------------\n\n");

        string id;
        centerText("Enter the ID of the patient you want to find and edit : ");
        getline(cin, id);
        while (!isInteger(id) || stoi(id) < 1000 || stoi(id) > 9999 || !isIDOfUserUsed(stoi(id)))
        {
            cout << "\n";
            centerText("Warning : The ID is not found or you did not enter ID in the correct format!\n");
            centerText("Please enter a number. (In case you don't know ID. Enter \"Exit\" to return).\n");
            centerText("Enter the ID of the patient you want to find and edit :");
            getline(cin, id);
            if (id == "Exit")
            {
                cout << "\n";
                return;
            }
        }

        int index = findIndexPatientInDatastructure(stoi(id));

        cout << "\n";

        // Selection of finding a user
        centerText("1. Edit an ID of patient.\n");
        centerText("2. Edit a name of patient.\n");
        centerText("3. Edit an age of patient.\n");
        centerText("4. Edit gender of patient.\n");
        centerText("5. Edit race of patient.\n");
        centerText("6. Edit diagnosis of patient.\n");
        centerText("7. Edit body part of patient.\n");
        centerText("8. Edit disposition of patient.\n");
        centerText("9. Edit location of patient.\n");
        centerText("10. Edit product of patient.\n");
        centerText("11. Edit stat_weight of patient.\n");
        centerText("12. Edit stratum of patient.\n");

        centerText("Select one to continue the application.\n");
        centerText("Enter your choice (Choose a number from 1 to 12) : ");

        string findChoice;
        getline(cin, findChoice);
        while (!isInteger(findChoice) || stoi(findChoice) < 1 || stoi(findChoice) > 12)
        {
            cout << "\n";
            centerText("Warning : Invalid choice!\n");
            centerText("Please enter a number between 1 and 12.\n");
            centerText("Enter your choice (Choose a number from 1 to 12) : ");
            getline(cin, findChoice);
        }

        cout << "\n";
        
        int findChoiceInt = stoi(findChoice);
        if (findChoiceInt == 1)
        {
            // Edit a user by ID
            centerText("Enter ID of patient to edit (4 digits) : ");
            string id;
            getline(cin, id);
            while (!isInteger(id) || stoi(id) < 1000 || stoi(id) > 9999 || !isIDOfUserUsed(stoi(id)))
            {
                cout << "\n";
                centerText("Warning : The ID is not found or you did not enter ID in the correct format!\n");
                centerText("Please enter a number. (In case you don't know ID. Enter \"Exit\" to return).\n");
                centerText("Enter ID of patient to edit (4 digits) : ");
                getline(cin, id);
                if (id == "Exit")
                {
                    cout << "\n";
                    return;
                }
            }

            // Edit this user from database and datastructure
            infoUsers[index].id = stoi(id);
            cout << "ID has been edited successfully.\n";
            cout << "\n";
        }
        else if (findChoiceInt == 2)
        {
            // Edit a user by name
            centerText("Enter name of patient to edit : ");
            string name;
            getline(cin, name);

            // Edit this user from database and datastructure
            infoUsers[index].name = name;
            cout << "Name has been edited successfully.\n";
            cout << "\n";
        }
        else if (findChoiceInt == 3)
        {
            // Edit a user by age
            centerText("Enter age of patient to edit : ");
            string age;
            getline(cin, age);
            while (!isInteger(age) || stoi(age) < 0)
            {
                cout << "\n";
                centerText("Warning : Invalid age!\n");
                centerText("Please enter a number greater than or equal to 0.\n");
                centerText("Enter age of patient : ");
                getline(cin, age);
            }

            // Edit this user from database and datastructure
            infoUsers[index].age = stoi(age);
            cout << "Age has been edited successfully.\n";
            cout << "\n";
        }
        else if (findChoiceInt == 4)
        {
            // Edit a user by gender
            centerText("Enter gender of patient to edit : ");
            string gender;
            getline(cin, gender);

            // Edit this user from database and datastructure
            infoUsers[index].gender = gender;
            cout << "Gender has been edited successfully.\n";
            cout << "\n";
        }
        else if (findChoiceInt == 5)
        {
            // Edit a user by race
            centerText("Enter race of patient to edit : ");
            string race;
            getline(cin, race);

            // Edit this user from database and datastructure
            infoUsers[index].race = race;
            cout << "Race has been edited successfully.\n";
            cout << "\n";
        }
        else if (findChoiceInt == 6)
        {
            // Edit a user by diagnosis
            centerText("Enter diagnosis of patient to edit : ");
            string diagnosis;
            getline(cin, diagnosis);
            while (!isInteger(diagnosis) || stoi(diagnosis) < 0)
            {
                cout << "\n";
                centerText("Warning : Invalid diagnosis!\n");
                centerText("Please enter a number greater than or equal to 0.\n");
                centerText("Enter diagnosis of patient : ");
                getline(cin, diagnosis);
            }

            // Edit this user from database and datastructure
            infoUsers[index].diagnosis = stoi(diagnosis);
            cout << "Diagnosis has been edited successfully.\n";
            cout << "\n";
        }
        else if (findChoiceInt == 7)
        {
            // Edit a user by body part
            centerText("Enter body part of patient to edit : ");
            string body_part;
            getline(cin, body_part);
            while (!isInteger(body_part) || stoi(body_part) < 0)
            {
                cout << "\n";
                centerText("Warning : Invalid body part!\n");
                centerText("Please enter a number greater than or equal to 0.\n");
                centerText("Enter body part of patient : ");
                getline(cin, body_part);
            }

            // Edit this user from database and datastructure
            infoUsers[index].body_part = stoi(body_part);
            cout << "Body part has been edited successfully.\n";
            cout << "\n";
        }
        else if (findChoiceInt == 8)
        {
            // Edit a user by disposition
            centerText("Enter disposition of patient to edit : ");
            string disposition;
            getline(cin, disposition);
            while (!isInteger(disposition) || stoi(disposition) < 0)
            {
                cout << "\n";
                centerText("Warning : Invalid disposition!\n");
                centerText("Please enter a number greater than or equal to 0.\n");
                centerText("Enter disposition of patient : ");
                getline(cin, disposition);
            }

            // Edit this user from database and datastructure
            infoUsers[index].disposition = stoi(disposition);
            cout << "Disposition has been edited successfully.\n";
        }
        else if (findChoiceInt == 9)
        {
            // Edit a user by location
            centerText("Enter location of patient to edit : ");
            string location;
            getline(cin, location);
            while (!isInteger(location) || stoi(location) < 0)
            {
                cout << "\n";
                centerText("Warning : Invalid location!\n");
                centerText("Please enter a number greater than or equal to 0.\n");
                centerText("Enter location of patient : ");
                getline(cin, location);
            }

            // Edit this user from database and datastructure
            infoUsers[index].location = stoi(location);
            cout << "Location has been edited successfully.\n";
        }
        else if (findChoiceInt == 10)
        {
            // Edit a user by product
            centerText("Enter product of patient to edit : ");
            string product;
            getline(cin, product);
            while (!isInteger(product) || stoi(product) < 0)
            {
                cout << "\n";
                centerText("Warning : Invalid product!\n");
                centerText("Please enter a number greater than or equal to 0.\n");
                centerText("Enter product of patient : ");
                getline(cin, product);
            }

            // Edit this user from database and datastructure
            infoUsers[index].product = stoi(product);
            cout << "Product has been edited successfully.\n";
        }
        else if (findChoiceInt == 11)
        {
            // Edit a user by stat_weight
            centerText("Enter stat_weight of patient to edit : ");
            string stat_weight;
            getline(cin, stat_weight);
            while (!isFloat(stat_weight) || stof(stat_weight) < 0)
            {
                cout << "\n";
                centerText("Warning : Invalid stat_weight!\n");
                centerText("Please enter a number greater than or equal to 0.\n");
                centerText("Enter stat_weight of patient : ");
                getline(cin, stat_weight);
            }

            // Edit this user from database and datastructure
            infoUsers[index].stat_weight = stof(stat_weight);
            cout << "Stat_weight has been edited successfully.\n";
        }
        else
        {
            // Edit a user by stratum
            centerText("Enter stratum of patient to edit : ");
            string stratum;
            getline(cin, stratum);

            // Edit this user from database and datastructure
            infoUsers[index].stratum = stratum;
            cout << "Stratum has been edited successfully.\n";
        }
    }
}