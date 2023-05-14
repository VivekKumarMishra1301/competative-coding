class Solution
{
public:
    vector<int> circularGameLosers(int n, int k)
    {
        map<int, int> meraMap;
        int i = 0;
        int t = 1;
        while (1)
        {
            meraMap[i]++;
            if (meraMap[i] >= 2)
            {
                break;
            }
            i = (i + t * k) % n;
            t++;
        }
        vector<int> lo;
        for (int it = 1; it < n; it++)
        {
            if (meraMap.find(it) == meraMap.end())
            {
                lo.push_back(it + 1);
            }
        }
        return lo;
    }
};