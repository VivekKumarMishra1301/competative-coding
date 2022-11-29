#include <iostream>
using namespace std;
class Vehicle
{
public:
    string color;

    // Pure virtual fn
    virtual void print() = 0;
};

class Car : public Vehicle
{
public:
    int numGears;

    void print()
    {
        cout << "Car" << endl;
    }
};

int main()
{
    // Vehicle v; we can not create the object of the abstract class

    Car c;
    c.print();
}
