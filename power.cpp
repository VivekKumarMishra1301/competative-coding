#include <iostream>
using namespace std;

int main()
{
    int x, n, mul = 1;
    cin >> x >> n;
    if (x >= 0 && x <= 8 && n >= 0 && n <= 9)
    {
        int i = 1;
        while (i <= n)
        {
            mul = mul * x;
            i = i + 1;
        }
        cout << mul;
    }
}
