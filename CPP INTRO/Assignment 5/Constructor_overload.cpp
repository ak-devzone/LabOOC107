/*
Question: Write a C++ program to illustrate
constructor overloading.
*/

#include <iostream>
using namespace std;

class construct {
public:
    float area;

    // Constructor with no parameters
    construct() {
        area = 0;
    }

    // Constructor with two parameters
    construct(int a, int b) {
        area = a * b;
    }

    // Function to display area
    void disp() {
        cout << "Area: " << area << endl;
    }
};

int main() {
    // Call default constructor
    construct o;

    // Call parameterized constructor
    construct o2(10, 20);

    // Display results
    o.disp();
    o2.disp();

    return 0;
}