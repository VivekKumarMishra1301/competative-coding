class Solution
{
public:
    vector<int> partitionLabels(string s)
    {
        vector<int> hold;

        map<char, int> meraMap;
        for (int i = 0; i < s.size(); i++)
        {
            meraMap[s[i]] = i;
        }

        for (int i = 0; i < s.size(); i++)
        {
            auto it = meraMap.find(s[i]);
            int j = it->second;
            map<char, int> mp;
            int k = 0;
            for (; k <= j; k++)
            {
                mp[s[k]]++;
            }
            int term = j;
            for (k = j + 1; k < s.size(); k++)
            {

                if (mp.find(s[k]) != mp.end())
                {

                    for (int l = k; l >= j + 1; l--)
                    {
                        mp[s[l]]++;
                    }

                    term = k;
                }
            }
            hold.push_back(term - i + 1);
            i = term;
        }

        return hold;
    }
};