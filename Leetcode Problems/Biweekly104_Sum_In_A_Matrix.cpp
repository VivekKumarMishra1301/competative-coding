class Solution
{
public:
    int matrixSum(vector<vector<int>> &nums)
    {
        int s = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            sort(nums[i].begin(), nums[i].end());
        }
        for (int i = 0; i < nums[0].size(); i++)
        {
            int maxi = nums[0][i];
            for (int j = 0; j < nums.size(); j++)
            {
                if (nums[j][i] > maxi)
                {
                    maxi = nums[j][i];
                }
            }
            s += maxi;
        }
        return s;
    }
};