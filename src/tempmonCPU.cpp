/*==============================================================
Program:  CPU Temperature Monitor
Version:  0.1.2
Version Date:  07/22/2022
Author:  Kevin Wilkins
Date:  02/05/2022
Parameters:
This application will read out CPU temperature data from 
'/sys/class/thermal/thermal_zone0/temp' file on Linux and will
convert output to human readable format in degrees Celsius, 
degrees Fahrenheit, and Kelvin.
==============================================================*/

// Preprocessor directives and namespace usage
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;

// Main function
int main()
{
    ifstream thermal;
    string sysTemp = ""; // Will store the output of thermal
    setprecision(3); // Use 3 significant digits

    // Read in /sys/.../temp file
    // Point read pointer to beginning of file
    thermal.open ("/sys/class/thermal/thermal_zone0/temp", ios::in);

    // Check if file is open and output in human readable format
    if (thermal.is_open())
    {
        while (getline (thermal, sysTemp))
        {
            // Convert output
            double tempLong = stod(sysTemp); // Convert string to double
            double tempCelsius = tempLong / 1000; // Convert output to human readable
            double tempFahrenheit = (tempCelsius * 1.8) + 32; // Convert to Fahrenheit
            double tempKelvin = tempCelsius + 273.15; // Convert to Kelvin
            
            // Output to human readable format
            cout << "System temperature:  " << tempCelsius << " \u00B0C\n"
                 << "                     " << tempFahrenheit << " \u00B0F\n"
                 << "                     " << tempKelvin << " K\n";
        }
        thermal.close();
    }
    else // File does not open
    {
        cout << "Failure to open '/sys/class/thermal/thermal_zone0/temp'\n"
             << "Please try again . . .\n\n";
    }

    // Exit program without errors
    return 0;
}
