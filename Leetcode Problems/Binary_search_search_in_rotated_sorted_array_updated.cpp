class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int st = 0;
        int en = nums.size() - 1;
        while (st <= en)
        {
            int mid = (st + en) / 2;
            if (nums[mid] == target)
            {
                return mid;
            }

            if (nums[mid] >= nums[st])
            {
                // if from starting to mid it is sorted check wether number is between the range or not if yes then take this part from starting to mid otherwise take rest of the part
                if (target >= nums[st] && target <= nums[mid])
                {
                    en = mid;
                }
                else
                {
                    st = mid + 1;
                }
            }
            else
            {
                // check in another part of available in the range go for the range otherwise leave it
                if (target >= nums[mid] && target <= nums[en])
                {
                    st = mid;
                }
                else
                {
                    en = mid - 1;
                }
            }
        }
        return -1;
    }
};