class Solution
{
public:
    int minStoneSum(vector<int> &piles, int k)
    {
        priority_queue<int> pendingNums;
        for (int i = 0; i < piles.size(); i++)
        {
            pendingNums.push(piles[i]);
        }
        while (k--)
        {
            int num = pendingNums.top();
            pendingNums.pop();
            num = num - floor(num / 2);
            pendingNums.push(num);
        }

        int sum = 0;
        while (!pendingNums.empty())
        {
            sum += pendingNums.top();
            pendingNums.pop();
        }
        return sum;
    }
};