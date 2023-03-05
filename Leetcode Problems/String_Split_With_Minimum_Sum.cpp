class Solution
{
public:
    int splitNum(int num)
    {
        string nums = to_string(num);
        sort(nums.begin(), nums.end());
        string num1 = "";
        string num2 = "";
        for (int i = 0; i < nums.size(); i++)
        {
            if (i % 2 == 0)
            {
                num1 += nums[i];
            }
            else
            {
                num2 += nums[i];
            }
        }
        int hold = stoi(num1) + stoi(num2);
        return hold;
    }
};