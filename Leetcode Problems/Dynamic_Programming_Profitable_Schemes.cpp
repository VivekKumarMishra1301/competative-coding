class Solution
{
public:
    int profitableSchemes(int n, int minProfit, vector<int> &group, vector<int> &profit)
    {
        int mod = 1e9 + 7;
        int sz = group.size();
        vector<vector<vector<int>>> dp(sz + 1, vector<vector<int>>(minProfit + 1, vector<int>(n + 1, 0)));

        dp[0][0][0] = 1;
        for (int i = 1; i <= sz; i++)
        {
            int g = group[i - 1];
            int p = profit[i - 1];
            for (int j = 0; j <= minProfit; j++)
            {
                for (int k = 0; k <= n; k++)
                {
                    dp[i][j][k] = dp[i - 1][j][k];
                    if (k >= g)
                    {
                        dp[i][j][k] = (dp[i][j][k] + dp[i - 1][max(0, j - p)][k - g]) % mod;
                    }
                }
            }
        }
        int hold = 0;
        for (int k = 0; k <= n; k++)
        {
            hold = (hold + dp[sz][minProfit][k]) % mod;
        }
        return hold;
    }
};