class Solution
{
public:
    bool isPow(int n)
    {
        return n > 0 and (n & (n - 1)) == 0;
    }
    vector<int> countBits(int n)
    {
        // cout<<isPow(16)<<" ";
        vector<int> dp(n + 1, 0);
        dp[0] = 0;
        if (n == 0)
        {
            return dp;
        }
        dp[1] = 1;
        int ls = 0;
        for (int i = 2; i <= n; i++)
        {
            if (isPow(i))
            {
                dp[i] = 1;
                ls = i;
            }
            else
            {

                dp[i] = dp[ls] + dp[i - ls];
            }
        }
        cout << endl;
        return dp;
    }
};