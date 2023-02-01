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
        int a, b, c, d;
        cin >> a >> b >> c >> d;

        int dist1 = abs(a * a + b * b);
        int dist2 = abs(c * c + d * d);
        if (dist1 > dist2)
        {
            cout << "ALEX" << endl;
        }
        else if (dist1 < dist2)
        {
            cout << "BOB" << endl;
        }
        else
        {
            cout << "EQUAL" << endl;
        }
    }
    return 0;
}
