#include "function.h"

// Setting Menu
void settingMenu(string &settingChoice, int &settingChoiceInt)
{   
    system("cls");
    centerText("------------------- Setting Menu -------------------\n\n");
    centerText("1. Contact us.\n");
    centerText("2. Return to Main Menu.\n\n");

    centerText("Select one to continue the application.\n");
    centerText("Enter your choice (Choose a number from 1 to 2) : ");
    
    getline(cin, settingChoice);

    while (!isInteger(settingChoice) || stoi(settingChoice) < 1 || stoi(settingChoice) > 2)
    {
        cout << "\n";
        centerText("Warning : Invalid choice!\n");
        centerText("Please enter a number between 1 and 2.\n");
        centerText("Enter your choice (Choose a number from 1 to 2) : ");
        getline(cin, settingChoice);
    }

    cout << "\n";
    system("cls");

    // Layer 2 menu
    settingChoiceInt = stoi(settingChoice);
    if (settingChoiceInt == 1)
    {
        // Contact us
        centerText("------------------- Contact us Menu -------------------\n\n");

        // Print the contact information
        centerText("Team : Our Team\n");
        centerText("Email : example@gmail.com\n");
        centerText("Phone number : 0123456789\n");
        centerText("Address : 227 Nguyen Van Cu, Ward 4, District 5, Ho Chi Minh City, Viet Nam\n");

        cout << "\n";
        system("pause");
    }
}