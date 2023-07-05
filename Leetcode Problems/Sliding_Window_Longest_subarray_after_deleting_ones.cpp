class Solution
{
public:
    int longestSubarray(vector<int> &nums)
    {
        int s = 0;
        int e = 0;
        int zc = 0;
        int maxi = 0;
        while (e < nums.size())
        {

            if (nums[e] == 0)
            {
                zc++;
            }

            if (zc >= 2)
            {

                maxi = max(e - s - 1, maxi);
                while (zc >= 2)
                {
                    if (nums[s] == 0)
                    {
                        zc--;
                    }
                    s++;
                }
            }
            e++;
        }
        maxi = max(e - s - 1, maxi);
        if (maxi == nums.size())
        {
            return maxi - 1;
        }
        return maxi;
    }
};