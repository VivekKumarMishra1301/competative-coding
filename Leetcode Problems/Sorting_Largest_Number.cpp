class Solution
{
public:
    string largestNumber(vector<int> &nums)
    {
        string hold = "";
        for (int i = 0; i < nums.size() - 1; i++)
        {
            for (int j = i + 1; j < nums.size(); j++)
            {
                string s1 = to_string(nums[i]);
                string s2 = to_string(nums[j]);
                string con1 = s1 + s2;
                string con2 = s2 + s1;
                // long long num1=stoi(con1);
                // long long num2=stoi(con2);
                if (con1 < con2)
                {
                    swap(nums[i], nums[j]);
                }
            }
        }

        bool flag = true;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] != 0)
            {
                flag = false;
            }
            string num = to_string(nums[i]);
            hold += num;
        }
        if (flag)
        {
            return "0";
        }
        return hold;
    }
};