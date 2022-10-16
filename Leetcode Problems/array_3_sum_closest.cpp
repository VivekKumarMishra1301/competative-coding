class Solution
{
public:
    int threeSumClosest(vector<int> &nums, int target)
    {

        sort(nums.begin(), nums.end());
        int dif = INT_MAX;
        int ans = 0;
        for (int i = 0; i < nums.size() - 2; i++)
        {
            int m = i + 1;
            int n = nums.size() - 1;
            while (m < n)
            {
                if (nums[i] + nums[m] + nums[n] == target)
                {
                    return target;
                }
                else if (abs(nums[i] + nums[m] + nums[n] - target) < dif)
                {
                    dif = abs(nums[i] + nums[m] + nums[n] - target);
                    ans = nums[i] + nums[m] + nums[n];
                }
                else if (nums[i] + nums[m] + nums[n] > target)
                {
                    end--;
                }
                else
                {
                    start++;
                }
            }
        }
    }
};