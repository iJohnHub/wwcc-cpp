#include <iostream>
#include <iomanip>
#if defined(_WIN32) || defined(_WIN64)
#include <windows.h>
#endif
using namespace std;

void convertTemperautre(double temperature, char unit, double &k, double &f, double &c) {
    if(unit == 'k' || unit == 'K' ) {
       k = temperature;
       f = ((temperature - 273.15) * 9 / 5) + 32;
       c = (temperature - 273.15); 
    } else if(unit == 'f' || unit == 'F'){
        f = temperature;
        k = ((temperature - 32) * 5 / 9) + 273.15;
        c = (temperature - 32) * 5 / 9;
    } else if(unit == 'c' || unit == 'C') {
        c = temperature;
        f = (temperature * 9 / 5) + 32;
        k = (temperature + 273.15);
    }
}

int main() {

    #if defined(_WIN32) || defined(_WIN64)
    SetConsoleOutputCP(CP_UTF8);
    #endif

    double tempvalue, kelvin, celsius, farhren;
    char unit;

    cout << "Enter a temperature value: ";
    cin >> tempvalue;
    cout << "Enter the unit (C for Celsius, F for Farhenheit, K for Kelvin): ";
    cin >> unit;

    convertTemperautre(tempvalue, unit, kelvin, farhren, celsius);

    cout << "Temperature Conversions: \n";
    cout << fixed << setprecision(2);
    cout << "Celsius:  " << celsius << "\xc2\xb0\x43" << "\n";
    cout << "Fahrenheit:  " << farhren << "\xc2\xb0\x46" <<"\n";
    cout << "Kelvin:  " << kelvin << " K";

    return 0;

}