/*==============================================================
Program:  CPU Temperature Monitor
Version:  0.1.0
Version Date:  02/05/2022
Author:  Kevin Wilkins
Date:  02/05/2022
Parameters:
This application will read out CPU temperature data from 
'/sys/class/thermal/thermal_zone0/temp' file on Linux and will
convert output to human readable format.
==============================================================*/

// Preprocessor directives and namespace usage
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;

// Function Prototypes
string Thermal();

// Main function
int main()
{
    string sysTemp = 0; // Will store the output of sysThermal
    
    // Use Thermal function to get system thermal info
    Thermal(sysTemp);

    // Output to human readable format
    double tempHumanRead = 0;
    double tempLong = stod(sysTemp); // Convert string to double
    setprecision(3);

    tempHumanRead = tempLong / 1000;
    cout << "System temperature:  " << tempHumanRead << " \u00B0C\n\n";
    
    // Exit program without errors
    return 0;
}

// Get thermal information from system
string Thermal(string sysTemp)
{
    ifstream thermal ("/sys/class/thermal/thermal_zone0/temp");

    // Check if file is open and send information to variable
    if (thermal.is_open())
    {
        // Write output of file to sysTemp variable
        while (getline (thermal, sysTemp))
        {
            thermal >> sysTemp;
        }
        thermal.close();
    }
    else
    {
        cout << "Failure to open '/sys/class/thermal/thermal_zone0/temp'\n"
             << "Please try again . . .\n\n";
    }

    return sysTemp;
}