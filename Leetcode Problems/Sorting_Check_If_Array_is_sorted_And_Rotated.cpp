class Solution
{
public:
    bool issorted(int ind, vector<int> &nums)
    {
        for (int i = ind + 1; i < nums.size(); i++)
        {
            if (nums[i] < nums[i - 1])
            {
                return false;
            }
        }
        return true;
    }

    bool check(vector<int> &nums)
    {
        int x = 0;
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] < nums[i - 1])
            {
                x = i;
                break;
            }
        }
        if (x == 0)
        {
            return true;
        }

        bool first = issorted(x, nums);
        // cout<<x<<first;

        if (!first)
        {
            return false;
        }
        int num = nums[nums.size() - 1];
        if (nums[0] < num)
        {
            return false;
        }
        for (int i = 1; i < x; i++)
        {
            if (nums[i] < nums[i - 1])
            {
                return false;
            }
        }
        return true;
    }
};