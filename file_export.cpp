#include "function.h"

// Export all info users from datastructure to data_information.csv
void exportInfoUsers()
{
    // Export all info users from datastructure to data_information.csv
    ofstream file;
    file.open("data_information.csv");
    file << temple1 << "\n";
    for (int i = 0; i < k; i++)
    {
        file << infoUsers[i].id << "," << infoUsers[i].name << "," << infoUsers[i].age << "," << infoUsers[i].gender << "," << infoUsers[i].race << "," << infoUsers[i].diagnosis << "," << infoUsers[i].body_part << "," << infoUsers[i].disposition << "," << infoUsers[i].location << "," << infoUsers[i].product << "," << infoUsers[i].stat_weight << "," << infoUsers[i].stratum;
        if (i != k - 1)
        {
            file << "\n";
        }
    }
    file.close();
}

// Export all users from datastructre to users_dataset.csv
void exportUsers()
{
    // Export all users from datastructure to users_dataset.csv
    ofstream file;
    file.open("data_users.csv");
    file << temple2 << "\n";
    for (int i = 0; i < m; i++)
    {
        file << users[i].id << "," << users[i].name;
        for (int j = 0; j < users[i].medical_examinationsCount; j++)
        {
            file << "," << users[i].medical_examinations[j].first << "," << users[i].medical_examinations[j].second.date << "/" << users[i].medical_examinations[j].second.month << "/" << users[i].medical_examinations[j].second.year;
        }
        if (i != m - 1)
        {
            file << "\n";
        }
    }
    file.close();
}

// Export all medicines from datastructure to data_medicines.csv
void exportMedicines()
{
    // Export all medicines from datastructure to data_medicines.csv
    ofstream file;
    file.open("data_medicines.csv");
    file << temple3 << "\n";
    for (int i = 0; i < n; i++)
    {
        file << medicines[i].id << "," << medicines[i].name << "," << medicines[i].category << "," << medicines[i].dosage_form << "," << medicines[i].strength_mg << "," << medicines[i].indication << ",";
        
        int j = 0;
        for ( ; j < medicines[i].manufacturer.size(); j++)
        {
            if (medicines[i].manufacturer[j] == ',')
            {
                file << "\"" << medicines[i].manufacturer << "\"";
                break;
            }
        }
        
        if (j == medicines[i].manufacturer.size())
        {
            file << medicines[i].manufacturer;
        }

        file << "," << medicines[i].remaining;
        if (i != n - 1)
        {
            file << "\n";
        }
    }
    file.close();
}