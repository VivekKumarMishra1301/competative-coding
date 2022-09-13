#include <iostream>
using namespace std;
int main()
{
    int a[] = {1, 2, 3, 4, 5};
    int *p = a;
    cout << *p + 1 << endl;

    *p = 358;
    cout << p[2] << endl;
    cout << a[1] << endl;
}