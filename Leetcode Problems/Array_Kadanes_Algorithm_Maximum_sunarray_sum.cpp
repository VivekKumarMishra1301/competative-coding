class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int total = 0;
        int maxi = INT_MIN;
        for (auto i : nums)
        {
            total += i;
            maxi = max(total, maxi);

            if (total < 0)
            {
                total = 0;
            }
        }
        return maxi;
    }
};