class Solution
{
public:
    bool canJump(vector<int> &nums)
    {
        int maxmove = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (maxmove < i)
                , ;
            {
                return false;
            }
            maxmove = max(maxmove, i + nums[i]);
        }
        return true;
    }
};