#include <bits/stdc++.h>
int maxpath(int i, int j, vector<vector<int>> &dp, vector<vector<int>> &matrix)
{
    if (j >= matrix[0].size() || j < 0)
    {
        return -1e8;
    }
    if (i == 0)
    {
        return matrix[0][j];
    }

    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }
    int vertical = matrix[i][j] + maxpath(i - 1, j, dp, matrix);
    int leftdia = matrix[i][j] + maxpath(i - 1, j - 1, dp, matrix);
    int rightdia = matrix[i][j] + maxpath(i - 1, j + 1, dp, matrix);
    return dp[i][j] = max(vertical, max(leftdia, rightdia));
}
int getMaxPathSum(vector<vector<int>> &matrix)
{

    //  Write your code here.
    int n = matrix.size();
    int m = matrix[0].size();

    vector<vector<int>> dp(n, vector<int>(m, -1));
    int maxi = -1e8;
    for (int i = 0; i < matrix[0].size(); i++)
    {
        maxi = max(maxi, maxpath(n - 1, i, dp, matrix));
    }
    return maxi;
}