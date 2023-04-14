class Solution
{
public:
    int lcs(string text1, string text2, int i, int j, vector<vector<int>> &dp)
    {
        int n = text1.size();
        int m = text2.size();
        vector<int> prev(m + 1, 0);
        vector<int> curr(m + 1, 0);
        for (int i = 0; i <= m; i++)
        {
            prev[i] = 0;
        }

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (text1[i - 1] == text2[j - 1])
                {
                    curr[j] = 1 + prev[j - 1];
                }
                else
                {
                    curr[j] = max(prev[j], curr[j - 1]);
                }
            }
            prev = curr;
        }
        return prev[m];
    }

    int longestPalindromeSubseq(string s)
    {
        string s2 = s;
        reverse(s2.begin(), s2.end());
        vector<vector<int>> dp(s.size() + 1, vector<int>(s.size() + 1, -1));

        return lcs(s, s2, s.size() - 1, s2.size() - 1, dp);
    }
};