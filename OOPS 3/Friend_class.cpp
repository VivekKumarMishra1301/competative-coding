#include <iostream>
using namespace std;

class Bus
{
public:
    void print();
    void print2();
};

void test();

class Truck
{
private:
    int x;

protected:
    int y;

public:
    int z;

    friend class Bus;
};

void Bus ::print()
{
    Truck t;
    t.x = 10;
    t.y = 20;
    cout << t.x << " " << t.y << endl;
}

void Bus ::print2()
{
    Truck t;
    t.x = 10;
    t.y = 20;
    cout << t.x << " " << t.y << endl;
}

int main()
{
    Bus b;
    b.print();

    test();
}
