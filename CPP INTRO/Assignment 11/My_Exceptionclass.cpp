
/*
Question: Write a C++ program to demonstrate
user-defined exception handling using a class.
*/

#include <iostream>
#include <exception>
using namespace std;

// User-defined exception class
class MyException : public exception {
public:
    // Return the exception message
    const char* what() const noexcept override {
        return "Attempted to divide by zero!\n";
    }
};

int main() {
    try {
        int x, y;

        // Accept two numbers
        cout << "Enter the two numbers: ";
        cin >> x >> y;

        // Check whether the denominator is zero
        if (y == 0) {
            MyException z;
            throw z;
        }
        else {
            // Perform division
            cout << "x / y = " << x / y << endl;
        }
    }
    catch (const exception& e) {
        // Handle and display the exception
        cout << e.what();
    }

    return 0;
}
