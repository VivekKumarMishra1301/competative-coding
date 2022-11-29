

#include <bits/stdc++.h>
using namespace std;
class A
{
public:
    int a;
    A(int y)
    {
        cout << "Parametrized constructor" << y << endl;
    }
};

class B : public A
{
public:
    int b;
};
int main()
{
    B obj1; // in this case error will be generated because parent doesnt have default constructor child only can implicitly call the default constructor
}