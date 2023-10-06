class Solution
{
public:
    int memo(int n, vector<int> &dp, bool flag)
    {

        if (n == 1 || n == 0)
        {

            return 1;
        }

        if (dp[n] != -1)
        {

            return dp[n];
        }

        int k = n;

        if (flag)
        {

            k--;
        }

        int maxi = INT_MIN;

        while (k)
        {

            maxi = max(maxi, k * memo(n - k, dp, false));

            k--;
        }

        return dp[n] = maxi;
    }

    int integerBreak(int n)
    {

        vector<int> dp(58, -1);

        return memo(n, dp, true);
    }
};