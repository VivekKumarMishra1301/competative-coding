class Solution
{
public:
    int getMaxLen(vector<int> &nums)
    {
        int l = 0;
        int temp = 0;
        int prod = 1;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            if (nums[i] == 0)
            {
                temp = 0;
                prod = 1;
                continue;
            }

            if (nums[i] > 0)
            {
                prod *= 1;
            }
            else
            {
                prod *= -1;
            }
            temp++;
            if (prod > 0)
            {
                l = max(l, temp);
            }
        }

        temp = 0;
        prod = 1;
        for (int i = n - 1; i >= 0; i--)
        {
            if (nums[i] == 0)
            {
                temp = 0;
                prod = 1;
                continue;
            }
            if (nums[i] > 0)
            {
                prod *= 1;
            }
            else
            {
                prod *= -1;
            }
            temp++;
            if (prod > 0)
                l = max(l, temp);
        }

        return l;
    }
};