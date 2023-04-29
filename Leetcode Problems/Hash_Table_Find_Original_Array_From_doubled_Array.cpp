class Solution
{
public:
    vector<int> findOriginalArray(vector<int> &changed)
    {
        vector<int> hold;
        if (changed.size() % 2 != 0)
        {
            return hold;
        }
        map<int, int> meraMap;
        for (auto i : changed)
        {
            meraMap[i]++;
        }

        for (auto i : meraMap)
        {
            if (i.first == 0)
            {
                if (meraMap[i.first] % 2 == 0)
                {
                    for (int j = 0; j < meraMap[i.first] / 2; j++)
                    {
                        hold.push_back(0);
                    }
                }
                continue;
            }
            int num = i.first * 2;
            if (meraMap.find(num) != meraMap.end())
            {
                cout << i.first << ":" << i.second << " ";
                int k = meraMap[i.first];
                if (k <= meraMap[num])
                {
                    for (int j = 0; j < meraMap[i.first]; j++)
                    {
                        hold.push_back(i.first);
                        meraMap[num]--;
                    }
                    if (meraMap[num] == 0)
                        meraMap.erase(num);
                }
                else
                {
                    vector<int> k;
                    return k;
                }
            }
            else
            {
                vector<int> k;
                return k;
            }
        }
        return hold;
    }
};