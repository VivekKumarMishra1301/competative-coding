class Solution
{
public:
    int maximizeGreatness(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int k = 0;
        int cnt = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] > nums[k])
            {
                cnt++;
                k++;
            }
        }
        return k;
    }
};