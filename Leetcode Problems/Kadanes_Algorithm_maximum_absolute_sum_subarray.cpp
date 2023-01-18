class Solution
{
public:
    int maxAbsoluteSum(vector<int> &nums)
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

        int sum = 0;
        int mini = INT_MAX;
        for (auto i : nums)
        {
            sum += i;
            mini = min(sum, mini);
            if (sum > 0)
            {
                sum = 0;
            }
        }
        return max(maxi, abs(mini));
    }
};