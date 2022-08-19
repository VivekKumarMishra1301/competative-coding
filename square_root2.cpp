#include <iostream>
using namespace std;
int main()
{
    int n, r1, r2, d1, d2;
    cin >> n;
    int i = 1;
    while (i * i <= n)
    {
        i++;
    }

    r1 = i - 1;
    r2 = i;
    d1 = n - r1 * r1;
    d2 = r2 * r2 - n;
    if (d1 < d2)
    {
        cout << r1;
    }
    else
    {
        cout << r2;
    }
}