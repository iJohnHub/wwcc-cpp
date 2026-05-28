#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <iomanip>
#include <algorithm>

using namespace std;

struct Student {
    string lastName;
    string firstName;
    int g1, g2, g3;
    double average;
    int high;
    int low;
};

int main() {
    // --- Read input file ---
    ifstream inFile("grades.txt");
    
    // BUG: The input file is opened but the program never checks whether it actually opened successfully.
    // FIX: Added an if-statement check to ensure the file exists and opened correctly, printing an error and exiting if it fails.
    if (!inFile) {
        cerr << "Error: Could not open grades.txt" << endl;
        return 1;
    }

    cout << "Reading records from grades.txt..." << endl;
    vector<Student> students;
    string line;

    // BUG: The original loop used while(!inFile.eof()), which causes the last record to be processed twice.
    // FIX: Replaced the broken loop entirely with a clean while(getline(inFile, line)) loop structure.
    while (getline(inFile, line)) {
        if (line.empty() || line[0] == '#') continue;

        // BUG: The stringstream object was originally declared outside the loop, causing data from one line to bleed into the next.
        // FIX: Moved the stringstream declaration inside the loop so a fresh instance is created for each line.
        stringstream ss(line);
        
        Student s;
        if (ss >> s.lastName >> s.firstName >> s.g1 >> s.g2 >> s.g3) {
            s.high = max({s.g1, s.g2, s.g3});
            s.low  = min({s.g1, s.g2, s.g3});
            
            int total = s.g1 + s.g2 + s.g3;
            
            // BUG: The average calculation used integer division (total / 3), silently dropping all decimal precision.
            // FIX: Changed the divisor to 3.0 to force floating-point division and preserve the decimals.
            s.average = total / 3.0;
            
            students.push_back(s);
        }
    }
    inFile.close();

    cout << students.size() << " students loaded." << endl << endl;

    // --- Write report ---
    // BUG: The output file is opened in a mode that overwrites the existing grade_report.txt file every time.
    // FIX: Opened the file with ios::app mode to preserve previous runs by appending to the file.
    ofstream outFile("grade_report.txt", ios::app);

    // --- Display to console and write to file ---
    auto printReport = [&](ostream& out) {
        out << "GRADE REPORT" << endl;
        out << string(20, '-') << endl;
        out << left << setw(20) << "Name" << setw(7) << "Avg" << setw(7) << "High" << setw(7) << "Low" << endl;
        out << string(20, '-') << endl;

        double classTotal = 0;
        int topIdx = 0, lowIdx = 0;

        for (int i = 0; i < (int)students.size(); i++) {
            Student& s = students[i];
            string name = s.lastName + ", " + s.firstName;

            // BUG: setw() was applied once outside the loop instead of being applied to each row, breaking column alignment.
            // FIX: Removed the external setw call and properly attached setw(20) directly to the name variable inside the loop.
            
            // BUG: Numeric columns used the 'left' manipulator, causing them to align improperly with text.
            // FIX: Explicitly applied the 'right' manipulator before outputting the numeric fields (Avg, High, Low).
            out << left << setw(20) << name
                << right << setw(7) << fixed << setprecision(1) << s.average
                << setw(7) << s.high
                << setw(7) << s.low << endl;

            classTotal += s.average;
            if (s.average > students[topIdx].average) topIdx = i;
            if (s.average < students[lowIdx].average) lowIdx = i;
        }

        double classAvg = students.empty() ? 0.0 : classTotal / students.size();
        out << endl << "CLASS STATISTICS" << endl;
        out << string(20, '-') << endl;
        out << fixed << setprecision(1);
        out << "Class average: " << classAvg << endl;
        out << "Top student:   " << students[topIdx].lastName << ", " << students[topIdx].firstName << " (" << students[topIdx].average << ")" << endl;
        out << "Low student:   " << students[lowIdx].lastName << ", " << students[lowIdx].firstName << " (" << students[lowIdx].average << ")" << endl;
    };

    printReport(cout);
    printReport(outFile);
    outFile.close();

    cout << endl << "Report written to grade_report.txt" << endl;
    return 0;
}
