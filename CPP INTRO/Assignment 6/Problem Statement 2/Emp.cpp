/*Develop a C++ program to create a class Employee that demonstrates Function
Overloading.
Implement overloaded member functions named calculateSalary() to
calculate:
● Salary using Basic Salary only.
● Salary using Basic Salary and HRA.
● Salary using Basic Salary, HRA, and DA.
Display the calculated salary for each overloaded function.
*/

#include <iostream>
using namespace std;

class Employee {
public:
    double calculateSalary(double basicSalary) {
        return basicSalary;
    }

    double calculateSalary(double basicSalary, double hra) {
        return basicSalary + hra;
    }

    double calculateSalary(double basicSalary, double hra, double da) {
        return basicSalary + hra + da;
    }
};

int main() {
    Employee e;

    cout << "Salary using Basic Salary only: "
         << e.calculateSalary(20000) << endl;

    cout << "Salary using Basic Salary and HRA: "
         << e.calculateSalary(20000, 5000) << endl;

    cout << "Salary using Basic Salary, HRA, and DA: "
         << e.calculateSalary(20000, 5000, 3000) << endl;

    return 0;
}