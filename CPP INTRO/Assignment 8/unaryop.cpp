// C++ program to show unary operator overloading

#include <iostream>
using namespace std;

class Distance
{
public:
    int feet, inch;
   

    // Constructor to initialize the object's value
    Distance(int f, int i)
    {
        this->feet = f;
        this->inch = i;
    }

    // Overloading (-) operator
    void operator-()
    {
        feet--;
        inch--;

        cout << "\nFeet & Inches (Decrement): "
             << feet << " " << inch <<endl;
    }

       void operator+()
    {
        feet=+3;
        inch=+3;

        cout << "\nFeet & Inches (Decrement): "
             << feet << " " << inch <<endl;
    }
};

// Driver code
int main()
{
    Distance d1(8, 9);
     int a=10;
     int b=20;
     int c=a+b;

     cout<<c;

    // Use unary operator as a single operand
    +d1;
 
    cout<< d1.feet<<" " << d1.inch;


    return 0;
}