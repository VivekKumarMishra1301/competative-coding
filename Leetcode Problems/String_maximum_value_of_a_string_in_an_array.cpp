class Solution
{
public:
    bool alpha(string s)
    {
        for (auto i : s)
        {
            if (i >= 97 && i <= 122)
            {
                return true;
            }
        }
        return false;
    }

    int maximumValue(vector<string> &strs)
    {
        int res = 0;
        for (int i = 0; i < strs.size(); i++)
        {
            if (alpha(strs[i]))
            {
                if (res < strs[i].size())
                {
                    res = strs[i].size();
                }
            }
            else
            {
                res = max(stoi(strs[i]), res);
            }
        }
        return res;
    }
};