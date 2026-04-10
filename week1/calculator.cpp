#include <iostream>
using namespace std;

int main() {
    double num1, num2;

    cout << "Enter the first number: ";
    cin >> num1;

    cout << "Enter the second number: ";
    cin >> num2;


    cout << "Results:    " << endl;

    cout << "Sum:        " << num1 << "+" << num2 << " = " << (num1 + num2) << endl;
    cout << "Difference: " << num1 << "-" << num2 << " = " << (num1 - num2) << endl;
    cout << "Product:    " << num1 << "*" << num2 << " = " << (num1 * num2) << endl;

    if(num2 == 0) {
        cout << "Quotient: Error: Attempted to divide by zero!" << endl;   
    } else {
        cout << "Quotient:   " << num1 << "/" << num2 << " = " <<(num1/num2) << endl;
     }
     return 0;

}