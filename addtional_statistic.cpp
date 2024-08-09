#include "function.h"

// Show all statistics in the system
void showAllStatisticsInTheSystem()
{
    int numberOfMale = 0;
    int numberOfFemale = 0;
    int averageAge = 0;
    int numberOfAsian = 0;
    int numberOfBlack = 0;
    int numberOfWhite = 0;
    int avarageStatWeight = 0;
    for (int i = 0; i < k; i++)
    {   
        if (infoUsers[i].gender == "Male")
        {
            numberOfMale++;
        }
        else
        {
            numberOfFemale++;
        }
        averageAge += infoUsers[i].age;
        if (infoUsers[i].race == "Asian")
        {
            numberOfAsian++;
        }
        else if (infoUsers[i].race == "Black")
        {
            numberOfBlack++;
        }
        else if (infoUsers[i].race == "White")
        {
            numberOfWhite++;
        }
        avarageStatWeight += infoUsers[i].stat_weight;
    }

    unordered_map<string, int> disease;

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < users[i].medical_examinationsCount; j++)
        {
            if (disease.find(users[i].medical_examinations[j].first) == disease.end())
            {
                disease[users[i].medical_examinations[j].first] = 1;
            }
            else
            {
                disease[users[i].medical_examinations[j].first]++;
            }
        }
    }

    centerText("Total number of male : " + to_string(numberOfMale) + "\n");
    centerText("Total number of female : " + to_string(numberOfFemale) + "\n");
    centerText("Total number of other gender : " + to_string(k - numberOfMale - numberOfFemale) + "\n");
    centerText("Average age : " + to_string(averageAge / k) + "\n");
    centerText("Total number of Asian : " + to_string(numberOfAsian) + "\n");
    centerText("Total number of Black : " + to_string(numberOfBlack) + "\n");
    centerText("Total number of White : " + to_string(numberOfWhite) + "\n");
    centerText("Total number of Other : " + to_string(k - numberOfAsian - numberOfBlack - numberOfWhite) + "\n");
    centerText("Average stat weight : " + to_string(avarageStatWeight / k) + "\n");
    centerText("Total number of diseases : " + to_string(disease.size()) + "\n");
    centerText("The most common disease : " + max_element(disease.begin(), disease.end(), [](const pair<string, int> &a, const pair<string, int> &b) { return a.second < b.second; })->first + "\n");
}