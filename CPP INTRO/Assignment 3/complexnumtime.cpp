
#include <iostream>

using namespace std;

class Complex
{
private:
    int hours, min, sec;

public:
    Complex(int h = 0, int m = 0,int s=0) : hours(h), imag(i) {}

    Complex add(const Complex &c)
    {
        return Complex(real + c.real, imag + c.imag);
    }

    Complex subtract(const Complex &c)
    {
        return Complex(real - c.real, imag - c.imag);
    }

    void display() const
    {
        cout << real << " + i" << imag << endl;
    }
};

int main()
{
    Complex c1(4, 5), c2(8, 9);

    Complex sum = c1.add(c1);
    Complex diff = c1.subtract(c2);

    cout << "First Complex Number: ";
    c1.display();

    cout << "Second Complex Number: ";
    c2.display();

    cout << "Addition: ";
    sum.display();

    cout << "Subtraction: ";
    diff.display();

    c1.display();
    c2.display();

    return 0;
}