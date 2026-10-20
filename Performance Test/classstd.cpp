
#include <iostream>
#include <string>
using namespace std;

class Student {
    int roll_no;
    string name;
    float marks;

public:
    
    Student() {
        cout << "Constructor initialized" << endl;
    }

    Student(int x, string y, float z) {
        roll_no = x;
        name = y;
        marks = z;
    }

   
    void display() {
        cout << "Roll No: " << roll_no << endl;
        cout << "Name: " << name << endl;
        cout << "Marks: " << marks << endl;
    }
};

int main() {
    Student s1(107, "Avinash", 91.18);
    s1.display();

    return 0;
}
