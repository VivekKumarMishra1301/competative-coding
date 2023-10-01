class Solution
{
public:
    int minSizeSubarray(vector<int> &nums, int target)
    {
        long su = 0;
        for (auto i : nums)
        {
            su += (long)i;
        }
        long k = target % su;
        if (k == 0)
        {
            return (target / su) * nums.size();
        }
        vector<int> arr = nums;
        for (int i = 0; i < nums.size(); i++)
        {
            arr.push_back(nums[i]);
        }
        int st = 0;
        int hold = INT_MAX;
        int curr = 0;
        for (int i = 0; i < arr.size(); i++)
        {
            curr += arr[i];
            while (curr > k)
            {
                curr -= arr[st++];
            }
            if (curr == k)
            {
                hold = min(hold, i - st + 1);
            }
        }
        if (hold == INT_MAX)
        {
            return -1;
        }
        return (target / su) * nums.size() + hold;
    }
};