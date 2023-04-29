class Solution
{
public:
    long long countOperationsToEmptyArray(vector<int> &nums)
    {

        long long hold = nums.size();

        map<int, int> meraMap;
        for (int i = 0; i < nums.size(); i++)
        {
            meraMap[nums[i]] = i;
        }

        sort(nums.begin(), nums.end());
        for (int i = 1; i < nums.size(); i++)
        {
            if (meraMap[nums[i]] < meraMap[nums[i - 1]])
            {
                hold += (nums.size() - i);
            }
        }
        return hold;
    }
};