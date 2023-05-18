class Solution
{
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>> &edges)
    {
        map<int, int> meraMap;
        for (auto i : edges)
        {
            meraMap[i[1]]++;
        }

        vector<int> hold;
        for (int i = 0; i < n; i++)
        {
            if (meraMap.find(i) == meraMap.end())
            {
                hold.push_back(i);
            }
        }
        return hold;
    }
};
