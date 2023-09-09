class Solution
{
public:
    int memo(int ind, int t, vector<int> &nums, vector<vector<int>> &dp)
    {
        if (t == 0)
        {
            return 1;
        }
        if (ind == nums.size())
        {
            return t == 0;
        }

        if (dp[ind][t] != -1)
        {
            return dp[ind][t];
        }

        int ans = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] <= t)
            {
                ans += memo(i, t - nums[i], nums, dp);
            }
        }
        return dp[ind][t] = ans;
    }

    int combinationSum4(vector<int> &nums, int target)
    {
        vector<vector<int>> dp(nums.size() + 1, vector<int>(target + 1, -1));
        return memo(0, target, nums, dp);
    }
};