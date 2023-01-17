int flips = 0;
int ones = 0;

for (auto c : s)
{
    if (c == '1')
    {
        ones++;
    }
    else if (ones > 0)
    {
        flips++;
        ones--;
    }
}

return flips;

class Solution
{
public:
    int minFlipsMonoIncr(string s)
    {
        // vector<int>dp(s.size()+1);
        int n = s.size();
        int ones = count(s.begin(), s.end(), '1');
        int hold = min(ones, n - ones);
        int now = 0;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '1')
            {
                now++;
            }
            int current = now + ((n - i - 1) - (ones - now));
            hold = min(hold, current);
        }
        return hold;
    }
};