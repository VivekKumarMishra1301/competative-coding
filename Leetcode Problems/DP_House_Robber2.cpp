class Solution
{
public:
    int rob(vector<int> &nums)
    {
        if (nums.size() == 1)
        {
            return nums[0];
        }
        int prev1 = nums[0];
        int prev2 = 0;
        for (int i = 1; i < nums.size() - 1; i++)
        {
            int pick = nums[i];
            if (i > 1)
            {
                pick += prev2;
            }
            int notpick = prev1;

            int curr = max(pick, notpick);
            prev2 = prev1;
            prev1 = curr;
        }

        int pre1 = nums[1];
        int pre2 = 0;
        for (int i = 2; i < nums.size(); i++)
        {
            int pick = nums[i];
            if (i > 1)
            {
                pick += pre2;
            }
            int notpick = pre1;

            int curr = max(pick, notpick);
            pre2 = pre1;
            pre1 = curr;
        }
        return max(prev1, pre1);
    }
};