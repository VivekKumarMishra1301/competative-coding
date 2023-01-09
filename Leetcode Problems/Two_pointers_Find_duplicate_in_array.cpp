class Solution
{
public:
    int findDuplicate(vector<int> &nums)
    {
        int fast = nums[0];
        int slow = nums[0];
        int first = nums[0];
        while (1)
        {
            slow = nums[slow];
            fast = nums[nums[fast]];
            if (fast == slow)
            {
                break;
            }
        }

        while (first != slow)
        {
            first = nums[first];
            slow = nums[slow];
        }
        return slow;
    }
};