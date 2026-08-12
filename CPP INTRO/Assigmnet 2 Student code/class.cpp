#include <iostream>
#include <string>

using namespace std;

void inputDetails();

class Student
{
private:
    string name;
//public:
    int rollNo;
    float marks;

public:
    void inputDetails()
    {
        cout << "Enter Student Name: ";
        getline(cin >> ws, name);

        cout << "Enter Roll Number: ";
        cin >> rollNo;

        cout << "Enter Marks: ";
        cin >> marks;
    }
public:
    void displayDetails() const
    {
        cout << "\n----- Student Details -----\n";
        cout << "Name    : " << name << endl;
        cout << "Roll No.: " << rollNo << endl;
        cout << "Marks   : " << marks << endl;
    }
};

int main()

{
    
    Student s;

    s.inputDetails();
    //s.rollNo=100;
    s.displayDetails();

    return 0;
}