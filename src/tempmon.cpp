/*==============================================================
Program:  CPU Temperature Monitor
Version:  0.2.2
Version Date:  01/08/2023
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

// Special definitions
#define DOUBLELINE "\n\n"
#define RESTORE "\033[0m" // Return to default terminal color
#define GREEN "\033[1m\033[32m" // Bold green
#define YELLOW "\033[1m\033[33m" // Bold yellow
#define RED "\033[1m\033[31m" // Bold red

// Main function
int main(){
    std::ifstream thermal;
    std::string sysTemp = "";
    
    // Read in /sys/.../temp file
    thermal.open("/sys/class/thermal/thermal_zone0/temp", std::fstream::in);

    // Check if file is open and output in human readable format
    if (thermal.is_open()){
        while (getline (thermal, sysTemp)){
            // Convert output
            double tempCelsius = stod(sysTemp) / 1000;
            double tempFahrenheit = (tempCelsius * 1.8) + 32;
            double tempKelvin = tempCelsius + 273.15;
            std::string colorCode = "";
            std::string status = "";
            std::string message = "";
            
            // Evaluate Temperature Safety Level
            if(tempCelsius < 60){
                colorCode = GREEN;
                status = "GOOD";
                message = "CPU temperature is very good.";
            }else if(tempCelsius >= 60 && tempCelsius < 75){
                colorCode = YELLOW;
                status = "CAUTION";
                message = "CPU temperature is somewhat elevated.";
            }else if(tempCelsius >= 75){
                colorCode = RED;
                status = "WARNING";
                message = "CPU temperature is high and needs attention.";
            }
            
            // Output to terminal as human readable
            std::cout << std::fixed << std::setprecision(3);
            std::cout << "System Temperature\n";
            std::cout << "Status:" << colorCode << status << RESTORE;
            std::cout << DOUBLELINE;
            std::cout << colorCode;
            std::cout << std::setw(10) << std::right << tempCelsius << " \u00B0C\n";
            std::cout << std::setw(10) << std::right << tempFahrenheit << " \u00B0F\n";
            std::cout << std::setw(10) << std::right << tempKelvin << "  K";
            std::cout << DOUBLELINE << RESTORE << message << DOUBLELINE;
        }
        thermal.close();
    }else{
        std::cout << "Failure to open '/sys/class/thermal/thermal_zone0/temp'\n";
        std::cout << "Please try again . . ." << DOUBLELINE;
    }

    // Exit program without errors
    return 0;
}