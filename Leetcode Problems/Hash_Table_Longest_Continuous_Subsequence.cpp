class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        if (nums.size() == 0)
        {
            return 0;
        }
        map<int, int> meraMap;
        for (int i = 0; i < nums.size(); i++)
        {
            meraMap[nums[i]]++;
        }

        int hold = 1;
        bool flag = true;
        int cnt = 1;
        for (auto i : meraMap)
        {
            if (flag)
            {
                flag = false;
                continue;
            }
            int k = i.first - 1;
            if (meraMap.find(k) != meraMap.end())
            {
                cnt++;
            }
            else
            {
                hold = max(hold, cnt);
                cnt = 1;
            }
        }
        hold = max(hold, cnt);
        return hold;
    }
};