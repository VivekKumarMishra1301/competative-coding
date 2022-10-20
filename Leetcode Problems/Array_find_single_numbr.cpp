class Solution
{
public:
    int singleNumber(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int ind = 0;
        if (nums.size() == 1)
        {
            return nums[0];
        }
        for (int i = 1; i < nums.size() - 1; i++)
        {
            if (nums[i] != nums[i + 1] && nums[i] != nums[i - 1])
            {
                return nums[i];
            }
        }
        if (nums[0] != nums[1])
        {
            return nums[0];
        }
        ind = nums.size() - 1;
        if (nums[ind] != nums[ind - 1])
        {
            return nums[ind];
        }
        return 0;
    }
};