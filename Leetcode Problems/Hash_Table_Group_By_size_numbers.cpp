class Solution
{
public:
    vector<vector<int>> groupThePeople(vector<int> &groupSizes)
    {
        unordered_map<int, vector<int>> meraMap;
        vector<vector<int>> hold;
        for (int i = 0; i < groupSizes.size(); i++)
        {
            meraMap[groupSizes[i]].push_back(i);
        }

        int r = 0;
        vector<int> k;
        hold.push_back(k);
        for (auto i : meraMap)
        {
            int ch = i.first;
            int cnt = 0;

            vector<int> temp = i.second;
            for (int i = 0; i < temp.size(); i++)
            {

                hold[r].push_back(temp[i]);
                cnt++;
                if (ch == cnt)
                {
                    vector<int> k;
                    hold.push_back(k);
                    r++;
                    cnt = 0;
                }
            }
        }
        hold.pop_back();
        return hold;
    }
};