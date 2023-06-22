class Solution
{
public:
    vector<string> wordSubsets(vector<string> &words1, vector<string> &words2)
    {
        vector<string> hold;
        map<char, int> mp;
        for (auto i : words2)
        {
            map<char, int> mp1;
            for (auto j : i)
            {
                // cout<<j;
                mp1[j]++;
            }
            for (auto m : mp1)
            {
                mp[m.first] = max(mp[m.first], m.second);
            }
        }

        for (auto i : words1)
        {
            map<char, int> mp2;
            cout << i;
            for (auto j : i)
            {
                // cout<<j;
                mp2[j]++;
            }
            bool flag = true;
            for (auto k : mp)
            {
                // cout<<k.first;
                if (mp2.find(k.first) == mp2.end() || k.second > mp2[k.first])
                {
                    flag = false;
                    break;
                }
                else
                {
                    continue;
                }
            }
            if (flag)
            {
                hold.push_back(i);
            }
        }

        return hold;
    }
};