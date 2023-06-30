class Solution
{
public:
    int countBeautifulPairs(vector<int> &nums)
    {
        int cnt = 0;
        for (int i = 0; i < nums.size() - 1; i++)
        {
            string k = to_string(nums[i]);
            int nu = k[0] - '0';
            for (int j = i + 1; j < nums.size(); j++)
            {
                string l = to_string(nums[j]);
                int n = l[l.size() - 1] - '0';
                if (__gcd(nu, n) == 1)
                {
                    cnt++;
                }
            }
        }
        return cnt;
    }
};