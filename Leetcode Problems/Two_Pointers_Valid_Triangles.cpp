class Solution
{
public:
    int triangleNumber(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int e = nums.size() - 1;
        int val = 0;
        while (e >= 2)
        {
            int s = 0;
            int t = e - 1;
            while (s < t)
            {
                if (nums[s] + nums[t] > nums[e])
                {
                    val += t - s;
                    t--;
                }
                else
                {
                    s++;
                }
            }

            e--;
        }
        return val;
    }
};