class Solution
{
public:
    int knap(int ind, vector<vector<int>> &events, int k, vector<vector<int>> &dp)
    {
        if (k == 0 || ind >= events.size())
        {
            return 0;
        }
        if (dp[ind][k] != -1)
        {
            return dp[ind][k];
        }
        int nind;
        for (int i = ind + 1; i < events.size(); i++)
        {
            if (events[i][0] > events[ind][1])
            {
                nind = i;
                break;
            }
        }

        return dp[ind][k] = max((events[ind][2] + knap(nind, events, k - 1, dp)), knap(ind + 1, events, k, dp));
    }

    int maxValue(vector<vector<int>> &events, int k)
    {
        sort(events.begin(), events.end());
        vector<vector<int>> dp(events.size() + 1, vector<int>(k + 1, -1));
        return knap(0, events, k, dp);
    }
};