#include <bits/stdc++.h>

using namespace std;

int canYouMake(string &str, string &ptr)
{
    // Write your code here.

    int n = str.size();
    int m = ptr.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    for (int i = 0; i <= n; i++)
    {
        dp[i][0] = 0;
    }
    for (int j = 0; j <= m; j++)
    {
        dp[0][j] = 0;
    }
    // int hold = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (str[i - 1] == ptr[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
            // cout<<dp[i][j]<<" ";
            // hold = max(hold, dp[i][j]);
        }
        cout << endl;
    }
    return n + m - 2 * dp[n][m];
}