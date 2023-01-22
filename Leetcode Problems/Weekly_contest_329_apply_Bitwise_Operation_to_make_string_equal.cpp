class Solution
{
public:
    bool makeStringsEqual(string s, string target)
    {
        int one = 0;
        int zero = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '1')
            {
                one++;
            }
            else
            {
                zero++;
            }
        }
        int zero2 = 0;
        int one2 = 0;
        for (int i = 0; i < target.size(); i++)
        {
            if (target[i] == '0')
            {
                zero2++;
            }
            else
            {
                one2++;
            }
        }
        if (zero != s.size() && zero2 == s.size())
        {
            return false;
        }
        else if (zero == s.size() && zero2 != s.size())
        {
            return false;
        }
        else
        {
            return true;
        }
    }
};