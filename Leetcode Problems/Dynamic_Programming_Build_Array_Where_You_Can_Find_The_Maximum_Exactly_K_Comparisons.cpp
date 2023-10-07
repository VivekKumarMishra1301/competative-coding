class Solution
{
public:
    int mod = 1e9 + 7;
    int memo(int n, int m, int k, int maxi, int tot, int totalCost, vector<vector<vector<int>>> &dp)
    {
        if (tot == n)
        {
            return totalCost == k;
        }
        if (dp[tot][maxi + 1][totalCost] != -1)
        {
            return dp[tot][maxi + 1][totalCost];
        }
        long ans = 0;
        for (int i = 1; i <= m; i++)
        {
            int nm = maxi;
            int cst = totalCost;
            if (maxi < i)
            {
                nm = i;
                cst++;
            }
            ans = (ans + memo(n, m, k, nm, tot + 1, cst, dp) % mod) % mod;
        }
        return dp[tot][maxi + 1][totalCost] = ans % mod;
    }

    int numOfArrays(int n, int m, int k)
    {
        vector<vector<vector<int>>> dp(51, vector<vector<int>>(102, vector<int>(52, -1)));
        return memo(n, m, k, -1, 0, 0, dp);
    }
};