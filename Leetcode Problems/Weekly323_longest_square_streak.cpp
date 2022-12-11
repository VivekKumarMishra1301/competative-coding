class Solution
{
public:
    int longestSquareStreak(vector<int> &nums)
    {

        sort(nums.begin(), nums.end());
        unordered_map<int, int> meraMap;
        for (int i = 0; i < nums.size(); i++)
        {
            meraMap[nums[i]] = i;
            ;
        }
        int max = 1;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] > 46340)
            {
                break;
            }
            int mul = nums[i] * nums[i];
            int count = 1;
            if (nums[i] == 1)
            {
                continue;
            }
            while (meraMap.count(mul) != 0)
            {
                int ind = meraMap[i];
                count++;
                if (mul > 46340)
                {
                    break;
                }
                mul = mul * mul;
                nums[ind] = 1;
            }
            if (count > max)
            {
                max = count;
            }
        }
        if (max == 1)
        {
            return -1;
        }
        return max;
    }
};