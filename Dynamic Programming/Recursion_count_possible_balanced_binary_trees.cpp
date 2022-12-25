#include <iostream>
using namespace std;

#include <bits/stdc++.h>
int balancedBTs(int n)
{
    // Write your code here
    if (n <= 1)
    {
        return 1;
    }
    int a = balancedBTs(n - 1);
    int b = balancedBTs(n - 2);

    int mod = (int)(pow(10, 9)) + 7;
    int x = (int)(((long)(a)*a) % mod);
    int y = (int)((2 * (long)(a)*b) % mod);
    int ans = (x + y) % mod;
    return ans;
}

int main()
{
    int n;
    cin >> n;
    cout << balancedBTs(n);
}