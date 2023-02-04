#include <iostream>
#include <cstring>
using namespace std;

#include <bits/stdc++.h>

int edit_dp(string s, string t)
{
    int m = s.size();
    int n = t.size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    for (int i = 0; i <= m; i++)
    {
        dp[i][0] = i;
    }
    for (int j = 1; j <= n; j++)
    {
        dp[0][j] = j;
    }

    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            int ans;
            if (s[m - i] == t[n - j])
            {
                ans = dp[i - 1][j - 1];
            }
            else
            {
                int a = 1 + dp[i - 1][j];
                int b = 1 + dp[i][j - 1];
                int c = 1 + dp[i - 1][j - 1];
                ans = min(a, min(b, c));
            }
            dp[i][j] = ans;
        }
    }
    return dp[m][n];
}

int editDistance(string s1, string s2)
{
    // Write your code here
    //  vector<vector<int>>memo(s1.size()+1,vector<int>(s2.size()+1,-1));
    return edit_dp(s1, s2);
}

int main()
{
    string s1;
    string s2;

    cin >> s1;
    cin >> s2;

    cout << editDistance(s1, s2) << endl;
}