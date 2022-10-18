class Solution
{
public:
    int find(vector<int> &nums, int st, int end, int target)
    {
        while (st <= end)
        {
            int mid = (st + end) / 2;
            if (target == nums[mid])
            {
                return mid;
            }
            else if (target > nums[mid])
            {
                st = mid + 1;
            }
            else
            {
                end = mid - 1;
            }
        }
        return -1;
    }
    int search(vector<int> &nums, int target)
    {

        int end = 0;
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] < nums[i - 1])
            {
                end = i - 1;
                break;
            }
        }
        int result = find(nums, 0, end, target);
        if (result == -1 && end == 0 && end + 1 <= nums.size() - 1)
        {
            return find(nums, end + 1, nums.size() - 1, target);
        }
        else if (end == 0)
        {
            return result;
        }
        if (result == -1 && end != 0)
        {
            return find(nums, end + 1, nums.size() - 1, target);
        }
        else if (end == 0)
        {
            return find(nums, 0, nums.size() - 1, target);
        }
        else
        {
            return result;
        }
    }
};