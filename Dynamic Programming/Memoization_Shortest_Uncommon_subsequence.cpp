#include <iostream>
#include <string>
using namespace std;

#include <bits/stdc++.h>
int tabulation(int n, int m, string &s, string &t, vector<vector<int>> &dp)
{
    if (n == 0)
    {
        return INT_MAX - 5;
    }
    if (m == 0)
    {
        return 1;
    }
    if (dp[n][m] != -1)
    {
        return dp[n][m];
    }
    int ans = INT_MAX - 5;
    int c = s[n - 1];
    int j;
    for (j = m - 1; j >= 0; j--)
    {
        if (t[j] == c)
        {
            break;
        }
    }
    if (j == -1)
    {
        ans = 1;
    }
    else
    {
        ans = min(tabulation(n - 1, m, s, t, dp), tabulation(n - 1, j, s, t, dp) + 1);
    }
    return dp[n][m] = ans;
}

int solve(string s, string v)
{
    // Write your code here
    vector<vector<int>> dp(s.size() + 1, vector<int>(v.size() + 1, -1));
    return tabulation(s.size(), v.size(), s, v, dp);
}

int main()
{
    string s, v;
    cin >> s >> v;
    cout << solve(s, v);
}