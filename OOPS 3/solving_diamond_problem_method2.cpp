
// using Scope Resolution Operator by specifying the print function of a particular class

#include <iostream>
using namespace std;
class Vehicle
{
private:
    int maxSpeed;

protected:
    int numTyres;

public:
    string color;

    Vehicle()
    {
        cout << "Vehicle's default constructor " << endl;
    }

    void print()
    {
        cout << "Vehicle" << endl;
    }

    // Vehicle(int z) {
    // cout << "Vehicle's Parametrized constructor " << z << endl;
    // 	maxSpeed = z;
    // }

    ~Vehicle()
    {
        cout << "Vehicle's Destructor " << endl;
    }
};

class Car : public Vehicle
{
public:
    int numGears;

    Car()
    {
        cout << "Car's default constructor " << endl;
    }

    /*
    Car(int x, int y) : Vehicle(x) {
        cout << "Car's constructor " << endl;
        numGears = y;
    }*/

    ~Car()
    {
        cout << "Car's Destructor " << endl;
    }

    /*
            void print() {
                cout << "NumTyres : " << numTyres << endl;
                cout << "Color : " << color << endl;
                cout << "Num gears : " << numGears << endl;
                //		cout << "Max Speed : " << maxSpeed << endl;
            }
    */
};

class Truck : public Vehicle
{
public:
    Truck()
    {
        cout << "Truck's constructor " << endl;
    }
    ~Truck()
    {
        cout << "Truck's destructor " << endl;
    }
};

class Bus : public Car, public Truck
{
public:
    Bus()
    {
        cout << "Bus's constructor " << endl;
    }

    ~Bus()
    {
        cout << "Bus's destructor " << endl;
    }
};

int main()
{
    Bus b;
    b.Car::print();
}
