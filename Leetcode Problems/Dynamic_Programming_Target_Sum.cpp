class Solution
{
public:
    int find(vector<int> &nums, int tar)
    {
        int n = nums.size();
        vector<int> prev(tar + 1, 0);
        vector<int> curr(tar + 1, 0);
        if (nums[0] == 0)
        {
            prev[0] = 2;
        }
        else
        {
            prev[0] = 1;
        }
        if (nums[0] != 0 && nums[0] <= tar)
        {
            prev[nums[0]] = 1;
        }
        for (int ind = 1; ind < n; ind++)
        {
            for (int sum = 0; sum <= tar; sum++)
            {
                int nottake = prev[sum];
                int take = 0;
                if (nums[ind] <= sum)
                    take = prev[sum - nums[ind]];
                curr[sum] = nottake + take;
            }
            prev = curr;
        }
        return prev[tar];
    }

    int countPart(int n, int d, vector<int> &nums)
    {
        int totsum = 0;
        for (auto i : nums)
        {
            totsum += i;
        }
        if (totsum - d < 0 || (totsum - d) % 2)
            return 0;
        return find(nums, (totsum - d) / 2);
    }

    int findTargetSumWays(vector<int> &nums, int target)
    {
        return countPart(nums.size(), target, nums);
    }
};