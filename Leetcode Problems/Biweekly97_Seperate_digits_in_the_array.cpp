class Solution
{
public:
    vector<int> separateDigits(vector<int> &nums)
    {
        vector<int> hold;
        for (int i = 0; i < nums.size(); i++)
        {
            vector<int> hold1;
            while (nums[i] > 0)
            {
                hold1.push_back(nums[i] % 10);
                nums[i] /= 10;
            }
            reverse(hold1.begin(), hold1.end());
            for (int j = 0; j < hold1.size(); j++)
            {
                hold.push_back(hold1[j]);
            }
        }
        return hold;
    }
};