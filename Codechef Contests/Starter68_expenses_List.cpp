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
        int p, q;
        cin >> p >> q;
        int ex = pow(2, q);

        for (int i = 0; i < p; i++)
        {
            ex /= 2;
        }
        cout << ex << endl;
    }
    return 0;
}
