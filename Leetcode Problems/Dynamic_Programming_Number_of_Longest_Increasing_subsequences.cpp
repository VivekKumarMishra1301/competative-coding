class Solution
{
public:
    int findNumberOfLIS(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> dp(n, 1);
        vector<int> counter(n, 1);
        int hold = 0;
        // return find(arr,n-1,memo);
        dp[0] = 1;
        counter[0] = 1;
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (nums[j] < nums[i])
                {
                    int ans = 1 + dp[j];
                    if (dp[i] < ans)
                    {
                        dp[i] = ans;
                        counter[i] = counter[j];
                    }
                    else if (dp[i] == ans)
                    {
                        counter[i] += counter[j];
                    }
                }
            }
        }
        // sort(dp.begin(),dp.end());
        int best = 0;
        for (int i = 0; i < n; i++)
        {
            if (best < dp[i])
            {
                best = dp[i];
            }
            cout << dp[i] << ":" << counter[i] << " ";
        }
S
        for (int i = 0; i < n; i++)
        {
            if (dp[i] == best)
            {
                hold += counter[i];
            }
        }

        return hold;
    }
};