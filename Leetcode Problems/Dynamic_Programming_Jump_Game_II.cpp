class Solution
{
public:
    int jumpak(vector<int> &nums, int x, vector<int> &dp)
    {
        if (x >= nums.size() - 1)
        {
            return 0;
        }
        if (dp[x] != 15000)
        {
            return dp[x];
        }
        int steps = INT_MAX;
        for (int j = 1; j <= nums[x]; j++)
        {
            dp[x] = min(dp[x], 1 + jumpak(nums, x + j, dp));
        }

        return dp[x];
    }

    int jump(vector<int> &nums)
    {
        vector<int> dp(nums.size(), 15000);
        int k = jumpak(nums, 0, dp);
        for (int i = 0; i < dp.size(); i++)
        {
            cout << dp[i] << " ";
        }
        return k;
    }
};
