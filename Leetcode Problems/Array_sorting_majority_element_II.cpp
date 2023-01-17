class Solution
{
public:
    vector<int> majorityElement(vector<int> &nums)
    {
        int size = floor(nums.size() / 3);
        int count = 1;
        vector<int> hold;
        sort(nums.begin(), nums.end());
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] != nums[i - 1])
            {
                if (count > size)
                    hold.push_back(nums[i - 1]);
                count = 1;
            }
            else
            {
                count++;
            }
        }
        if (count > size)
            hold.push_back(nums[nums.size() - 1]);
        return hold;
    }
};