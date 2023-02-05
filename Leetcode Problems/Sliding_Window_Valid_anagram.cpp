class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        if (s.size() != t.size())
        {
            return false;
        }
        unordered_map<char, int> smap;
        unordered_map<char, int> tmap;

        for (auto i : s)
        {
            smap[i]++;
        }

        for (auto i : t)
        {
            tmap[i]++;
        }

        for (auto i : s)
        {
            if (smap[i] != tmap[i])
            {
                return false;
            }
        }
        for (auto i : t)
        {
            if (smap[i] != tmap[i])
            {
                return false;
            }
        }
        return true;
    }
};