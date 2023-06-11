class Solution
{
public:
    int sumDistance(vector<int> &nums, string s, int d)
    {
        for (int i = 0; i < nums.size(); i++)
        {
            if (s[i] == 'L')
            {
                nums[i] -= d;
            }
            else
            {
                nums[i] += d;
            }
        }
        long mod = 1000000007;

        sort(nums.begin(), nums.end());
        long pref = 0;
        long hold = 0;
        for (int i = 1; i < nums.size(); i++)
        {
            long cl = (pref + ((long)((long)nums[i] - (long)nums[i - 1]) * (long)i) % mod) % mod;
            hold = (long)(hold + cl) % mod;
            pref = cl;
        }
        return hold % mod;
    }
};