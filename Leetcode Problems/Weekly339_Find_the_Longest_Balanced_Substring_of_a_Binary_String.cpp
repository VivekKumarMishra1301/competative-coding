class Solution
{
public:
    int findTheLongestBalancedSubstring(string s)
    {
        vector<pair<int, int>> ginti;
        int z = 0;
        int o = 0;
        int hold = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] != '0')
            {
                while (i < s.size() && s[i] != '0')
                {
                    i++;
                    o++;
                }
                if (z == o)
                {
                    hold = max(hold, o + z);
                }
                else if (z > o)
                {
                    hold = max(hold, o + o);
                }
                else
                {
                    hold = max(hold, z + z);
                }
                i--;
                z = 0;
                o = 0;
            }
            else
            {
                z++;
            }
        }
        if (z == o)
        {
            hold = max(hold, o + z);
        }
        return hold;
    }
};