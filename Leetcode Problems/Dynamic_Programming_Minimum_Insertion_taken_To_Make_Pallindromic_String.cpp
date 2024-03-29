class Solution
{
public:
    int dp[501][501] = {};
    int longestPalindromeSubseq(string &s)
    {
        for (int len = 1; len <= s.size(); ++len)
            for (int i = 0; i + len <= s.size(); ++i)
                dp[i][i + len] = s[i] == s[i + len - 1] ? dp[i + 1][i + len - 1] + (len == 1 ? 1 : 2)
                                                        : max(dp[i][i + len - 1], dp[i + 1][i + len]);
        return dp[0][s.size()];
    }

    int minInsertions(string s)
    {
        return s.size() - longestPalindromeSubseq(s);
    }
};