#include <iostream>
using namespace std;
int main()
{
    int x, y = 1;
    x = 10;
    if (x != 10 && x / 0 == 0)
        cout << y; /*==printf("%d",y);*/
    else
        cout << ++y; /*==printf("%d",++y);*/
}