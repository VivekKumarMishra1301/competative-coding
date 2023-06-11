class Solution
{
public:
    int longestSemiRepetitiveSubstring(string s)
    {
        int maxi = 1;
        int rc = 1;
        bool flag = false;
        int preve = -1;
        for (int i = 1; i < s.size(); i++)
        {
            if (s[i] != s[i - 1])
            {
                rc++;
            }
            else if (s[i] == s[i - 1] && !flag)
            {
                preve = i;
                flag = true;
                rc++;
            }
            else
            {
                maxi = max(rc, maxi);
                rc = i - preve + 1;
                preve = i;
            }
        }
        maxi = max(rc, maxi);
        return maxi;
    }
};