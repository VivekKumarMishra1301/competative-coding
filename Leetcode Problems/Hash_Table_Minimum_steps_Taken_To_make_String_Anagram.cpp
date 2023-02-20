class Solution
{
public:
    int minSteps(string s, string t)
    {
        unordered_map<char, int> meraMap;
        for (auto i : s)
        {
            meraMap[i]++;
        }

        unordered_map<char, int> teraMap;

        for (auto i : t)
        {
            teraMap[i]++;
        }
        int hold = 0;
        for (auto i : teraMap)
        {
            if (meraMap.count(i.first) == 0)
            {
                hold += i.second;
            }
            else
            {
                if (i.second > meraMap[i.first])
                {
                    hold += i.second - meraMap[i.first];
                }
            }
        }
        return hold;
    }
};