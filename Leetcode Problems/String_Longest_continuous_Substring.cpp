class Solution
{
public:
    int longestContinuousSubstring(string s)
    {
        int hold = 0;
        int cnt = 1;
        for (int i = 1; i < s.size(); i++)
        {
            if (s[i] != s[i - 1] + 1)
            {
                hold = max(hold, cnt);
                cnt = 1;
            }
            else
            {
                cnt++;
            }
        }
        hold = max(hold, cnt);
        return hold;
    }
};