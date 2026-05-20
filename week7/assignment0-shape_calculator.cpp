#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

double const PI = 3.14159;

class Rectangle {
    private:
        double length;
        double width;

    public:
        Rectangle(double l, double w) : length(l), width(w) {}

        double findlength() const {return length; }
        double findwidth() const {return width; }

        void setlength(double l) { if (l > 0) length = l; }
        void setwidth(double w) { if (w > 0) width = w; }

        double area() const { return width * length; }
        void area(double& result) const { result = width * length; }

        Rectangle& resize(double factor) {
            this->length *= factor;
            this->width *= factor;
            return *this;

        }

        void display() const;
        void printline() const;
};

void Rectangle::display() const {
    cout << fixed << setprecision(2);
    cout << "Rectangle (Length: " << length << ", Width:  " << width << ")" << endl;
}

void Rectangle::printline() const {
    cout << fixed << setprecision(2);
    cout << "Length = " << length << ", Width = " << width;
}

class Circle {
    private:
    double radius;

    public:
    Circle(double r = 0) : radius(r) {}

    double getRadius() const { return radius; }
    void setRadius(double r) { if (r > 0) radius = r; }

    double getCircumfernce() const { return 2 * PI * radius; }
    double getArea() const { return PI * pow(radius, 2); }

    void print() const {
        cout << "Circle: (Radius: " << radius << ")" << endl;
        cout << "Area: " << getArea() << endl;
        cout << "Circumference: " << getCircumfernce() << endl; 
    }

    void print(bool detailed) const {
        if(detailed) {
            cout << "Circle details: " << endl;
            cout << "   Radius:         " << radius << endl;
            cout << "   Area:           pi x " << radius <<  "^2 = " <<  getArea() << endl;
            cout << "   Circumference:  2 x pi x " << radius << " = " << getCircumfernce() << endl;
        } else {
            print();
        }
    }
};

int main() {
    cout << "SHAPE CALCULATOR" << endl;
    cout << "----------------\n\n";

    Rectangle rect(5.0,3.0);
    rect.display();
    cout << "Area: " << rect.area() << endl;

    double areaRef;
    rect.area(areaRef);
    cout << "Area via Reference: " << areaRef << endl;

    cout << endl;
    Circle circ(4.0);
    circ.print();
    cout << endl;
    circ.print(true);

    cout << "Method chaining: " << endl;
    cout << "   Original:  ";
    rect.printline();
    cout << endl;

    cout << "   After resize(2.0): ";
    rect.resize(2.0).printline();
    cout << endl;

    cout << "Const Object Test: " << endl;
    const Circle constCirc(5.0);
    cout << "   Const Area: " << constCirc.getArea() << endl;

    return 0;
}