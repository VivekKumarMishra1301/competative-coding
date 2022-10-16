class Solution
{
public:
    int searchInsert(vector<int> &nums, int target)
    {
        if (target < nums[0])
        {
            return 0;
        }
        if (target > nums[nums.size() - 1])
        {
            return nums.size();
        }
        if (target == nums[0])
        {
            return 0;
        }
        int st = 0;
        int end = nums.size() - 1;

        while (st < end)
        {
            int mid = (st + end) / 2;
            if (nums[mid] == target)
            {
                return mid;
            }
            else if (nums[mid] < target)
            {
                st = mid + 1;
            }
            else
            {
                end = mid - 1;
            }
        }
        if (target > nums[st])
        {
            return st + 1;
        }
        return st;
    }
};