class Solution
{
public:
    vector<int> findAnagrams(string s, string p)
    {
        vector<int> smap(26, 0);
        vector<int> tmap(26, 0);
        int len1 = p.size();
        int len2 = s.size();
        vector<int> hold;
        if (len2 < len1)
        {
            return hold;
        }

        int l = 0;
        int r = 0;
        while (r < len1)
        {
            smap[p[r] - 'a'] += 1;
            tmap[s[r] - 'a'] += 1;
            r++;
        }

        r--;
        while (r < len2)
        {
            if (smap == tmap)
            {
                hold.push_back(l);
            }
            r++;
            if (r != len2)
            {
                tmap[s[r] - 'a'] += 1;
            }
            tmap[s[l] - 'a'] -= 1;
            l++;
        }
        return hold;
    }
};