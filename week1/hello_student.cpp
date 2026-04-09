#include <iostream>
#include <string>
using namespace std;

int main() {
    string name;
    string email;

    cout << "Enter your name: ";
    cin>>name;

    cout<<"Hello, "<< name << "! Welcome to C++!" << endl;

    cout<<"Enter your email: ";
    cin>>email;

    cout<< "Thank you for your email " << name << "! There will be some incoming spam headed your way! (" << email << ")" << endl;
    return 0;
}