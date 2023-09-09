#include <bits/stdc++.h>
using namespace std;
int main()
{
    // write your code here
    int t;
    cin >> t;
    while (t--)
    {
        int n, bit;
        cin >> n >> bit;
        cout << (n & ((1 << bit) - 1)) << endl;
    }

    return 0;
}