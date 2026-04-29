#include <iostream>
#include <iomanip>
using namespace std;

static int conversionValue = 0;

double dollarToEuro(double amount) {
    conversionValue++;
    return amount * 0.85;
}

double dollarToPound(double amount) {
    conversionValue++;
    return amount * 0.74;
}

double dollarToYen(double amount) {
    conversionValue++;
    return amount * 110.33;
}

int getConversionCount() {
    return conversionValue;
}

int main() {
    double amount;
    char repeat;
    int choice;

    do {
    cout << "CURRENCY CONVERTER \n";
    cout << "------------------- \n";
    cout << "1. Convert USD to Euro (EUR) \n";
    cout << "2. Convert USD to British Pound (GBP) \n";
    cout << "3. Convert USD to Japenese Yen (JPY) \n";
    cout << "4. Exit \n\n";

    cout << "Enter your choice (1-4): ";
    cin >> choice;
    
    if(choice == 1 || choice == 2 || choice == 3) {
        cout << "Enter amount in USD: ";
        cin >> amount;

        cout << fixed << setprecision(2);

        if(choice == 1) {
            cout << amount << " USD = " << dollarToEuro(amount) << " EUR\n\n"; 
        } else if(choice == 2) {
            cout << amount << " USD = " << dollarToPound(amount) << " GBP\n\n";
        } else if (choice == 3) {
            cout << amount << " USD = " << dollarToYen(amount) << " JPY\n\n";
        }
    } else if(choice == 4) {
        break;
    } else {
        cout << "Error. Please enter a valid choice.";
        continue;
    }
    cout << "Number of conversions performed: " << getConversionCount() << " \n\n";

    cout << "Would you like to perform another conversion? (y/n): ";
    cin >> repeat;
    } while (repeat == 'y' || repeat == 'Y');

    return 0;
}

