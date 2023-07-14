class Solution
{
public:
    int longestSubsequence(vector<int> &arr, int d)
    {
        // vector<int>dp(arr.size(),1);
        map<int, int> dp;

        int hold = 1;
        int maxind = 0;
        for (int i = 0; i < arr.size(); i++)
        {

            if (dp.find(arr[i] - d) != dp.end())
            {
                dp[arr[i]] = 1 + dp[arr[i] - d];
            }
            else
            {
                dp[arr[i]] = 1;
            }
            hold = max(hold, dp[arr[i]]);
        }
        return hold;
    }
};