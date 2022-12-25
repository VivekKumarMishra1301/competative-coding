#include <iostream>
using namespace std;

#include <bits/stdc++.h>

int countBT(int n, vector<int> &dp)
{

    dp[0] = 1;
    dp[1] = 1;
    for (int i = 2; i <= n; i++)
    {

        int a = dp[i - 1];
        int b = dp[i - 2];

        int mod = (int)(pow(10, 9)) + 7;
        int x = (int)(((long)(a)*a) % mod);
        int y = (int)((2 * (long)(a)*b) % mod);
        int ans = (x + y) % mod;

        dp[i] = ans;
    }

    return dp[n];
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