#include <iostream>
using namespace std;

#include <bits/stdc++.h>

int countBT(int n, vector<int> &dp)
{
    if (n <= 1)
    {
        return 1;
    }

    if (dp[n] != -1)
    {
        return dp[n];
    }

    int a = countBT(n - 1, dp);
    int b = countBT(n - 2, dp);

    int mod = (int)(pow(10, 9)) + 7;
    int x = (int)(((long)(a)*a) % mod);
    int y = (int)((2 * (long)(a)*b) % mod);
    int ans = (x + y) % mod;
    return dp[n] = ans;
}

int balancedBTs(int n)
{
    // Write your code here
    vector<int> dp(n + 1, -1);
    return countBT(n, dp);
}

int main()
{
    int n;
    cin >> n;
    cout << balancedBTs(n);
}