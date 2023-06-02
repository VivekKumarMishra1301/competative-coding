class Solution
{
public:
    int find(int i, int j, vector<int> &cuts, vector<vector<int>> &dp)
    {
        if (i > j)
        {
            return 0;
        }

        if (dp[i][j] != -1)
        {
            return dp[i][j];
        }
        int mini = INT_MAX;
        for (int ind = i; ind <= j; ind++)
        {
            mini = min(mini, cuts[j + 1] - cuts[i - 1] + find(ind + 1, j, cuts, dp) + find(i, ind - 1, cuts, dp));
        }
        return dp[i][j] = mini;
    }

    int minCost(int n, vector<int> &cuts)
    {
        int cs = cuts.size();
        cuts.insert(cuts.begin(), 0);
        cuts.push_back(n);
        sort(cuts.begin(), cuts.end());
        vector<vector<int>> dp(cs + 1, vector<int>(cs + 1, -1));
        return find(1, cs, cuts, dp);
    }
};C