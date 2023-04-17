class Solution
{
public:
    int maxDivScore(vector<int> &nums, vector<int> &divisors)
    {
        int div = divisors[0];
        int cnt = 0;
        for (int i = 0; i < divisors.size(); i++)
        {
            int ncn = 0;
            for (int j = 0; j < nums.size(); j++)
            {
                if (nums[j] % divisors[i] == 0)
                {
                    ncn++;
                }
            }
            if (ncn > cnt)
            {
                cnt = ncn;
                div = divisors[i];
            }
            else if (ncn == cnt)
            {
                div = min(div, divisors[i]);
            }
        }
        return div;
    }
};