class Solution
{
public:
    double new21Game(int n, int k, int maxPts)
    {
        if (k == 0 || (k + maxPts <= n))
            return 1.0;
        vector<double> dp(n + 1, 0);
        dp[0] = 1.0;
        double res = 0;
        double ts = 1.0;
        for (int i = 1; i <= n; i++)
        {
            dp[i] = ts / maxPts;
            if (i < k)
            {
                ts += dp[i];
            }
            else
            {
                res += dp[i];
            }

            if ((i - maxPts) >= 0)
            {
                ts -= dp[i - maxPts];
            }
        }
        return res;
    }
};