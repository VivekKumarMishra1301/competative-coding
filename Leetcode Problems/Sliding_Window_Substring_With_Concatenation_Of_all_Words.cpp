class Solution
{
public:
    vector<int> findSubstring(string s, vector<string> &words)
    {
        vector<int> hold;
        int n = words.size();
        int m = words[0].size();
        int size = n * m;
        if (size > s.size())
        {
            return hold;
        }

        for (int i = 0; i <= s.size() - size; i++)
        {
            unordered_map<string, int> meraMap;
            for (auto i : words)
            {
                meraMap[i]++;
            }
            int k;
            for (k = 0; k < n; k++)
            {
                string temp = s.substr(i + k * m, m);
                if (meraMap.count(temp) == 0)
                {
                    break;
                }
                else
                {
                    if (meraMap[temp] != 0)
                    {
                        meraMap[temp]--;
                    }
                    else
                    {
                        break;
                    }
                }
            }
            if (k == n)
            {
                hold.push_back(i);
            }
        }
        return hold;
    }
};