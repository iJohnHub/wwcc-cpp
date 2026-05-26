#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void swap(int& a, int& b);
int findMax(int* arr, int size);
void writeNote(ofstream& file, const string& note);
void showNote(ifstream& file);

int main () {
    cout << "=== PART 1: MEMORY AND ADDRESSING ===" << endl;

    int age = 25;
    double gpa = 3.75;
    char grade = 'A';

    cout << "\nVariables values and addresses:" << endl;
    cout << "   int     age = " << age << " at address " << &age << endl;
    cout << "   double  gpa = " << gpa << " at address " << &gpa << endl;
    cout << "   char    grade = " << grade << " at address " << (void*)&grade << endl;

    int& ageRef = age;
    cout << "\nReference demonstration:" << endl;
    cout << "Before: age = " << age << ", ageRef = " << ageRef << endl;
    ageRef = 26;
    cout << "After modifying through reference: age = " << ageRef << endl;

    int* agePtr = &age;
    if (agePtr != nullptr) {
        cout << "\n Pointer demonstration:" << endl;
        cout << "Pointer stores address: " << agePtr << endl;
        cout << "Value at that address: " << *agePtr << endl;
        *agePtr = 100;
        cout << "After modifying value through pointer: age = " << age << endl;
    }

    int x = 10, y = 20;
    cout << "\nSwap function (by reference):" << endl;
    cout << "Before: x = " << x << ", y = " << y << endl;
    swap(x, y);
    cout << "After: x = " << x << ", y = " << y << endl;

    int arr[] = {5, 3, 8, 1, 4};
    cout << "\nArray-pointer relationship: " << endl;
    cout << "arr[0] = " << arr[0] << "  *(arr + 0) = " << *(arr + 0) << endl;
    cout << "arr[1] = " << arr[1] << "  *(arr + 1) = " << *(arr + 1) << endl;

    int maxVal = findMax(arr, 5);
    cout << "Maximum value (via pointer):" << maxVal << endl;

    cout << "\n--- PART 2: FILE I/O ---" << endl;

    ofstream outFile("note.txt", ios::out);
    if(!outFile) {
        cerr << "Error opening file for writing!" << endl;
        return 1;
    }

    cin.ignore(); 
    for (int i = 1; i <= 3; i++) {
        string note;
        cout << "Enter note " << i << ": ";
        getline(cin, note);
        writeNote(outFile, note);
    }
    outFile.close();
    cout << "Notes written to notes.txt successfully." << endl;

    ifstream inFile("note.txt");
    if(!inFile) {
        cerr << "Error opening file for reading!" << endl;
        return 1;
    }

    cout << "\nReading notes from note.txt: " << endl;
    showNote(inFile);
    inFile.close();

    return 0;
}

void swap (int&a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

int findMax(int* arr, int size) {
    if (arr == nullptr) return 0;
    int max = *arr;
    for (int i = 1; i < size; i++) {
        if(*(arr + i) > max) {
            max = *(arr + i);
        }
    }
    return max;
}

void writeNote(ofstream& file, const string& note) {
    if (file.is_open()) {
        file << note << endl;
    }
}

void showNote(ifstream& file) {
    string line;
    if (file.is_open()) {
        while (getline(file, line)) {
            cout << line << endl;
        }
    }
}