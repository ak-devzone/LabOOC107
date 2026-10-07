#include <iostream>
using namespace std;

// Abstract class
class Vehicle
{
public:
    // Pure virtual functions
    virtual void start() = 0;
    virtual void stop() = 0;
};

// Derived class Car
class Car : public Vehicle
{
public:
    void start()
    {
        cout << "Car starts with a key." << endl;
    }

    void stop()
    {
        cout << "Car stops using brakes." << endl;
    }
};

// Derived class Bike
class Bike : public Vehicle
{
public:
    void start()
    {
        cout << "Bike starts with self-start." << endl;
    }

    void stop()
    {
        cout << "Bike stops using brakes." << endl;
    }
};

int main()
{
    Vehicle *v;

    Car c;
    Bike b;

    // Runtime polymorphism
    v = &c;
    v->start();
    v->stop();

    v = &b;
    v->start();
    v->stop();

    return 0;
}