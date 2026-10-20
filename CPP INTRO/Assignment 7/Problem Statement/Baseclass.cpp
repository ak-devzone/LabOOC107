/*
Question: Create a Base Class Employee
(Employee ID, Employee Name, Department).
*/

#include <iostream>
using namespace std;

class Employee {
public:
    int emp_id;
    string emp_name, department;

    void getData() {
        cout << "Enter Employee ID: ";
        cin >> emp_id;

        cout << "Enter Employee Name: ";
        cin >> emp_name;

        cout << "Enter Department: ";
        cin >> department;
    }

    void display() {
        cout << "Employee ID: " << emp_id << endl;
        cout << "Employee Name: " << emp_name << endl;
        cout << "Department: " << department << endl;
    }
};

int main() {
    Employee e;

    e.getData();

    cout << "\nEmployee Details:\n";
    e.display();

    return 0;
}