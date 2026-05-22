#include <iostream>
#include <string>
#include <iomanip>
using namespace std;


// Fix: Renamed class to BankAccount as a better alternative to the generic name "Account" and to better reflect its purpose
class BankAccount {
    private:  
    // Fix: Change to private for better encapsulation
    // Fix: Use more descriptive variable names(like accountType instead of type)
        string customerName;
        double balance; // 
        bool isOpen; 
        int accountNumber;
        string accountType;

        // Fix: Extracted interest rates into constants for better maintainability
        const double Savings_Interest_Rate = 1.03; 
        const double Checking_Interest_Rate = 1.01;
        const double Business_Interest_Rate = 1.005;

    public:
        // Fix: Added constructor to initialize member variables instead of the setup() function
        BankAccount(string name, int num, string t)
            : customerName(name), balance(0.0), isOpen(true), accountNumber(num), accountType(t) {}

            // Fix: Added input validation to ensure that deposit and withdrawal amounts are positive and that withdrawals do not exceed the balance
            void deposit(double amount) {
                if(amount > 0) {
                    balance += amount;
                } else if (amount <= 0) {
                    cout << "Error: Deposit amount must be positive." << endl;
                }
            }
            
            // Fix: Added input validation to ensure that withdrawal amounts are positive and do not exceed the current balance, and provided user feedback for invalid inputs
            void withdraw(double amount) {
                if (amount > 0 && amount <= balance) {
                    balance -= amount;
                } else if (amount > balance) {
                    cout << "Insufficient funds. Please enter a smaller amount." << endl;
                } else if (amount <= 0) {
                    cout << "Error: Withdrawal amount must be positive." << endl;
                }
            }

            // Fix: Renamed do_interest() to doInterest() for consistency with C++ naming conventions and utilized the defined class constants
            void doInterest() {
                if (accountType == "savings") {
                    balance *= Savings_Interest_Rate;
                } else if (accountType == "checking") {
                    balance *= Checking_Interest_Rate;
                } else if (accountType == "business") {
                    balance *= Business_Interest_Rate;
                }
            }

            // Fix: Original code forgot to mark the method as 'const' to protect objest state from being modified
            void print() const {
                cout << "Account Number: " << accountNumber << endl;
                cout << "Customer Name: " << customerName << endl;
                cout << "Balance: " << balance << "$" << endl;
                cout << "Account Type: " << accountType << endl;
                cout << "Status: " << (isOpen ? "Open" : "Closed") << endl;
            }
            
            // Fix: Kept the close() but ensures it safely updates the account status without affecting any variables
            void close() {
                isOpen = false;
            }
            // Fix: Changed get_money() to getBalance() for better clarity
            // Fix: Added 'const' since it is a read only function that does not modify the state of the object
            double getBalance() const {
                return balance;
            }
};

int main() {
    // Fix: Updated the constructor call to match the new BankAccount class and its parameters
    BankAccount acc1("John Smith", 12345, "savings");

    acc1.deposit(1000);
    acc1.withdraw(250);
    acc1.doInterest();

    acc1.print();
    acc1.close();

    return 0;
}