// User function Template for C++
class Solution
{
public:
    long long int dp[1001][1001];
    long long int mod = 1e9 + 7;

    long long int ways(int n, int x, int i)
    {
        if (n == 0)
        {
            return 1;
        }

        if (i > n)
        {
            return 0;
        }

        if (dp[n][i] != -1)
        {
            return dp[n][i] % mod;
        }

        long long int num = pow(i, x);
        if (num <= n)
        {
            dp[n][i] = ways(n - num, x, i + 1) + ways(n, x, i + 1);
            return dp[n][i] % mod;
        }
        else
        {
            dp[n][i] = 0;
            return dp[n][i] % mod;
        }
    }

    int numOfWays(int n, int x)
    {
        // code here
        //  vector<int> memo(a, -1);
        memset(dp, -1, sizeof(dp));
        return ways(n, x, 1);
    }
};