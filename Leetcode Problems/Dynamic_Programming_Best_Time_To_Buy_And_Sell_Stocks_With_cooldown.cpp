class Solution
{
public:
    int prof(int ind, int op, vector<int> &arr, vector<vector<int>> &dp)
    {
        if (ind >= arr.size())
        {
            return 0;
        }

        if (dp[ind][op] != -1)
        {
            return dp[ind][op];
        }

        int profit;
        if (op)
        {
            profit = max((-arr[ind] + prof(ind + 1, 0, arr, dp)), prof(ind + 1, 1, arr, dp));
        }
        else
        {
            profit = max((arr[ind] + prof(ind + 2, 1, arr, dp)), prof(ind + 1, 0, arr, dp));
        }
        return dp[ind][op] = profit;
    }

    int maxProfit(vector<int> &prices)
    {
        vector<vector<int>> dp(prices.size() + 1, vector<int>(2, -1));
        return prof(0, 1, prices, dp);
    }
};