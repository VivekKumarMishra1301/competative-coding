int cutRod(vector<int> &price, int n)
{

    // Write your code here.
    vector<vector<int>> dp(n, vector<int>(n + 1, 0));
    for (int i = 0; i <= n; i++)
    {
        dp[0][i] = i * price[0];
    }

    for (int ind = 1; ind < n; ind++)
    {
        for (int i = 0; i <= n; i++)
        {

            int notpick = dp[ind - 1][i];
            int pick = INT_MIN;
            int rodlength = ind + 1;
            if (rodlength <= i)
            {
                pick = price[ind] + dp[ind][i - rodlength];
            }
            dp[ind][i] = max(pick, notpick);
        }
    }
    return dp[n - 1][n];
}
