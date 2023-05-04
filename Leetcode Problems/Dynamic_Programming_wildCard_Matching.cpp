class Solution
{
public:
    bool match(string &s, string &t, int i, int j, vector<vector<int>> &dp)
    {
        if (i < 0 && j < 0)
            return 1;
        if (i < 0)
        {
            return 0;
        }
        if (j < 0)
        {
            for (int m = 0; m <= i; m++)
            {
                if (s[m] != '*')
                    return 0;
            }
            return 1;
        }

        if (dp[i][j] != -1)
        {
            return dp[i][j];
        }
        if (s[i] == t[j] || s[i] == '?')
            return dp[i][j] = match(s, t, i - 1, j - 1, dp);
        else if (s[i] == '*')
            return dp[i][j] = match(s, t, i - 1, j, dp) || match(s, t, i, j - 1, dp);
        else
        {
            return false;
        }
    }

    bool isMatch(string s, string p)
    {
        vector<vector<int>> dp(p.size() + 1, vector<int>(s.size() + 1, -1));

        return match(p, s, p.size() - 1, s.size() - 1, dp);
    }
};