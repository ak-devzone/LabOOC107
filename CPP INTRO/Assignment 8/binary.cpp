// C++ program to show binary operator overloading   .  ..
// mandatory 

#include <iostream>
using namespace std;

class Distance
{
public:
    int feet, inch;

    // Default constructor
    Distance()
    {
        this->feet = 0;
        this->inch = 0;
    }

    // Parameterized constructor
    Distance(int f, int i)
    {
        this->feet =f;
        this->inch =i;
    }

    // Overloading (+) operator
    Distance operator+(Distance &d2)
    {
        
       // change
        cout<< d2.feet  <<" and "<< d2.inch << endl;
        // Create an object to return
        Distance d3;
        //this is calling object 

        d3.feet = this->feet + d2.feet;
        d3.inch = this->inch + d2.inch;
// change
        cout<< "i am from op "<<d2.feet;
        this->feet = this->feet + 30;
        d2.feet= d2.feet + 30;
        
        // Return the result
        return d3;
    }
};

// Driver code
int main()
{
    Distance d1(8, 9);
    Distance d2(10, 2);
    Distance d3;

    // Use overloaded operator
    d3 = d1 + d2; // in binary d1 is calling and d2 is parameter send to constructor.

    cout << "\nTotal Feet & Inches: "
         << d3.feet << "," << d3.inch << endl;
         // change
    cout<< "\n i am d1 feet " << d1.feet;
    cout<< "\n i am d2 feet " << d2.feet;

    return 0;
}