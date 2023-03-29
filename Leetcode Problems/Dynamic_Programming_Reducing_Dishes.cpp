class Solution
{
public:
    int memo(vector<int> &satisfaction, vector<vector<int>> &dp, int ind, int mul)
    {
        if (ind == satisfaction.size())
        {
            return 0;
        }

        if (dp[ind][mul] != INT_MIN)
        {
            return dp[ind][mul];
        }

        int ans = 0;
        int notpick = memo(satisfaction, dp, ind + 1, mul);
        int pick = mul * satisfaction[ind] + memo(satisfaction, dp, ind + 1, mul + 1);
        return dp[ind][mul] = max(max(ans, notpick), pick);
    }

    int maxSatisfaction(vector<int> &satisfaction)
    {
        sort(satisfaction.begin(), satisfaction.end());
        vector<vector<int>> dp(satisfaction.size() + 1, vector<int>(satisfaction.size() + 1, INT_MIN));
        return memo(satisfaction, dp, 0, 1);
    }
};