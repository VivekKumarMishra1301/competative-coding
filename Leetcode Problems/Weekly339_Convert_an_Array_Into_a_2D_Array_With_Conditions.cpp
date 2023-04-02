class Solution
{
public:
    vector<vector<int>> findMatrix(vector<int> &nums)
    {
        vector<vector<int>> hold;
        map<int, vector<int>> meraMap;
        map<int, int> rowTrack;
        for (int i = 0; i < nums.size(); i++)
        {
            meraMap[nums[i]].push_back(i);
        }

        for (auto i : meraMap)
        {
            vector<int> l = i.second;
            for (int j = 0; j < l.size(); j++)
            {
                if (rowTrack.find(j) == rowTrack.end())
                {
                    rowTrack[j]++;
                    vector<int> m;
                    hold.push_back(m);
                }
                hold[j].push_back(i.first);
            }
        }
        return hold;
    }
};