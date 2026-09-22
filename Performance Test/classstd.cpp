#include <iostream>
using namespace std;

class Student{

    int roll_no;
    char name;
    float marks;
    

    Student(){
    cout<<"Constructor initialized";

    }

    Student(int x,char y){

        roll_no=x;
        marks=y;

    }

    void display(int x, char y){

        cout<<"roll no :- "
    }
}