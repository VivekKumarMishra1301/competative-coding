class Solution
{
public:
    int mod = 1e9 + 7;
    int rest(int ind, string &s, int k, vector<int> &dp)
    {
        if (ind == s.size())
        {
            return 1;
        }
        if (s[ind] == '0')
        {
            return 0;
        }
        if (dp[ind] != -1)
            return dp[ind];
        long hold = 0;
        long num = 0;
        for (int i = ind; i < s.size(); i++)
        {
            long temp = s[i] - '0';
            num = num * 10 + temp;
            if (num > k)
                break;
            hold += rest(i + 1, s, k, dp);
            hold = hold % mod;
        }
        return dp[ind] = hold;
    }

    int numberOfArrays(string s, int k)
    {
        vector<int> dp(s.size(), -1);
        return rest(0, s, k, dp);
    }
};