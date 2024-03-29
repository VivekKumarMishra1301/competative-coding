class Solution
{
public:
    int distinct(string s, string t, int i, int j, vector<vector<int>> &dp)
    {
        if (j < 0)
            return 1;
        if (i < 0)
            return 0;

        if (dp[i][j] != -1)
        {
            return dp[i][j];
        }
        if (s[i] == t[j])
            return dp[i][j] = distinct(s, t, i - 1, j - 1, dp) + distinct(s, t, i - 1, j, dp);
        else
            return dp[i][j] = distinct(s, t, i - 1, j, dp);
    }

    int numDistinct(string s, string t)
    {
        vector<vector<int>> dp(s.size() + 1, vector<int>(t.size() + 1, -1));

        return distinct(s, t, s.size() - 1, t.size() - 1, dp);
    }
};