class Solution
{
public:
    long long distinctNames(vector<string> &ideas)
    {
        unordered_set<string> t(ideas.begin(), ideas.end());
        unordered_map<char, unordered_map<char, int>> meraMap;
        for (auto &i : t)
        {
            string s = i;
            char prev = s[0];
            for (char c = 'a'; c <= 'z'; ++c)
            {
                s[0] = c;
                if (t.find(s) == t.end())
                {
                    ++meraMap[c][prev];
                }
            }
        }
        long long hold = 0;
        for (auto &i : t)
        {
            string s = i;
            char prev = s[0];
            for (char c = 'a'; c <= 'z'; ++c)
            {
                s[0] = c;
                if (t.find(s) == t.end())
                {
                    hold += meraMap[prev][c];
                }
            }
        }
        return hold;
    }
};