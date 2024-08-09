#include "function.h"   

// Check if a string is an integer
bool isInteger(string str) 
{
    if (str.empty() || (str[0] != '-' && !isdigit(str[0]))) 
    {
        return false;
    }

    for (int i = 1; i < str.size(); ++i) 
    {
        if (!isdigit(str[i])) 
        {
            return false;
        }
    }

    return true;
}

// Check if a string is a float
bool isFloat(string str) 
{
    if (str.empty() || (str[0] != '-' && str[0] != '.' && !isdigit(str[0]))) 
    {
        return false;
    }

    for (int i = 1; i < str.size(); ++i) 
    {
        if (!isdigit(str[i]) && str[i] != '.') 
        {
            return false;
        }
    }

    return true;
}