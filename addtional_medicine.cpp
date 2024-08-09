#include "function.h"

// Check if the ID of medicine has been used
bool isIDOfMedicineUsed(int id)
{
    // Binary search to check if the ID of medicine has been used
    int left = 0;
    int right = n - 1;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        if (medicines[mid].id == id)
        {
            return true;
        }
        else if (medicines[mid].id < id)
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

// Add one medicine to datastructure
void addOneMedicineToDatastructure(int id, string name, string category, string Dosage_Form, int Strength_mg, string Indication, string Manufacturer, int remaining)
{
    // Add one medicine to datastructure
    medicines[n].id = id;
    medicines[n].name = name;
    medicines[n].category = category;
    medicines[n].dosage_form = Dosage_Form;
    medicines[n].strength_mg = Strength_mg;
    medicines[n].indication = Indication;
    medicines[n].manufacturer = Manufacturer;
    medicines[n].remaining = remaining;
    n++;
    sort(medicines, medicines + n, [](const MedicinesObject &a, const MedicinesObject &b) {
        return a.id < b.id;
    });
}

// Delete one medicine from datastructure
void deleteOneMedicineFromDatastructure(int id)
{
    // Delete one medicine from datastructure
    for (int i = 0; i < n; i++)
    {
        if (medicines[i].id == id)
        {
            for (int j = i; j < n - 1; j++)
            {
                medicines[j] = medicines[j + 1];
            }
            n--;
            break;
        }
    }
}

// Find one medicine from datastructure by ID
void findOneMedicineFromDatastructureByID(int id)
{
    // Binary search to find one medicine from datastructure by ID
    int left = 0;
    int right = n - 1;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        if (medicines[mid].id == id)
        {
            centerText("The medicine you search : " + to_string(medicines[mid].id) + " - " + medicines[mid].name + " - " + medicines[mid].category + " - " + medicines[mid].dosage_form + " - " + to_string(medicines[mid].strength_mg) + " - " + medicines[mid].indication + " - " + medicines[mid].manufacturer + " - " + to_string(medicines[mid].remaining));
            cout << "\n\n";
            system("pause");
            return;
        }
        else if (medicines[mid].id < id)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
}

// Find all medicines from datastructure by name
void findAllMedicinesFromDatastructureByName(string name)
{
    // Find all medicines from datastructure by name
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (medicines[i].name == name)
        {
            centerText("The medicine you search : " + to_string(medicines[i].id) + " - " + medicines[i].name + " - " + medicines[i].category + " - " + medicines[i].dosage_form + " - " + to_string(medicines[i].strength_mg) + " - " + medicines[i].indication + " - " + medicines[i].manufacturer + " - " + to_string(medicines[i].remaining));
            count++;
        }
    }
    if (count == 0)
    {
        centerText("The medicine you search is not found!\n");
    }
    cout << "\n";
    system("pause");
}

// Find all medicines from datastructure by category
void findAllMedicinesFromDatastructureByCategory(string category)
{
    // Find all medicines from datastructure by category
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (medicines[i].category == category)
        {
            centerText("The medicine you search : " + to_string(medicines[i].id) + " - " + medicines[i].name + " - " + medicines[i].category + " - " + medicines[i].dosage_form + " - " + to_string(medicines[i].strength_mg) + " - " + medicines[i].indication + " - " + medicines[i].manufacturer + " - " + to_string(medicines[i].remaining));
            count++;
        }
    }
    if (count == 0)
    {
        centerText("The medicine you search is not found!\n");
    }
    cout << "\n";
    system("pause");
}

// Find all medicines from datastructure by original language
void findAllMedicinesFromDatastructureByDosage_Form(string Dosage_Form)
{
    // Find all medicines from datastructure by Dosage_Form
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (medicines[i].dosage_form == Dosage_Form)
        {
            centerText("The medicine you search : " + to_string(medicines[i].id) + " - " + medicines[i].name + " - " + medicines[i].category + " - " + medicines[i].dosage_form + " - " + to_string(medicines[i].strength_mg) + " - " + medicines[i].indication + " - " + medicines[i].manufacturer + " - " + to_string(medicines[i].remaining));
            count++;
        }
    }
    if (count == 0)
    {
        centerText("The medicine you search is not found!\n");
    }
    cout << "\n";
    system("pause");
}

// Find all medicines from datastructure by Strength(mg)
void findAllMedicinesFromDatastructureByStrength_mg(int Strength_mg)
{
    // Find all medicines from datastructure by Strength_mg
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (medicines[i].strength_mg == Strength_mg)
        {
            centerText("The medicine you search : " + to_string(medicines[i].id) + " - " + medicines[i].name + " - " + medicines[i].category + " - " + medicines[i].dosage_form + " - " + to_string(medicines[i].strength_mg) + " - " + medicines[i].indication + " - " + medicines[i].manufacturer + " - " + to_string(medicines[i].remaining));
            count++;
        }
    }
    if (count == 0)
    {
        centerText("The medicine you search is not found!\n");
    }
    cout << "\n";
    system("pause");
}

// Find all medicines from datastructure by Manufacturer
void findAllMedicinesFromDatastructureByManufacturer(string Manufacturer)
{
    // Find all medicines from datastructure by Manufacturer
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (medicines[i].manufacturer == Manufacturer)
        {
            centerText("The medicine you search : " + to_string(medicines[i].id) + " - " + medicines[i].name + " - " + medicines[i].category + " - " + medicines[i].dosage_form + " - " + to_string(medicines[i].strength_mg) + " - " + medicines[i].indication + " - " + medicines[i].manufacturer + " - " + to_string(medicines[i].remaining));
            count++;
        }
    }
    if (count == 0)
    {
        centerText("The medicine you search is not found!\n");
    }
    cout << "\n";
    system("pause");
}