class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        if (nums.size() == 1)
        {
            return nums[0];
        }
        sort(nums.begin(), nums.end());
        int i = 1;
        int count = 1;
        int maxcount = 1;
        int max = nums[i];
        while (i < nums.size())
        {
            if (nums[i] == nums[i - 1])
            {
                count++;
                i++;
            }
            else
            {
                if (maxcount < count)
                {
                    maxcount = count;
                    max = nums[i - 1];
                    count = 1;
                }
                i++;
            }
        }
        if (maxcount < count)
        {
            maxcount = count;
            max = nums[i - 1];
            count = 1;
        }
        return max;
    }
};