class Solution
{
public:
    int countBinarySubstrings(string s)
    {
        int p = 0;
        int c = 1;
        int hold = 0;
        for (int i = 1; i < s.size(); i++)
        {
            if (s[i] == s[i - 1])
            {
                c++;
            }
            else
            {
                hold = hold + min(p, c);
                p = c;
                c = 1;
            }
        }
        return hold + min(p, c);
    }
};