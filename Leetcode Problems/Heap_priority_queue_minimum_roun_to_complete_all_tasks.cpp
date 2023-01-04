class Solution
{
public:
    int minimumRounds(vector<int> &tasks)
    {
        unordered_map<int, int> meraMap;
        for (int i = 0; i < tasks.size(); i++)
        {
            meraMap[tasks[i]]++;
        }
        for (auto i : meraMap)
        {
            if (i.second == 1)
            {
                return -1;
            }
            cout << i.first << "->" << i.second << " ";
        }

        int count = 0;
        for (auto i : meraMap)
        {
            while (i.second >= 2)
            {
                if (i.second == 2 || i.second == 3)
                {
                    count += 1;
                    i.second = 0;
                }
                else if (i.second == 4 || i.second == 5)
                {
                    count += 2;
                    i.second = 0;
                }
                else
                {
                    count = count + (i.second / 3);
                    i.second = i.second % 3;
                }
            }

            if (i.second != 0)
            {
                count += 1;
            }
        }
        return count;
    }
};