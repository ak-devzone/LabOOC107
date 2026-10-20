#include <iostream>
using namespace std;

class Employee
{
public:
    virtual void calculateBonus()
    {
        cout << "Employee Bonus" << endl;
    }
};

class Manager : public Employee
{
public:
    void calculateBonus() override
    {
        cout << "Manager Bonus = 20% of salary" << endl;
    }
};

class Developer : public Employee
{
public:
    void calculateBonus() override
    {
        cout << "Developer Bonus = 10% of salary" << endl;
    }
};

int main()
{
    Employee *emp;

    Manager manager;
    Developer developer;

    emp = &manager;
    emp->calculateBonus();

    emp = &developer;
    emp->calculateBonus();

    return 0;
}