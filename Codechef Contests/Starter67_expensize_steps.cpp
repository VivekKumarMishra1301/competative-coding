#include <iostream>
using namespace std;
#include <bits/stdc++.h>
int main()
{
    // your code goes here
    int t;
    cin >> t;
    while (t--)
    {
        int boundary;
        cin >> boundary;
        int p, q, r, s;
        cin >> p >> q >> r >> s;
        int dist1 = abs(p - r) + abs(s - q);
        int x = min(min(p, boundary - p + 1), min(q, boundary - q + 1));
        int y = min(min(r, boundary - r + 1), min(s, boundary - s + 1));
        cout << min(dist1, x + y) << endl;
    }
    return 0;
}
