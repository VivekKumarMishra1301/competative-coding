class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int mini = prices[0];
        int prof = 0;
        for (int i = 0; i < prices.size(); i++)
        {
            int cost = prices[i] - mini;
            prof = max(prof, cost);
            mini = min(prices[i], mini);
        }
        return prof;
    }
};