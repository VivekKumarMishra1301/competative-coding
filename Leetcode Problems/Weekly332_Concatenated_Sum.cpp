class Solution
{
public:
    long long findTheArrayConcVal(vector<int> &nums)
    {
        long long concat = 0;
        int st = 0;
        int en = nums.size() - 1;
        while (st < en)
        {
            string num1 = to_string(nums[st]);
            string num2 = to_string(nums[en]);
            string num = num1 + num2;
            int hold = stoi(num);
            concat += hold;
            st++;
            en--;
        }
        if (nums.size() % 2 != 0)
        {
            // int numb=stoi(nums[st]);
            concat += nums[st];
        }
        return concat;
    }
};