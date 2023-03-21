class Solution
{
public:
    long long zeroFilledSubarray(vector<int> &nums)
    {
        long long cnt = 0;
        long long z = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] != 0)
            {
                cnt += ((z * (z + 1)) / 2);
                z = 0;
            }
            else
            {
                z++;
            }
        }
        cnt += ((z * (z + 1)) / 2);
        return cnt;
    }
};