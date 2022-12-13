#include <bits/stdc++.h>
int minpath(vector<vector<int>> &vec, int n)
{
    int dp[n][n];
    for (int j = 0; j < n; j++)
    {
        dp[0][j] = vec[0][j];
    }
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int vert = vec[i][j] + dp[i - 1][j];
            int leftdia = vec[i][j];
            if (j - 1 >= 0)
                leftdia += dp[i - 1][j - 1];
            else
                leftdia = 1e9;
            int rightdia = vec[i][j];
            if (j + 1 < n)
                rightdia += dp[i - 1][j + 1];
            else
                rightdia = 1e9;
            dp[i][j] = min(vert, min(leftdia, rightdia));
        }
    }

    int mini = dp[n - 1][0];
    for (int i = 1; i < n; i++)
    {
        mini = min(mini, dp[n - 1][i]);
    }
    return mini;
}
int minFallingPathSum(vector<vector<int>> &vec, int n)
{
    // Write your code here.
    return minpath(vec, n);
}