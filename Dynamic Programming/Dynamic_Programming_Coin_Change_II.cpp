class Solution
{
public:
    int change(int amount, vector<int> &coins)
    {
        vector<vector<int>> dp(coins.size() + 1, vector<int>(amount + 1, 0));
        for (int i = 0; i <= amount; i++)
        {
            dp[0][i] = (i % coins[0] == 0);
        }

        for (int i = 1; i < coins.size(); i++)
        {
            for (int j = 0; j <= amount; j++)
            {
                int notpick = dp[i - 1][j];
                int pick = 0;
                if ((coins[i] <= j))
                {
                    pick = dp[i][j - coins[i]];
                }
                dp[i][j] = pick + notpick;
            }
        }
        return dp[coins.size() - 1][amount];
    }
};