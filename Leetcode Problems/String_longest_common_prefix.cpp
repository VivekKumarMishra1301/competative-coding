class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        string hold = "";

        if (strs.size() == 1)
        {
            return strs[0];
        }

        for (int i = 0; i < strs[0].size(); i++)
        {
            for (int j = 1; j < strs.size(); j++)
            {
                if (strs[0][i] != strs[j][i])
                {
                    return hold;
                }
            }
            hold = hol + strs[0][i];
        }
        return hold;
    }
};