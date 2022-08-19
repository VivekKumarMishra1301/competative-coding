#include <iostream>
using namespace std;
int main()
{
    int x = 10;
    int y = 20;
    if (x++ > 10 && ++y > 20) /*x=10>10==false  0&&0or1==0*/
    {
        cout << "Inside if ";
    }
    else
    {
        cout << "Inside else ";
    }
    cout << x << " " << y;
}