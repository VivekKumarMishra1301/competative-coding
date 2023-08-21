class Solution
{
public:
    bool repeatedSubstringPattern(string s)
    {
        string str = s;
        for (int i = 0; i < s.size() - 1; i++)
        {
            s.push_back(s[0]);
            s.erase(0, 1);
            if (str == s)
            {
                return true;
            }
        }
        return false;
    }
};