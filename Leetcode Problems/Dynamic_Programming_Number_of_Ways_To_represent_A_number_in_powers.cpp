class Solution
{
public:
    int mod = 1000000007;
    long memo(long ind, long t, long n, long x, vector<vector<long>> &dp)
    {
        // cout<<ind<<" ";
        if (t == 0)
        {
            return 1;
        }
        if (ind > n)
        {
            return 0;
        }
        if (t < 0)
        {
            return 0;
        }
        if (dp[ind][t] != -1)
        {
            return dp[ind][t];
        }

        long pick = memo(ind + 1, t - pow(ind, x), n, x, dp) % mod;
        long np = memo(ind + 1, t, n, x, dp) % mod;

        return dp[ind][t] = (pick + np) % mod;
    }

    int numberOfWays(int n, int x)
    {
        vector<vector<long>> dp(n + 1, vector<long>(n + 1, -1));
        return memo(1, n, n, x, dp);
    }
};