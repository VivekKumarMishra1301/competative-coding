class Solution
{
public:
    int find(vector<int> &nums, int ind, int k, int sum)
    {
        if (ind == 0)
        {
            if (nums[ind] + sum == k || sum - nums[ind] == k)
            {
                return 1;
            }
            return 0;
        }
        int pos = find(nums, ind - 1, k, sum - nums[ind]);
        int neg = find(nums, ind - 1, k, sum + nums[ind]);
        return pos + neg;
    }

    int findTargetSumWays(vector<int> &nums, int target)
    {
        return find(nums, nums.size() - 1, target, 0);
    }
};