

#include <bits/stdc++.h>
using namespace std;
class A
{
public:
    int a;
    A()
    {
        cout << "default constructor A" << endl;
    }
};

class B : public A
{
public:
    int b;
    B()
    {
        cout << "default constructor B" << endl;
    }
};
int main()
{
    B obj1;
}