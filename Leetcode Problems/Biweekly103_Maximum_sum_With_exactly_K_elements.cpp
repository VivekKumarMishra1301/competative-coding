class Solution
{
public:
    int maximizeSum(vector<int> &nums, int k)
    {
        priority_queue<int> d;
        for (auto i : nums)
        {
            d.push(i);
        }
        int hold = 0;
        for (int i = 0; i < k; i++)
        {
            int tp = d.top();
            d.pop();
            hold += tp;
            d.push(tp + 1);
        }
        return hold;
    }
};