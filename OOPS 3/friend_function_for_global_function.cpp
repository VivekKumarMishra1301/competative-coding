#include <iostream>
using namespace std;

void test();

class Truck
{
private:
    int x;

protected:
    int y;

public:
    int z;

    friend void test();
};

void test()
{
    // Access truck private
    Truck t;
    t.x = 10;
    t.y = 20;
    cout << t.x << " " << t.y << endl;
}

int main()
{

    test();
}
