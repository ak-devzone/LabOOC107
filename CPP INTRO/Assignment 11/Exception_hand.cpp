
/*
Question: Write a C++ program to demonstrate the use of
try, catch and throw in exception handling.
*/

#include <iostream>
using namespace std;

// Function to perform division
double division(int a, int b) {
    if (b == 0) {
        // Throw an exception if denominator is zero
        throw "Division by zero condition!";
    }

    return (double)a / b;
}

int main() {
    int x = 50;
    int y = 0;
    double z = 0;

    try {
        // Call the division function
        z = division(x, y);
        cout << "Result: " << z << endl;
    }
    catch (const char* msg) {
        // Handle the exception
        cerr << "Exception: " << msg << endl;
    }

    return 0;
}
