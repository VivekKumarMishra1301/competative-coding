class Solution
{
public:
    int findJudge(int n, vector<vector<int>> &trust)
    {
        if (trust.size() == 0 && n == 1)
        {
            return 1;
        }

        unordered_map<int, int> meraMap;
        for (int i = 0; i < trust.size(); i++)
        {
            meraMap[trust[i][0]]++;
        }

        unordered_map<int, int> ginti;
        for (int i = 0; i < trust.size(); i++)
        {
            ginti[trust[i][1]]++;
        }

        for (int i = 0; i < trust.size(); i++)
        {
            if (meraMap.count(trust[i][1]) == 0 && (ginti[trust[i][1]]) == (n - 1))
            {
                return trust[i][1];
            }
        }
        return -1;
    }
};