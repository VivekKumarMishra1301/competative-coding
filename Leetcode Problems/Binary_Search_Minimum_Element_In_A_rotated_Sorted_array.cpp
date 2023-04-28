class Solution
{
public:
    int findMin(vector<int> &nums)
    {
        int hold = nums[0];
        int st = 0;
        int en = nums.size() - 1;
        if (nums[en] < hold)
        {
            hold = nums[en];
        }
        while (st <= en)
        {
            int mid = (st + en) / 2;
            if (nums[mid] == hold)
            {
                // hold=nums[mid];
                return hold;
            }

            if (nums[mid] < hold)
            {
                hold = nums[mid];
            }
            if (nums[st] <= nums[mid])
            {
                if (nums[st] < hold)
                {
                    hold = nums[st];
                }
                st = mid + 1;
            }
            else
            {

                en = mid - 1;
            }
        }
        return hold;
    }
};