/*==============================================================
Program:  CPU Temperature Monitor
Version:  0.2.1
Version Date:  09/06/2022
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

// Special definitions
#define DOUBLELINE "\n\n"
#define RESTORE "\033[0m" // Return to default terminal color
#define GREEN "\033[1m\033[32m" // Bold green
#define YELLOW "\033[1m\033[33m" // Bold yellow
#define RED "\033[1m\033[31m" // Bold red

// Main function
int main()
{
    ifstream thermal;
    string sysTemp = "";
    
    // Read in /sys/.../temp file
    thermal.open("/sys/class/thermal/thermal_zone0/temp", ios::in);

    // Check if file is open and output in human readable format
    if (thermal.is_open())
    {
        while (getline (thermal, sysTemp))
        {
            // Convert output
            // double tempCelsius = stod(sysTemp) / 1000;
            
            double tempCelsius = 87; //Test value

            double tempFahrenheit = (tempCelsius * 1.8) + 32;
            double tempKelvin = tempCelsius + 273.15;
            string colorCode = "";
            string status = "";
            string message = "";
            
            // Evaluate Temperature Safety Level
            if(tempCelsius < 60)
            {
                colorCode = GREEN;
                status = "GOOD";
                message = "CPU temperature is very good.";
            }
            else if(tempCelsius >= 60 && tempCelsius < 75)
            {
                colorCode = YELLOW;
                status = "CAUTION";
                message = "CPU temperature is somewhat elevated.";
            }
            else if(tempCelsius >= 75)
            {
                colorCode = RED;
                status = "WARNING";
                message = "CPU temperature is high and needs attention.";
            }
            
            // Output to terminal as human readable
            cout << fixed << setprecision(3);
            cout << "System Temperature\n";
            cout << "Status:" << colorCode << status << RESTORE;
            cout << DOUBLELINE;
            cout << colorCode;
            cout << setw(10) << right << tempCelsius << " \u00B0C\n"
                 << setw(10) << right << tempFahrenheit << " \u00B0F\n"
                 << setw(10) << right << tempKelvin << "  K" << DOUBLELINE;
            cout << RESTORE;
            cout << message << DOUBLELINE;
        }
        thermal.close();
    }
    else
    {
        cout << "Failure to open '/sys/class/thermal/thermal_zone0/temp'\n"
             << "Please try again . . ."
             << DOUBLELINE;
    }

    // Exit program without errors
    return 0;
}