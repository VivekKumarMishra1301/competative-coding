class Solution
{
public:
    vector<int> findingUsersActiveMinutes(vector<vector<int>> &logs, int k)
    {
        map<int, set<int>> meraMap;
        for (int i = 0; i < logs.size(); i++)
        {
            meraMap[logs[i][0]].insert(logs[i][1]);
        }
        vector<int> hold;
        map<int, int> mp;
        for (auto i : meraMap)
        {
            mp[i.second.size()]++;
        }

        for (int i = 0; i < k; i++)
        {
            if (mp.count(i + 1) != 0)
            {
                hold.push_back(mp[i + 1]);
            }
            else
            {
                hold.push_back(0);
            }
        }
        return hold;
    }
};