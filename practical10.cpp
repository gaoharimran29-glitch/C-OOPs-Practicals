#include <iostream>
#include <cmath>
using namespace std;

class Triangle {

    double a, b, c;

public:

    // Constructor
    Triangle(double x, double y, double z) {

        // Exception Handling

        if (x <= 0 || y <= 0 || z <= 0) {
            throw "Sides must be greater than 0";
        }

        if ((x + y <= z) || (x + z <= y) || (y + z <= x)) {
            throw "Invalid Triangle: Sum of any two sides must be greater than third side";
        }

        a = x;
        b = y;
        c = z;
    }

    // Overloaded Function for Right Angled Triangle
    double area(double base, double height) {

        return 0.5 * base * height;
    }

    // Overloaded Function using Heron's Formula
    double area() {

        double s = (a + b + c) / 2;

        return sqrt(s * (s - a) * (s - b) * (s - c));
    }

    // Display sides
    void display() {

        cout << "Sides: "
             << a << " "
             << b << " "
             << c << endl;
    }
};

int main() {

    double x, y, z;

    try {

        cout << "Enter three sides of triangle: ";
        cin >> x >> y >> z;

        Triangle t(x, y, z);

        t.display();

        cout << "\nArea using Heron's Formula = "
             << t.area() << endl;

        double base, height;

        cout << "\nEnter base and height for right angled triangle: ";
        cin >> base >> height;

        cout << "Area of Right Angled Triangle = "
             << t.area(base, height) << endl;
    }

    catch (const char* msg) {

        cout << "\nException: " << msg << endl;
    }

    return 0;
}