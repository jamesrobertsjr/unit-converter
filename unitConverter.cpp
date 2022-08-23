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
using namespace std;

// Constants.
const string USER_INPUT_ERROR = "ERROR. Invalid entry. Please try again.";

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
        cout << fixed << setprecision(2);

        cout << "What would you like to convert?\n";
        cout << "(T) - Temperature\n";
        cout << "(S) - Speed\n";
        cout << "(D) - Distance\n";
        cout << "Enter T, S, or D: ";
        cin >> conversionSelection;

        switch (toupper(conversionSelection)) {
            case 'T': 
            {
                char temperatureConversionSelection = '\0';
                double ftemp = 0.0, ctemp = 0.0;
                do {
                    cout << "(A) - Convert Fahrenheit to Celsius\n"; 
                    cout << "(B) - Convert Celsius to Fahrenheit\n";
                    cout << "Enter A or B: ";
                    cin >> temperatureConversionSelection;

                    switch (toupper(temperatureConversionSelection)) {
                        case 'A':
                            cout << "Enter a temperature value in Fahrenheit: ";
                            cin >> ftemp;
                            cout << "Converted to Celsius: ";
                            cout << fahrenheitToCelsius(ftemp) << "ºC" << endl;
                            break;
                        case 'B':
                            cout << "Enter a temperature value in Celsius: ";
                            cin >> ctemp;
                            cout << "Converted to Fahrenheit: "; 
                            cout << celsiusToFahrenheit(ctemp) << "ºF" << endl;
                            break;
                        default:
                            cout << USER_INPUT_ERROR << endl;
                            break;
                    }

                    cout << "Would you like to enter another temperature? (Y or N) ";
                    cin >> yesNo;
                } while (validateRunAgain(yesNo) == 'Y');
                break;
            }
            case 'S': 
            {
                char speedConversionSelection = '\0';
                double mph = 0, kmh = 0;
                do {
                    cout << "(A) - Convert Miles per Hour (MPH) to Kilometers an Hour (KMH)\n";
                    cout << "(B) - Convert Kilometers an Hour (KMH) to Miles per Hour (MPH)\n";
                    cout << "Enter A or B: ";
                    cin >> speedConversionSelection;

                    switch (toupper(speedConversionSelection)) {
                        case 'A':
                            cout << "Enter a speed value in Miles per Hour (MPH): ";
                            cin >> mph;
                            cout << "Converted to KMH: ";
                            cout << mphToKmh(mph) << " KMH" << endl;
                            break;
                        case 'B':
                            cout << "Enter a speed value in Kilometers an Hour (KMH): ";
                            cin >> kmh;
                            cout << "Converted to MPH: ";
                            cout << kmhToMph(kmh) << " MPH" << endl;
                            break;
                        default:
                            cout << USER_INPUT_ERROR << endl;
                            break;
                    }
                
                    cout << "Would you like to enter another speed? (Y or N) ";
                    cin >> yesNo;
                } while (validateRunAgain(yesNo) == 'Y');
                break;
            }
            case 'D':
            {
                char distanceConversionSelection = '\0';
                double miles = 0, kilometers = 0;
                do {
                    cout << "(A) - Convert Miles to Kilometers\n";
                    cout << "(B) - Convert Kilometers to Miles\n";
                    cin >> distanceConversionSelection;

                    switch (toupper(distanceConversionSelection)) {
                        case 'A':
                            cout << "Enter a distance value in Miles: ";
                            cin >> miles;
                            cout << "Converted to Kilometers: ";
                            cout << milesToKilometers(miles) << " KM" << endl;
                            break;
                        case 'B':
                            cout << "Enter a distance value in Kilometers: ";
                            cin >> kilometers;
                            cout << "Converted to Miles: ";
                            cout << kilometersToMiles(kilometers) << " Miles" << endl;
                            break;
                        default:
                            cout << USER_INPUT_ERROR << endl;
                            break;
                    }

                    cout << "Would you like to enter another distance? (Y or N) ";
                    cin >> yesNo;
                } while (validateRunAgain(yesNo) == 'Y');
            }
            default: 
            {
                cout << USER_INPUT_ERROR << endl;
                break;
            }
        }

        cout << "Would you like to execute a different conversion? (Y or N) ";
        cin >> yesNo;

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
        cout << USER_INPUT_ERROR << endl;
        cin >> yesNo;
    }

    return toupper(yesNo);
}
