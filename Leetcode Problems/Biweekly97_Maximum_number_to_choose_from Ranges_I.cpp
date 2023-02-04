class Solution
{
public:
    int maxCount(vector<int> &banned, int n, int maxSum)
    {
        unordered_map<int, int> meraMap;
        for (auto i : banned)
        {
            meraMap[i]++;
        }
        int sum = 0;
        int num = 0;
        for (int i = 1; i <= n; i++)
        {
            if (meraMap.count(i) == 0 && (sum + i) <= maxSum)
            {
                sum += i;
                num++;
            }
        }
        return num;
    }
};