class Solution
{
public:
    bool canPartition(vector<int> &nums)
    {
        if (nums.size() == 1)
        {
            return false;
        }
        int totalsum = 0;
        for (auto i : nums)
        {
            totalsum += i;
        }
        if (totalsum % 2 != 0)
        {
            return false;
        }
        int requiredsum = totalsum / 2;
        vector<vector<bool>> dp(nums.size() + 1, vector<bool>(20001, false));

        for (int i = 0; i <= nums.size(); i++)
        {
            dp[i][0] = true;
        }
        dp[0][nums[0]] = true;
        for (int i = 1; i < nums.size(); i++)
        {
            for (int j = 1; j <= requiredsum; j++)
            {
                bool notpick = dp[i - 1][j];
                bool pick = false;
                if (j >= nums[i])
                {
                    pick = dp[i - 1][j - nums[i]];
                }
                dp[i][j] = pick || notpick;
            }
        }

        return dp[nums.size() - 1][requiredsum];
    }
};