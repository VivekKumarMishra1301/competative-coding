#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main()
{
    // your code goes here
    int t;
    cin >> t;
    while (t--)
    {
        long x, y;
        cin >> x >> y;

        long maxi = __gcd(x, y);
        long res = lcm(x, maxi) - __gcd(y, maxi);

        cout << res << endl;
    }
    return 0;
}
