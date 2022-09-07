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
void displayConversions(std::string, double, std::string);
char askToRunAgain(std::string);
char validateRunAgain (char);

int main() {
    char conversionSelection = '\0';

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
                double temp = 0.0;
                char tempUnit = '\0';
                do {
                    std::cout << "Enter a temperature value with unit (example: '32 F' or '0 C'): ";
                    std::cin >> temp >> tempUnit;

                    switch (toupper(tempUnit)) {
                        case 'F':
                            displayConversions("Celsius", fahrenheitToCelsius(temp), "ºC");
                            // std::cout << "Converted to Celsius: ";
                            // std::cout << fahrenheitToCelsius(temp) << "Cº\n";
                            break;
                        case 'C':
                            displayConversions("Fahrenheit", celsiusToFahrenheit(temp), "ºF");
                            // std::cout << "Converted to Fahrenheit: ";
                            // std::cout << celsiusToFahrenheit(temp) << "Fº\n";
                            break;
                        default:
                            std::cout << USER_INPUT_ERROR << std::endl;
                    }
                } while (validateRunAgain(askToRunAgain("temperature")) == 'Y');
                break;
            }
            case 'S': 
            {
                double speed = 0.0;
                std::string speedUnit = "\0";

                do {
                    std::cout << "Enter a speed with the unit (example: '60 MPH' or '100 KMH'): ";
                    std::cin >> speed >> speedUnit;

                    if (speedUnit == "MPH" || speedUnit == "mph") {
                        displayConversions("KMH", mphToKmh(speed), "\0");
                        // std::cout << "Converted to KMH: ";
                        // std::cout << mphToKmh(speed) << std::endl;
                    } else if (speedUnit == "KMH" || speedUnit == "kmh") {
                        displayConversions("MPH", kmhToMph(speed), "\0");
                    } else {
                        std::cout << USER_INPUT_ERROR << std::endl;
                    }
                } while (validateRunAgain(askToRunAgain("speed")) == 'Y');
                break;
            }
            case 'D':
            {
                double distance = 0.0;
                std::string distanceUnit = "\0";

                do {
                    std::cout << "NOTE: Program currently supports miles and kilometers.\n";
                    std::cout << "Enter a distance with the unit (example: '15 M' or '30 KM'): ";
                    std::cin >> distance >> distanceUnit;

                    if (distanceUnit == "M" || distanceUnit == "m") {
                        displayConversions("Kilometers", milesToKilometers(distance), "KM");
                    } else if (distanceUnit == "KM" || distanceUnit == "km") {
                        displayConversions("Miles", kilometersToMiles(distance), "Miles");
                    } else {
                        std::cout << USER_INPUT_ERROR << std::endl;
                    }
                } while (validateRunAgain(askToRunAgain("distance")) == 'Y');
                break;
            }
            default: 
            {
                std::cout << USER_INPUT_ERROR << std::endl;
                break;
            }
        }
    } while (validateRunAgain(askToRunAgain("(different) conversion")) == 'Y');
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

void displayConversions(std::string unit, double conversion, std::string abbreviatedUnit) {
    std::cout << "Converted to " << unit << ": " << conversion << " " << abbreviatedUnit << std::endl;
}

char askToRunAgain(std::string unit) {
    char yesNo;
    std::cout << "Would you like to enter another " << unit << "? (Y or N) ";
    std::cin >> yesNo;
    return yesNo;
}

// Validates user entry for re-running program.
char validateRunAgain (char yesNo) {
    while (toupper(yesNo) != 'Y' && toupper(yesNo) != 'N') {
        std::cout << USER_INPUT_ERROR << std::endl;
        std::cin >> yesNo;
    }
    return toupper(yesNo);
}
