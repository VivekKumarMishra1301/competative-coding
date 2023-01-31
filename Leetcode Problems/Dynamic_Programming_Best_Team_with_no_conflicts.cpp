class Solution
{
public:
    int findMax(vector<pair<int, int>> &hold)
    {
        vector<int> dp(hold.size());
        int res = 0;
        for (int i = 0; i < hold.size(); i++)
        {
            dp[i] = hold[i].second;
            res = max(dp[i], res);
        }

        for (int i = 0; i < hold.size(); i++)
        {
            int j = i - 1;
            while (j >= 0)
            {
                if (hold[i].second >= hold[j].second)
                {
                    dp[i] = max(dp[i], hold[i].second + dp[j]);
                }
                j--;
            }
            res = max(res, dp[i]);
        }

        return res;
    }

    int bestTeamScore(vector<int> &scores, vector<int> &ages)
    {

        vector<pair<int, int>> hold;
        for (int i = 0; i < ages.size(); i++)
        {
            hold.push_back({ages[i], scores[i]});
        }
        sort(hold.begin(), hold.end());

        return findMax(hold);
    }
};