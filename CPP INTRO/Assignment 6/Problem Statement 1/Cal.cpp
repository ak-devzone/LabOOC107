/*
Question: Create an object of the Calculator class and invoke
the appropriate overloaded functions. Display the result
of each operation.
*/

#include <iostream>
using namespace std;

class Calculator {
public:
    // Add two integers
    int calculate(int a, int b) {
        return a + b;
    }

    // Add two float numbers
    float calculate(float a, float b) {
        return a + b;
    }

    // Multiply two integers
    int calculate(int a, int b, int c) {
        return a * b * c;
    }
};

int main() {
    // Create an object of Calculator
    Calculator c;

    // Invoke overloaded functions
    cout << "Addition of integers: "
         << c.calculate(10, 20) << endl;

    cout << "Addition of float numbers: "
         << c.calculate(5.5f, 2.5f) << endl;

    cout << "Multiplication of three integers: "
         << c.calculate(2, 3, 4) << endl;

    return 0;
}