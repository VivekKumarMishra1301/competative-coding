class Solution
{
public:
    long long maximumOr(vector<int> &nums, int k)
    {

        long long p = pow(2, k);

        vector<long long> pref(nums.size(), 0);

        vector<long long> suff(nums.size(), 0);

        // pref[0]=nums[0];

        for (int i = 1; i < nums.size(); i++)
        {
            pref[i] = pref[i - 1] | nums[i - 1];
        }

        // suff[nums.size()-1]=nums[nums.size()-1];

        for (int i = nums.size() - 2; i >= 0; i--)
        {

            suff[i] = suff[i + 1] | nums[i + 1];
        }

        long long hold = 0;
        for (int i = 0; i < nums.size(); i++)
        {

            hold = max(hold, (pref[i] | nums[i] * p | suff[i]));
        }

        return hold;
    }
};