class Solution
{
public:
    void nextPermutation(vector<int> &nums)
    {
        int ind = -1;
        for (int i = nums.size() - 2; i >= 0; i--)
        {
            if (nums[i] < nums[i + 1])
            {
                ind = i;
                break;
            }
        }

        // base case
        if (ind == -1)
        {
            reverse(nums.begin(), nums.end());
            return;
        }
        int newind = ind;
        for (int i = nums.size() - 1; i > ind; i--)
        {
            if (nums[i] > nums[ind])
            {
                newind = i;
                break;
            }
        }
        swap(nums[ind], nums[newind]);

        // you can also use the reverse function because it is in descending order

        sort(nums.begin() + ind + 1, nums.end());
        return;
    }
};