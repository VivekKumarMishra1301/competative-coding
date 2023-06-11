class Solution
{
public:
    bool isFascinating(int n)
    {
        int f = 2 * n;
        int t = 3 * n;
        string s = "";
        s += to_string(n);
        s += to_string(f);
        s += to_string(t);
        map<int, int> mp;
        for (auto i : s)
        {
            mp[i - '0']++;
        }
        for (auto i : mp)
        {
            if (i.second >= 2 || i.first == 0)
            {
                return false;
            }
        }

        return true;
    }
};