class Solution
{
public:
    bool valid(long mid, vector<int> &nums)
    {
        long sum = 0;
        for (long i = 0; i < nums.size(); i++)
        {
            sum += long(nums[i]);
            if (sum > mid * (i + 1))
            {
                return false;
            }
        }
        return true;
    }

    int minimizeArrayValue(vector<int> &nums)
    {
        int hold = 0;
        int st = 0;
        int en = *max_element(nums.begin(), nums.end());
        while (st <= en)
        {
            int mid = (st + en) / 2;
            if (valid(mid, nums))
            {
                hold = mid;
                en = mid - 1;
            }
            else
            {
                st = mid + 1;
            }
        }
        return hold;
    }
};