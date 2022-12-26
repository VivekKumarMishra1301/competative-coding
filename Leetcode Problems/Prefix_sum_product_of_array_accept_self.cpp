class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        vector<int> hold;
        int mul = 1;
        int count = 0;
        for (int i = 0; i < nums.size(); i++)
        {

            if (nums[i] != 0)
            {

                mul *= nums[i];
            }
            else
            {
                count++;
            }
        }
        if (count >= 2)
        {
            mul = 0;
        }
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == 0)
            {
                hold.push_back(mul);
            }
            else if (count == 1)
            {
                hold.push_back(0);
            }
            else
            {
                hold.push_back(mul / nums[i]);
            }
        }

        return hold;
    }
};