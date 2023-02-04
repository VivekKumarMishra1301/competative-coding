class Solution
{
public:
    int minimumDeleteSum(string word1, string word2)
    {
        int m = word1.size();
        int n = word2.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        vector<vector<int>> asc(m + 1, vector<int>(n + 1, 0));
        int sum1 = 0;
        asc[0][0] = 0;
        for (int i = 1; i <= m; i++)
        {
            dp[i][0] = i;

            sum1 += word1[i - 1];
            asc[i][0] = sum1;
        }
        int sum2 = 0;
        for (int j = 1; j <= n; j++)
        {
            sum2 += word2[j - 1];
            dp[0][j] = j;
            asc[0][j] = sum2;
        }

        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                int ans;
                if (word1[i - 1] == word2[j - 1])
                {
                    // ans = dp[i - 1][j - 1];
                    asc[i][j] = asc[i - 1][j - 1];
                }
                else
                {
                    // int a = 1 + dp[i - 1][j];
                    // int b = 1 + dp[i][j - 1];
                    // int c = 1 + dp[i - 1][j - 1];
                    int c = word1[i - 1] + asc[i - 1][j];
                    int d = word2[j - 1] + asc[i][j - 1];
                    // ans = min(a, b);
                    asc[i][j] = min(c, d);
                    // ans=b;
                }
                // dp[i][j] = ans;
            }
        }
        return asc[m][n];
    }
};