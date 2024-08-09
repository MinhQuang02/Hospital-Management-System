#include "function.h"

// Add one user to datastructure
void addOneUserToDatastructure(int id, string name)
{
    // Add one user to datastructure
    users[m].id = id;
    users[m].name = name;
    m++;
    sort(users, users + m, [](const UsersObject &a, const UsersObject &b) {
        return a.id < b.id;
    });
}

// Delete one user from datastructure
void deleteOneUserFromDatastructure(int id)
{
    // Delete one user from datastructure
    for (int i = 0; i < m; i++)
    {
        if (users[i].id == id)
        {
            for (int j = i; j < m - 1; j++)
            {
                users[j] = users[j + 1];
            }
            m--;
            break;
        }
    }
}

// Find one user from datastructure by ID
void findOneUserFromDatastructureByID(int id)
{
    // Binary search to find one user from datastructure by ID
    int left = 0;
    int right = m - 1;
    int mid;

    while (left <= right)
    {
        mid = left + (right - left) / 2;

        if (users[mid].id == id)
        {
            centerText("The user you search : " + to_string(users[mid].id) + " - " + users[mid].name);
            for (int i = 0; i < users[mid].medical_examinationsCount; i++)
            {
                centerText("| " + users[mid].medical_examinations[i].first + " - " + to_string(users[mid].medical_examinations[i].second.date) + "/" + to_string(users[mid].medical_examinations[i].second.month) + "/" + to_string(users[mid].medical_examinations[i].second.year));
            }
            cout << "\n";
            system("pause");
            break;
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }

    system("cls");
    cout << "\n";
    centerText("------------------- Edit user information Menu -------------------\n\n");

    centerText("1. Add medical examination results.\n");
    centerText("2. Edit medical examination results.\n");
    centerText("3. Return to User Management menu.\n\n");

    centerText("Select one to continue the application.\n");
    centerText("Enter your choice (Choose a number from 1 to 3) : ");
    string editChoice;
    getline(cin, editChoice);

    while (!isInteger(editChoice) || stoi(editChoice) < 1 || stoi(editChoice) > 3)
    {
        cout << "\n";
        centerText("Warning : Invalid choice!\n");
        centerText("Please enter a number between 1 and 3.\n");
        centerText("Enter your choice (Choose a number from 1 to 3) : ");
        getline(cin, editChoice);
    }

    int editChoiceInt = stoi(editChoice);
    system("cls");
    if (editChoiceInt == 1)
    {   
        centerText("------------------- Add medical examination results Menu -------------------\n\n");

        centerText("The user you search : " + to_string(users[mid].id) + " - " + users[mid].name);
        cout << "\n";

        // Add medical examination results
        centerText("Enter the name of the disease : ");
        string disease;
        getline(cin, disease);
        centerText("Enter the date of the examination (Enter \"Today\" to default input is today) : ");
        string date;
        getline(cin, date);
        int dateInt = stoi(date);
        centerText("Enter the month of the examination (Enter \"Today\" to default input is today, only needed 1 out of 3 times) : ");
        string month;
        getline(cin, month);
        int monthInt = stoi(month);
        centerText("Enter the year of the examination (Enter \"Today\" to default input is today, only needed 1 out of 3 times) : ");
        string year;
        getline(cin, year);
        int yearInt = stoi(year);

        if (date == "Today" || month == "Today" || year == "Today")
        {
            time_t now = time(0);
            tm *ltm = localtime(&now);
            dateInt = ltm->tm_mday;
            monthInt = 1 + ltm->tm_mon;
            yearInt = 1900 + ltm->tm_year;
        }

        users[mid].medical_examinations[users[mid].medical_examinationsCount].first = disease;
        users[mid].medical_examinations[users[mid].medical_examinationsCount].second.date = dateInt;
        users[mid].medical_examinations[users[mid].medical_examinationsCount].second.month = monthInt;
        users[mid].medical_examinations[users[mid].medical_examinationsCount].second.year = yearInt;
        users[mid].medical_examinationsCount++; 

        centerText("The medical examination results have been added successfully!\n");
        cout << "\n";
        system("pause");
    }
    else if (editChoiceInt == 2)
    {
        centerText("------------------- Edit medical examination results Menu -------------------\n\n");

        centerText("The user you search : " + to_string(users[mid].id) + " - " + users[mid].name);
        cout << "\n";

        // Edit medical examination results
        centerText("Enter the name of the disease you want to edit : ");
        string disease;
        getline(cin, disease);
        centerText("Enter the date of the examination you want to edit : ");
        string date;
        getline(cin, date);
        int dateInt = stoi(date);
        centerText("Enter the month of the examination you want to edit : ");
        string month;
        getline(cin, month);
        int monthInt = stoi(month);
        centerText("Enter the year of the examination you want to edit : ");
        string year;
        getline(cin, year);
        int yearInt = stoi(year);

        for (int i = 0; i < users[mid].medical_examinationsCount; i++)
        {
            if (users[mid].medical_examinations[i].first == disease && users[mid].medical_examinations[i].second.date == dateInt && users[mid].medical_examinations[i].second.month == monthInt && users[mid].medical_examinations[i].second.year == yearInt)
            {
                centerText("Enter the new name of the disease : ");
                string newDisease;
                getline(cin, newDisease);
                centerText("Enter the new date of the examination : ");
                string newDate;
                getline(cin, newDate);
                int newDateInt = stoi(newDate);
                centerText("Enter the new month of the examination : ");
                string newMonth;
                getline(cin, newMonth);
                int newMonthInt = stoi(newMonth);
                centerText("Enter the new year of the examination : ");
                string newYear;
                getline(cin, newYear);
                int newYearInt = stoi(newYear);

                users[mid].medical_examinations[i].first = newDisease;
                users[mid].medical_examinations[i].second.date = newDateInt;
                users[mid].medical_examinations[i].second.month = newMonthInt;
                users[mid].medical_examinations[i].second.year = newYearInt;

                centerText("The medical examination results have been edited successfully!\n");
                cout << "\n";
                system("pause");
                break;
            }
        }
    }
}

// Find all users from datastructure by name
void findAllUsersFromDatastructureByName(string name)
{
    // Find all users from datastructure by name
    int count = 0;
    for (int i = 0; i < m; i++)
    {
        if (users[i].name == name)
        {
            centerText("The user you search : " + to_string(users[i].id) + " - " + users[i].name);
            for (int j = 0; j < users[i].medical_examinationsCount; j++)
            {
                centerText("| " + users[i].medical_examinations[j].first + " - " + to_string(users[i].medical_examinations[j].second.date) + "/" + to_string(users[i].medical_examinations[j].second.month) + "/" + to_string(users[i].medical_examinations[j].second.year));
            }
            cout << "\n";
            count++;
        }
    }
    if (count == 0)
    {
        centerText("The user you search is not found!\n");
    }
    cout << "\n";
    system("pause");
}

// Print all users whose books are overdue
void showUsersWhoseHaveThatDisease(string disease)
{      
    // Show users whose have that disease
    centerText("Patients whose have that disease\n");

    // Take a sign
    bool isHave = false;

    // Print all users whose have that disease
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < users[i].medical_examinationsCount; j++)
        {
            if (users[i].medical_examinations[j].first == disease)
            {
                if (!isHave)
                {   
                    cout << "\n";
                    isHave = true;
                }
                centerText("ID : " + to_string(users[i].id) + " | Name : " + users[i].name + " | Date : " + to_string(users[i].medical_examinations[j].second.date) + "/" + to_string(users[i].medical_examinations[j].second.month) + "/" + to_string(users[i].medical_examinations[j].second.year) + "\n");
            }
        }
    }
    cout << "\n";
    system("pause");
}

// Check if the ID of user has been used
bool isIDOfUserUsed(int id)
{
    // Binary search to check if the ID of user has been used
    int left = 0;
    int right = m - 1;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        if (users[mid].id == id)
        {
            return true;
        }
        else if (users[mid].id < id)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }

    return false;
}