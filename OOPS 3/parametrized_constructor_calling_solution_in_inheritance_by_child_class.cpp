

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
    B() : A(5) // here we need to call the parent constructor explicitly in case absence of default constructor in parent class
    {
        cout << "Default constructor   B" << endl;
    }
};
int main()
{
    B obj1;
}