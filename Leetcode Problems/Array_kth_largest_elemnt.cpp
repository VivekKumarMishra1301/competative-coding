class Solution
{
public:
    int findKthLargest(vector<int> &nums, int k)
    {
        sort(nums.begin(), nums.end());
        int j = 1;
        // if(k>=nums.size()){
        //     return nums[0];
        // }
        for (int i = nums.size() - 2; i >= 0; i--)
        {
            j++;
            if (j == k)
            {
                return nums[i];
            }
        }
        if (k == 1)
        {
            return nums[nums.size() - 1];
        }
        return nums[0];
    }
};