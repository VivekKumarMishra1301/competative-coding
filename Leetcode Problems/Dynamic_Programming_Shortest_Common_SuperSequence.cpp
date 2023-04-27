class Solution
{
public:
    string shortestCommonSupersequence(string str1, string str2)
    {
        int n = str1.size();
        int m = str2.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        for (int i = 0; i <= n; i++)
        {
            dp[i][0] = 0;
        }
        for (int j = 0; j <= m; j++)
        {
            dp[0][j] = 0;
        }
        // int hold = 0;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (str1[i - 1] == str2[j - 1])
                {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                }
                else
                {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
                // cout<<dp[i][j]<<" ";
                // hold = max(hold, dp[i][j]);
            }
            // cout<<endl;
        }

        // vector<char>hold(n+m-d[n][m]);
        string hold = "";
        int i = n;
        int j = m;
        int ind = n + m - dp[n][m] - 1;
        while (i > 0 && j > 0)
        {
            if (str1[i - 1] == str2[j - 1])
            {
                hold += str1[i - 1];
                i--;
                j--;
            }
            else if (dp[i - 1][j] > dp[i][j - 1])
            {
                hold += str1[i - 1];
                i--;
            }
            else
            {
                hold += str2[j - 1];
                j--;
            }
        }
        while (j > 0)
        {
            hold += str2[j - 1];
            j--;
        }
        while (i > 0)
        {
            hold += str1[i - 1];
            i--;
        }
        reverse(hold.begin(), hold.end());
        return hold;
    }
};