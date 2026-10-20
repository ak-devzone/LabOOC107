
/*
Question: Develop a C++ program to implement Hierarchical
Inheritance for an Employee Management System.
*/

#include <iostream>
using namespace std;

// Base class
class Employee {
public:
    int id;
    string name;

    void getData() {
        cout << "Enter Employee ID: ";
        cin >> id;

        cout << "Enter Employee Name: ";
        cin >> name;
    }

    void display() {
        cout << "Employee ID: " << id << endl;
        cout << "Employee Name: " << name << endl;
    }
};

// Derived class 1
class Manager : public Employee {
public:
    float salary;

    void getSalary() {
        cout << "Enter Manager Salary: ";
        cin >> salary;
    }

    void displayManager() {
        display();
        cout << "Manager Salary: " << salary << endl;
    }
};

// Derived class 2
class Developer : public Employee {
public:
    float salary;

    void getSalary() {
        cout << "Enter Developer Salary: ";
        cin >> salary;
    }

    void displayDeveloper() {
        display();
        cout << "Developer Salary: " << salary << endl;
    }
};

int main() {
    Manager m;
    Developer d;

    cout << "--- Manager Details ---" << endl;
    m.getData();
    m.getSalary();

    cout << "\n--- Developer Details ---" << endl;
    d.getData();
    d.getSalary();

    cout << "\n--- Employee Records ---" << endl;

    cout << "\nManager Information:" << endl;
    m.displayManager();

    cout << "\nDeveloper Information:" << endl;
    d.displayDeveloper();

    return 0;
}
