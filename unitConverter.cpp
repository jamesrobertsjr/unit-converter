//
// unitConverter.cpp
// Author: jameserv
//

#include <iostream>
#include <iomanip>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <string>

const std::string USER_INPUT_ERROR = "ERROR: Invalid entry. Please try again.";

// Function prototypes.
double fahrenheitToCelsius(double);
double celsiusToFahrenheit(double);
double mphToKmh(double);
double kmhToMph(double);
double milesToKilometers(double);
double kilometersToMiles(double);
char validateRunAgain (char);

int main() {
    char conversionSelection = '\0';
    char yesNo = '\0';

    do {
        std::cout << std::fixed << std::setprecision(2);
        std::cout << "What would you like to convert?\n";
        std::cout << "(T) - Temperature\n";
        std::cout << "(S) - Speed\n";
        std::cout << "(D) - Distance\n";
        std::cout << "Enter T, S, or D: ";
        std::cin >> conversionSelection;

        switch (toupper(conversionSelection)) {
            case 'T': 
            {
                // char temperatureConversionSelection = '\0';
                // double ftemp = 0.0, ctemp = 0.0;
                double temp = 0.0;
                char tempUnit = '\0';

                do {
                    std::cout << "Enter a temperature value with unit (example: '32 F' or '0 C'): ";
                    std::cin >> temp >> tempUnit;

                    switch (toupper(tempUnit)) {
                        case 'F':
                            std::cout << "Converted to Celsius: ";
                            std::cout << fahrenheitToCelsius(temp) << "Cº\n";
                            break;
                        case 'C':
                            std::cout << "Converted to Fahrenheit: ";
                            std::cout << celsiusToFahrenheit(temp) << "Fº\n";
                            break;
                        default:
                            std::cout << USER_INPUT_ERROR << std::endl;
                    }

                    // cout << "(A) - Convert Fahrenheit to Celsius\n"; 
                    // cout << "(B) - Convert Celsius to Fahrenheit\n";
                    // cout << "Enter A or B: ";
                    // cin >> temperatureConversionSelection;

                    // switch (toupper(temperatureConversionSelection)) {
                    //     case 'A':
                    //         cout << "Enter a temperature value in Fahrenheit: ";
                    //         cin >> ftemp;
                    //         cout << "Converted to Celsius: ";
                    //         cout << fahrenheitToCelsius(ftemp) << "ºC" << endl;
                    //         break;
                    //     case 'B':
                    //         cout << "Enter a temperature value in Celsius: ";
                    //         cin >> ctemp;
                    //         cout << "Converted to Fahrenheit: "; 
                    //         cout << celsiusToFahrenheit(ctemp) << "ºF" << endl;
                    //         break;
                    //     default:
                    //         cout << USER_INPUT_ERROR << endl;
                    //         break;
                    // }

                    std::cout << "Would you like to enter another temperature? (Y or N) ";
                    std::cin >> yesNo;
                } while (validateRunAgain(yesNo) == 'Y');
                break;
            }
            case 'S': 
            {
                // char speedConversionSelection = '\0';
                // double mph = 0, kmh = 0;
                double speed = 0.0;
                std::string speedUnit = "\0";

                do {
                    std::cout << "Enter a speed with the unit (example: '60 MPH' or '100 KMH'): ";
                    std::cin >> speed >> speedUnit;

                    if (speedUnit == "MPH" || speedUnit == "mph") {
                        std::cout << "Converted to KMH: ";
                        std::cout << mphToKmh(speed) << std::endl;
                    } else if (speedUnit == "KMH" || speedUnit == "kmh") {
                        std::cout << "Converted to MPH: ";
                        std::cout << kmhToMph(speed) << std::endl;
                    } else {
                        std::cout << USER_INPUT_ERROR << std::endl;
                    }

                    // std::cout << "(A) - Convert Miles per Hour (MPH) to Kilometers an Hour (KMH)\n";
                    // std::cout << "(B) - Convert Kilometers an Hour (KMH) to Miles per Hour (MPH)\n";
                    // std::cout << "Enter A or B: ";
                    // std::cin >> speedConversionSelection;

                    // switch (toupper(speedConversionSelection)) {
                    //     case 'A':
                    //         std::cout << "Enter a speed value in Miles per Hour (MPH): ";
                    //         std::cin >> mph;
                    //         std::cout << "Converted to KMH: ";
                    //         std::cout << mphToKmh(mph) << " KMH" << std::endl;
                    //         break;
                    //     case 'B':
                    //         std::cout << "Enter a speed value in Kilometers an Hour (KMH): ";
                    //         std::cin >> kmh;
                    //         std::cout << "Converted to MPH: ";
                    //         std::cout << kmhToMph(kmh) << " MPH" << std::endl;
                    //         break;
                    //     default:
                    //         std::cout << USER_INPUT_ERROR << std::endl;
                    //         break;
                    // }
                
                    std::cout << "Would you like to enter another speed? (Y or N) ";
                    std::cin >> yesNo;
                } while (validateRunAgain(yesNo) == 'Y');
                break;
            }
            case 'D':
            {
                // char distanceConversionSelection = '\0';
                // double miles = 0, kilometers = 0;
                double distance = 0.0;
                std::string distanceUnit = "\0";

                do {
                    std::cout << "NOTE: Program currently supports miles and kilometers.\n";
                    std::cout << "Enter a distance with the unit (example: '15 M' or '30 KM'): ";
                    std::cin >> distance >> distanceUnit;

                    if (distanceUnit == "M" || distanceUnit == "m" || 
                            distanceUnit == "Miles" || distanceUnit == "miles") {
                        std::cout << "Converted to Kilometers: ";
                        std::cout << milesToKilometers(distance) << " KM" << std::endl;
                    } else if (distanceUnit == "KM" || distanceUnit == "km" || 
                            distanceUnit == "Kilometers" || distanceUnit == "kilometers") {
                        std::cout << "Converted to Miles: ";
                        std::cout << kilometersToMiles(distance) << " Miles" << std::endl;
                    } else {
                        std::cout << USER_INPUT_ERROR << std::endl;
                    }

                    // std::cout << "(A) - Convert Miles to Kilometers\n";
                    // std::cout << "(B) - Convert Kilometers to Miles\n";
                    // std::cin >> distanceConversionSelection;

                    // switch (toupper(distanceConversionSelection)) {
                    //     case 'A':
                    //         std::cout << "Enter a distance value in Miles: ";
                    //         std::cin >> miles;
                    //         std::cout << "Converted to Kilometers: ";
                    //         std::cout << milesToKilometers(miles) << " KM" << std::endl;
                    //         break;
                    //     case 'B':
                    //         std::cout << "Enter a distance value in Kilometers: ";
                    //         std::cin >> kilometers;
                    //         std::cout << "Converted to Miles: ";
                    //         std::cout << kilometersToMiles(kilometers) << " Miles" << std::endl;
                    //         break;
                    //     default:
                    //         std::cout << USER_INPUT_ERROR << std::endl;
                    //         break;
                    // }

                    std::cout << "Would you like to enter another distance? (Y or N) ";
                    std::cin >> yesNo;
                } while (validateRunAgain(yesNo) == 'Y');
            }
            default: 
            {
                std::cout << USER_INPUT_ERROR << std::endl;
                break;
            }
        }

        std::cout << "Would you like to execute a different conversion? (Y or N) ";
        std::cin >> yesNo;

    } while (validateRunAgain(yesNo) == 'Y');
    return 0;
}

double fahrenheitToCelsius(double ftemp) {
    double celsius = (ftemp - 32.0) * (5.0 / 9.0);
    return celsius;
}

double celsiusToFahrenheit(double ctemp) {
    double fahrenheit = (ctemp * (9.0 / 5.0)) + 32.0;
    return fahrenheit;
}

double mphToKmh(double mph) {
    double kmh = mph * 1.609344;
    return kmh;
}

double kmhToMph(double kmh) {
    double mph = kmh / 1.609344;
    return mph;
}

double milesToKilometers(double miles) {
    double kilometers = miles * 1.609344;
    return kilometers;
}

double kilometersToMiles(double kilometers) {
    double miles = kilometers / 1.609344;
    return miles;
}

// Validates user entry for re-running program.
char validateRunAgain (char yesNo) {
    while (toupper(yesNo) != 'Y' && toupper(yesNo) != 'N') {
        std::cout << USER_INPUT_ERROR << std::endl;
        std::cin >> yesNo;
    }
    return toupper(yesNo);
}
