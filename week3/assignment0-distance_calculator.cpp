#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

 double calculateDistance(double x1, double y1, double x2, double y2) { // Function used to calculate the distance of two points
    return sqrt (pow(x2 - x1, 2) + pow(y2 -y1, 2)); // The formula used for distance

}
int main () {

    double x1,x2,y1,y2;

    cout << "Enter the coordinates of the first point: \n"; // Asks the user to input the first point
    cout << "x1: ";
    cin >> x1;
    cout << "y1: ";
    cin >> y1;
    cout << "Enter the coordinates of the second point: \n"; // Asks the user to intpu the second point
    cout << "x2: ";
    cin >> x2;
    cout << "y2: ";
    cin >> y2;

    double distance = calculateDistance (x1,y1,x2,y2); // Calculates the distance using the distance formula from earlier

    printf("The distance between (%.0f,%.0f) and (%.0f,%.0f) is: %.2f", x1, y1, x2, y2, distance); // Outputs the two points the user entered and also the distance calculated to the tenth place

    return 0;

}
