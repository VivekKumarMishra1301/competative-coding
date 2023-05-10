class Solution
{
public:
    int prof(int ind, int op, vector<int> &arr, vector<vector<vector<int>>> &dp, int tr)
    {
        if (tr == 0)
        {
            return 0;
        }
        if (ind == arr.size())
        {
            return 0;
        }

        if (dp[ind][op][tr] != -1)
        {
            return dp[ind][op][tr];
        }

        int profit;
        if (op)
        {
            profit = max((-arr[ind] + prof(ind + 1, 0, arr, dp, tr)), prof(ind + 1, 1, arr, dp, tr));
        }
        else
        {
            profit = max((arr[ind] + prof(ind + 1, 1, arr, dp, tr - 1)), prof(ind + 1, 0, arr, dp, tr));
        }
        return dp[ind][op][tr] = profit;
    }

    int maxProfit(int k, vector<int> &prices)
    {
        vector<vector<vector<int>>> dp(
            prices.size() + 1, vector<vector<int>>(3, vector<int>(k + 1, -1)));
        return prof(0, 1, prices, dp, k);
    }
};