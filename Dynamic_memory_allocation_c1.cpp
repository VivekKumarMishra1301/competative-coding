#include <iostream>
using namespace std;
int main()
{
    // while (true)
    // {
    //     int i = 10;
    //     cout << i;
    // }
    while (true)
    {
        int *p = new int;
        *p = 10;
        cout << *p;
    }
}