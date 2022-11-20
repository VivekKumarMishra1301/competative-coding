class Solution
{
public:
    int findPairs(vector<int> &nums, int k)
    {
        sort(nums.begin(), nums.end());

        int count = 0;
        unordered_map<int, int> hold;
        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = i + 1; j < nums.size(); j++)
            {
                if ((nums[j] - nums[i]) == k)
                {
                    if (hold.count(nums[i]) == 0)
                    {
                        count++;
                        hold[nums[i]] = nums[j];
                    }
                    else if (hold[nums[i]] != nums[j])
                    {
                        count++;
                    }
                }
            }
        }
        return count;
    }
};