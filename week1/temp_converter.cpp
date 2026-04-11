#include <iostream>

int main() {
    double temperature;
    char unit;

    std::cout << "Temperature Converter\n";

    std::cout << "Enter temperature value: ";
    std::cin >> temperature; 

    std::cout << "Enter Unit (C for Celsius, F for Fahrenheit): "; 
    std::cin >> unit;

    if(unit == 'C' || unit == 'c') {
        double temp2 = (temperature * 1.8) + 32;
        std::cout << temperature << "C is equal to " << temp2 << "F";
    }
     else if (unit == 'F' || unit == 'f') {
        double temp2 = (temperature - 32) * 5.0 / 9.0;
        std::cout << temperature << "F is equal to " << temp2 << "C"; 
    }

    return 0;
}