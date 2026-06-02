#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <fstream>
#include <iomanip>
using namespace std;

enum class Department { ENGINEERING, SALES, HR, OPERATIONS };

constexpr double OVERTIME_THRESHOLD = 40.0;
constexpr double OVERTIME_MULTIPLIER = 1.5;
constexpr double MAX_WEEKLY_HOURS = 168.0;

struct Employee {
    string name;
    Department dept;
    // BUG 2: hourlyRate should be double instead of int.
    // FIX 2: Change int to double for hourlyRate.
    double hourlyRate;      // Bug 2: should be double
    double hoursWorked;
};

// Returns the display name for a department
string deptName(Department d) {
    switch (d) {
        case Department::ENGINEERING: return "Engineering";
        case Department::SALES:       return "Sales";
        case Department::HR:          return "HR";
        case Department::OPERATIONS:  return "Operations";
        // BUG 3: missing case for unknown department
        // FIX 3: add a default case to handle unknown departments.
        default:                        return "Unknown";
    }
}

// Validate hours input — returns true if valid
bool validHours(double hours) {
    // BUG 4: checks both lower and upper bounds.
    // FIX 4: Add a check for negative hours to ensure they are not valid.
    if (hours < 0.0 || hours > MAX_WEEKLY_HOURS) {    // Bug 4: only checks upper bound
        cout << "Error: hours cannot exceed " << MAX_WEEKLY_HOURS << "\n";
        return false;
    }
    return true;
}

// Calculate weekly pay for one employee (with overtime)
double calculatePay(const Employee& e) {
    if (e.hoursWorked <= OVERTIME_THRESHOLD) {
        return e.hoursWorked * e.hourlyRate;
    } else {
        // Bug 1: applies overtime rate to ALL hours, not just excess
        return e.hoursWorked * e.hourlyRate * OVERTIME_MULTIPLIER;
    }
}

// Display a single employee row
void printEmployee(const Employee& e) {
    cout << left  << setw(20) << e.name
         << setw(14) << deptName(e.dept)
         << right << setw(8)  << fixed << setprecision(2) << e.hoursWorked << " hrs"
         << setw(10) << "$" + to_string((int)e.hourlyRate) + "/hr"
         << setw(12) << "$" + to_string((int)calculatePay(e))
         << "\n";
}

// Display all employees
void displayAll(const vector<Employee>& employees) {
    cout << "\n=== Employee Time Report ===\n";
    cout << left  << setw(20) << "Name"
         << setw(14) << "Department"
         << right << setw(8)  << "Hours"
         << setw(10) << "Rate"
         << setw(12) << "Pay"
         << "\n";
    cout << string(64, '-') << "\n";
    for (const auto& emp : employees) {
        printEmployee(emp);
    }
}

// Calculate total payroll cost
double totalPayroll(const vector<Employee>& employees) {
    // BUG 5: using integer 0 causes the sum to be truncated to an integer.
    // FIX 5: changed the initial value from 0 to 0.0.
    return accumulate(employees.begin(), employees.end(), 0.0,  // Bug 5: integer init
        [](double sum, const Employee& e) {
            return sum + calculatePay(e);
        });
}

void sortByHours(vector<Employee>& employees) {
    sort(employees.begin(), employees.end(), [](const Employee& a, const Employee& b) {
        return a.hoursWorked > b.hoursWorked;  // Sort in descending order
    });
    cout << "\n=== Hours Ranking ===\n";
    displayAll(employees);
}

void getDepartmentStats(const vector<Employee>& employees, Department dept) {
    vector<Employee> deptEmps;

    copy_if(employees.begin(), employees.end(), back_inserter(deptEmps), [dept](const Employee& e) {
        return e.dept == dept;
    });

    cout << "\n=== " << deptName(dept)  << "Department Stats ===\n";
    if(deptEmps.empty()) {
        cout << "No employees in this department.\n";
        return;
    }

    double totalHours = accumulate(deptEmps.begin(), deptEmps.end(), 0.0, [](double sum, const Employee& e) {
        return sum + e.hoursWorked;
    });

    double totalPay = accumulate(deptEmps.begin(), deptEmps.end(), 0.0, [](double sum, const Employee& e) {
        return sum + calculatePay(e);
    });

    double avgPay = totalPay / deptEmps.size();

    cout << "Employee Count: " << deptEmps.size() << "\n";
    cout << "Total Hours: " << fixed << setprecision(2) << totalHours << " hrs\n";
    cout << "Average Pay:  $" << fixed << setprecision(2) << avgPay << "\n";
}

void exportPayrollReport(const vector<Employee>& employees, const string& filename) {
    ofstream outFile(filename);
    if (!outFile) {
        cerr << "Error: Could not open file " << filename << " for writing.\n";
        return;
    }

    outFile << "=== WEEKLY PAYROLL EXPORT REPORT ===\n";

    vector<Department> departments = {
        Department::ENGINEERING,
        Department::SALES,
        Department::HR,
        Department::OPERATIONS
    };

    for (const auto& dept : departments) {
        outFile << "Department: " << deptName(dept) << "\n" << string(40, '-') << "\n";

        double deptSubtotal = 0.0;
        bool hasEmployees = false;

        for (const auto& emp : employees) {
            if (emp.dept == dept) {
                double pay = calculatePay(emp);
                outFile << left << setw(20) << emp.name
                        << right << " $" << fixed << setprecision(2) << pay << "\n";
                deptSubtotal += pay;
                hasEmployees = true;
            }
        }

        if(!hasEmployees) {
            outFile << "No employees in this department.\n";
        }
        outFile << string (40, '-') << "\n"
                << left << setw(20) << "Subtotal"
                << right << " $" << fixed << setprecision(2) << deptSubtotal << "\n\n";\
    }

    outFile.close();
    cout << "\nPayroll report exported to " << filename << "\n";
}

int main() {
    vector<Employee> employees = {
        {"Alice Chen",      Department::ENGINEERING, 42,   45.0},
        {"Bob Martinez",    Department::SALES,       28,   38.0},
        {"Carol Singh",     Department::HR,          35,   32.5},  // fractional rate
        {"David Park",      Department::ENGINEERING, 38,   50.0},
        {"Emma Wilson",     Department::OPERATIONS,  30,   29.0 },
        {"Frank Torres",    Department::SALES,       45,   44.5},  // overtime
        {"Grace Kim",       Department::HR,          33,   33.5},  // fractional rate
        {"Henry Okafor",    Department::OPERATIONS,  29,   55.0},  // overtime
    };

    cout << "=== HR Time Tracker ===\n";

    // Validate a sample input
    cout << "\nValidating hours entry -5: ";
    // BUG: validHours does not check for negative hours, so -5 would be considered valid.
    // FIX: Update validHours to check for negative hours and return false if hours is < 0.
    if (validHours(-5)) {
        cout << "valid\n";
    } else {
        cout << "invalid\n";  // should be invalid
    }

    displayAll(employees);

    cout << "\nTotal payroll this week: $"
         << fixed << setprecision(2) << totalPayroll(employees) << "\n";

    sortByHours(employees);
    getDepartmentStats(employees, Department::ENGINEERING);
    exportPayrollReport(employees, "payroll_report.txt");

    return 0;
}