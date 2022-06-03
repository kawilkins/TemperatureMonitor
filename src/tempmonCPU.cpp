/*==============================================================
Program:  CPU Temperature Monitor
Version:  0.1.1
Version Date:  06/02/2022
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
    double tempLong = stod(sysTemp); // Convert string to double
    double tempCelsius = tempLong / 1000; // Convert output to human readable
    double tempFahrenheit = tempCelsius * (9/5) + 32; // Convert to Fahrenheit
    double tempKelvin = tempCelsius + 273.15; // Convert to Kelvin
    setprecision(3); // Use 3 significant digits

    // Read in /sys/.../temp file
    thermal.open ("/sys/class/thermal/thermal_zone0/temp", ios::in);

    // Check if file is open and output in human readable format
    if (thermal.is_open())
    {
        // Write output of file to sysTemp variable
        while (getline (thermal, sysTemp))
        {
            // Output to human readable format
            cout << "   System temperature (Celsius):  " << tempCelsius << " \u00B0C\n"
                 << "System temperature (Fahrenheit):  " << tempFahrenheit << " \u00B0F\n"
                 << "    System temperature (Kelvin):  " << tempKelvin << " K\n";
        }
        thermal.close();
    }
    else
    {
        cout << "Failure to open '/sys/class/thermal/thermal_zone0/temp'\n"
             << "Please try again . . .\n\n";
    }

    // Exit program without errors
    return 0;
}