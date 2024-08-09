#include "function.h"

// Add one patient to datastructure
void addOnePatientToDatastructure(int id, string name, int age, string gender, string race, int diagnosis, int body_part, int disposition, int location, int product, float stat_weight, string stratum)
{
    infoUsers[k].id = id;
    infoUsers[k].name = name;
    infoUsers[k].age = age;
    infoUsers[k].gender = gender;
    infoUsers[k].race = race;
    infoUsers[k].diagnosis = diagnosis;
    infoUsers[k].body_part = body_part;
    infoUsers[k].disposition = disposition;
    infoUsers[k].location = location;
    infoUsers[k].product = product;
    infoUsers[k].stat_weight = stat_weight;
    infoUsers[k].stratum = stratum;
    k++;
    sort(infoUsers, infoUsers + k, [](const InfoUsers &a, const InfoUsers &b) {
        return a.id < b.id;
    });
}

// Delete one patient from datastructure
void deleteOnePatientFromDatastructure(int id)
{
    for (int i = 0; i < k; i++)
    {
        if (infoUsers[i].id == id)
        {
            for (int j = i; j < k - 1; j++)
            {
                infoUsers[j] = infoUsers[j + 1];
            }
            k--;
            break;
        }
    }
}

// Find the index of patient in datastructure
int findIndexPatientInDatastructure(int id)
{
    int left = 0;
    int right = k - 1;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        if (infoUsers[mid].id == id)
        {
            return mid;
        }
        else if (infoUsers[mid].id < id)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }

    return -1;
}