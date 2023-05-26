class Solution
{
public:
    int stoneGameII(vector<int> &piles)
    {
        int n = piles.size();
        vector<int> ss(n + 1);
        ss[n - 1] = piles[n - 1];
        for (int i = n - 2; i >= 0; i--)
        {
            ss[i] = ss[i + 1] + piles[i];
        }

        vector<vector<int>> dp(n, vector<int>(n + 1));
        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = 1; j <= n; j++)
            {
                if (i + 2 * j >= n)
                {
                    dp[i][j] = ss[i];
                }
                else
                {
                    for (int x = 1; x <= 2 * j; x++)
                    {
                        int ops = dp[i + x][max(x, j)];
                        int sc = ss[i] - ops;
                        dp[i][j] = max(dp[i][j], sc);
                    }
                }
            }
        }
        return dp[0][1];
    }
};