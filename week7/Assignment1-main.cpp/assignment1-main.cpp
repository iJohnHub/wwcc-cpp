#include "Library.h"
#include <iostream>
#include <limits>
using namespace std;

int main() {
    Library myLibrary("Central City Library");
    int choice =0;

    while (choice != 6) {
        cout << "\nLIBRARY MANAGEMENT SYSTEM\n";
        cout << "-------------------------\n";        
        cout << "1. Add Book\n";
        cout << "2. Display All Books\n";
        cout << "3. Search by Author\n";    
        cout << "4. Search by Title\n";
        cout << "5. Show Stats\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        if (choice == 1) {
            string t, i, an; int y, ay;
            cout << "Title: "; 
            getline(cin, t);
            cout << "Year: ";
            cin >> y; 
            cout << "Isbn: ";
            cin >> i;
            cout << "Author's Name: ";
            cin .ignore();
            getline(cin, an);
            cout << "Author's Birth Year: ";
            cin >> ay;
            myLibrary.addBook(Book(t, y, i, Author(an, ay)));
        }
        else if (choice == 2) myLibrary.displayAll();
        else if (choice == 3) {
            string n; 
            cout << "Author Name: ";
            getline(cin, n);
            myLibrary.searchByAuthor(n);
        }
        else if (choice == 4) {
            string t; 
            cout << "Title: ";
            getline(cin, t);
            myLibrary.searchByTitle(t);
        }
        else if (choice == 5) {
            myLibrary.showStats();
        } 
        else if (choice == 6) {
            cout << "Exiting...\n";
        } 
        else {
            cout << "Invalid choice. Please try again.\n";
        }
    }
    return 0;
}