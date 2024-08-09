#include "function.h"

// Import Info Users function
void importInfoUsers()
{
    // Import all info users from data_information.csv to database and datastructure
    ifstream file("data_information.csv");

    // Check if the file is opened successfully
    if (!file.is_open())
    {
        centerText("Error: File cannot be opened!\n");
        return;
    }

    // Read the first line
    string line;
    getline(file, temple1);

    // Read the rest of the lines and import to InfoUsersObject
    while (!file.eof())
    {   
        // Read a line
        getline(file, line);

        // Define temp string and count variable
        string temp = "";
        int count = 0;

        // Read each character of the line
        for (int i = 0; i < line.size(); i++)
        {   
            // Check if the character is a comma
            if (line[i] == ',')
            {
                count++;
                if (count == 1)
                {
                    infoUsers[k].id = stoi(temp);
                }
                else if (count == 2)
                {
                    infoUsers[k].name = temp;
                }
                else if (count == 3)
                {
                    infoUsers[k].age = stoi(temp);
                }
                else if (count == 4)
                {
                    infoUsers[k].gender = temp;
                }
                else if (count == 5)
                {
                    infoUsers[k].race = temp;
                }
                else if (count == 6)
                {
                    infoUsers[k].diagnosis = stoi(temp);
                }
                else if (count == 7)
                {
                    infoUsers[k].body_part = stoi(temp);
                }
                else if (count == 8)
                {
                    infoUsers[k].disposition = stoi(temp);
                }
                else if (count == 9)
                {
                    infoUsers[k].location = stoi(temp);
                }
                else if (count == 10)
                {
                    infoUsers[k].product = stoi(temp);
                }
                else if (count == 11)
                {
                    infoUsers[k].stat_weight = stof(temp);
                }
                else
                {
                    infoUsers[k].stratum = temp;
                }
                temp = "";
            }
            else
            {
                temp += line[i];
            }
        }
        k++;
    }
    file.close();
}

// Import Users function
void importUsers()
{
    // Import all users from data_users.csv to database and datastructure
    ifstream file("data_users.csv");

    // Check if the file is opened successfully
    if (!file.is_open())
    {
        centerText("Error: File cannot be opened!\n");
        return;
    }

    // Read the first line
    string line;
    getline(file, temple2);

    // Read the rest of the lines and import to UsersObject
    while (!file.eof())
    {   
        // Read a line
        getline(file, line);

        // Define temp string and count variable
        string temp = "";
        int count = 0;

        // Bool variable to check id or date
        bool checkIDOrDate = true;

        // Read each character of the line
        for (int i = 0; i < line.size(); i++)
        {
            if (line[i] == ',' || i == line.size() - 1)
            {   
                if (i == line.size() - 1)
                {
                    temp += line[i];
                }
                count++;
                if (count == 1)
                {
                    users[m].id = stoi(temp);
                }
                else if (count == 2)
                {
                    users[m].name = temp;
                }
                else
                {
                    if (checkIDOrDate)
                    {
                        users[m].medical_examinations[users[m].medical_examinationsCount].first = temp;
                        checkIDOrDate = false;
                    }
                    else
                    {
                        // Read date
                        string date = "";
                        string month = "";
                        string year = "";
                        int countDateMonthYear = 0;
                        for (int j = 0; j < temp.size(); j++)
                        {
                            if (temp[j] == '/')
                            {
                                countDateMonthYear++;
                            }
                            else
                            {
                                if (countDateMonthYear == 0)
                                {
                                    date += temp[j];
                                }
                                else if (countDateMonthYear == 1)
                                {
                                    month += temp[j];
                                }
                                else
                                {
                                    year += temp[j];
                                }
                            }
                        }
                        users[m].medical_examinations[users[m].medical_examinationsCount].second.date = stoi(date);
                        users[m].medical_examinations[users[m].medical_examinationsCount].second.month = stoi(month);
                        users[m].medical_examinations[users[m].medical_examinationsCount].second.year = stoi(year);
                        users[m].medical_examinationsCount++;
                        checkIDOrDate = true;
                    }
                }
                temp = "";
            }
            else
            {
                temp += line[i];
            }
        }
        m++;
    }
    file.close();
}

// Import medicines function
void importMedicines()
{
    // Import all medicines from data_medicines.csv to database and datastructure
    ifstream file("data_medicines.csv");

    // Check if the file is opened successfully
    if (!file.is_open())
    {
        centerText("Error: File cannot be opened!\n");
        return;
    }

    // Read the first line
    string line;
    getline(file, temple3);

    // Read the rest of the lines and import to MedicinesObject
    while (!file.eof())
    {   
        // Read a line
        getline(file, line);

        // Define temp string and count variable
        string temp = "";
        int count = 0;

        // Read each character of the line
        for (int i = 0; i < line.size(); i++)
        {
            if (line[i] == ',')
            {
                count++;
                if (count == 1)
                {
                    medicines[n].id = stoi(temp);
                }
                else if (count == 2)
                {
                    medicines[n].name = temp;
                }
                else if (count == 3)
                {
                    medicines[n].category = temp;
                }
                else if (count == 4)
                {
                    medicines[n].dosage_form = temp;
                }
                else if (count == 5)
                {
                    medicines[n].strength_mg = stoi(temp);
                }
                else if (count == 6)
                {
                    medicines[n].indication = temp;
                }
                else if (count == 7)
                {
                    medicines[n].manufacturer = temp;
                }
                temp = "";
                if (line[i + 1] == '"')
                {
                    i += 2;
                    while (line[i] != '"')
                    {
                        temp += line[i];
                        i++;
                    }
                }
            }
            else
            {
                temp += line[i];
            }
        }
        // Read the last element of the line
        medicines[n].remaining = stoi(temp);
        n++;
    }
    file.close();
}
