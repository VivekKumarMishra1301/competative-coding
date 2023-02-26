class Solution
{
public:
    string longestPalindrome(string s)
    {
        int n = s.size();
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        string hold = "";
        // hold=s.substr(1,4);
        // cout<<hold;
        int maxsize = 0;
        for (int gap = 0; gap < n; gap++)
        {
            for (int i = 0, j = gap; j < n; i++, j++)
            {
                // cout<<i<<j<<s.substr(i,j-i+1)<<" ";
                if (gap == 0)
                {
                    dp[i][j] = true;
                }
                else if (gap == 1)
                {
                    if (s[i] == s[j])
                    {
                        dp[i][j] = true;
                    }
                    else
                    {
                        dp[i][j] = false;
                    }
                }
                else
                {
                    if (s[i] == s[j] && dp[i + 1][j - 1])
                    {
                        dp[i][j] = true;
                    }
                    else
                    {
                        dp[i][j] = false;
                    }
                }
                if (dp[i][j])
                {
                    // cout<<i<<j<<" ";
                    if ((j - i + 1) > maxsize)
                    { // you can make make size of substring =gap+1;
                        maxsize = j - i + 1;
                        hold = s.substr(i, (j - i + 1));
                    }
                }
            }
        }
        return hold;
    }
};