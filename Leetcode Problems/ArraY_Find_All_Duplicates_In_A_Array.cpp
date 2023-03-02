class Solution
{
public:
    vector<int> findDuplicates(vector<int> &nums)
    {
        vector<int> hold;
        for (int i = 0; i < nums.size(); i++)
        {
            int n = abs(nums[i]);
            int num = abs(nums[i]);

            if (nums[num - 1] < 0)
                hold.push_back(num);
            else
                nums[num - 1] *= -1;
        }
        return hold;
    }
};