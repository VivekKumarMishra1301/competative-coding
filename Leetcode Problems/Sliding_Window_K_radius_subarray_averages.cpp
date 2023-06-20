class Solution
{
public:
    vector<int> getAverages(vector<int> &nums, int k)
    {
        vector<int> avg(nums.size(), -1);
        int ind = 0;
        long sum = 0;
        int s = 0;
        if (nums.size() < 2 * k + 1)
        {
            return avg;
        }
        while (ind < nums.size() && ind <= 2 * k)
        {
            sum += nums[ind];
            ind++;
        }

        while (ind < nums.size())
        {
            avg[ind - k - 1] = sum / (long)(2 * (long)k + 1);
            sum -= nums[s++];
            sum += nums[ind];
            ind++;
        }
        avg[ind - k - 1] = sum / (long)(2 * (long)k + 1);
        return avg;
    }
};