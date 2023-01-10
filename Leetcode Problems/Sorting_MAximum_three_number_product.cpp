class Solution
{
public:
    int maximumProduct(vector<int> &nums)
    {
        int prod = 1;
        sort(nums.begin(), nums.end());
        if (nums[nums.size() - 1] <= 0)
        {
            return nums[nums.size() - 1] * nums[nums.size() - 2] * nums[nums.size() - 3];
        }

        if (nums[0] >= 0)
        {
            return nums[nums.size() - 1] * nums[nums.size() - 2] * nums[nums.size() - 3];
        }

        int prod1 = nums[0] * nums[1] * nums[nums.size() - 1];
        int prod2 = nums[nums.size() - 1] * nums[nums.size() - 2] * nums[nums.size() - 3];
        if (prod1 > prod2)
        {
            return prod1;
        }
        else
        {
            return prod2;
        }
    }
};