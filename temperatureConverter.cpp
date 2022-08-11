//
// temperatureConverter.cpp
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
const char f_to_c = 'A';
const char c_to_f = 'B';

// Function prototypes.
double fahrenheitToCelsius(double);
double celsiusToFahrenheit(double);
char validateRunAgain (char);

int main() {
    char conversionSelection = '\0';
    double ftemp = 0.0, ctemp = 0.0;
    char yesNo = '\0';

    do {
        // Displays options to user.
        cout << "(A) - Convert Fahrenheit to Celsius\n"; 
        cout << "(B) - Convert Celsius to Fahrenheit\n";
        cout << "Enter A or B: ";
        cin >> conversionSelection;

        // Converts user entry to capital letters, then feeds it into switch statement.
        switch (toupper(conversionSelection)) {
            case f_to_c:
                cout << "Enter a temperature value in Fahrenheit: ";
                cin >> ftemp;
                cout << "Converted to Celsius: ";
                cout << fahrenheitToCelsius(ftemp) << "ºC" << endl;
                break;
            case c_to_f:
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

// Validates user entry for re-running program.
char validateRunAgain (char yesNo) {
    while (toupper(yesNo) != 'Y' && toupper(yesNo) != 'N') {
        cout << USER_INPUT_ERROR << endl;
        cin >> yesNo;
    }

    return toupper(yesNo);
}
