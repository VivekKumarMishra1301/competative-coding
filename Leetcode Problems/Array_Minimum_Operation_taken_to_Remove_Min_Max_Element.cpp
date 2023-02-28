class Solution
{
public:
    int minimumDeletions(vector<int> &nums)
    {
        int mini = nums[0];
        int maxi = nums[0];
        int m = 0;
        int n = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] > maxi)
            {
                maxi = nums[i];
                m = i;
            }
            if (nums[i] < mini)
            {
                mini = nums[i];
                n = i;
            }
        }
        int size = nums.size();
        if (m < n)
        {
            int del1 = (m + 1) + (size - n);
            int del2 = n + 1;
            int del3 = size - m;
            return min(del1, min(del2, del3));
        }
        else if (n < m)
        {
            int del1 = (n + 1) + (size - m);
            int del2 = m + 1;
            int del3 = size - n;
            return min(del1, min(del2, del3));
        }
        else
        {
            return min(size - m, m + 1);
        }
    }
};