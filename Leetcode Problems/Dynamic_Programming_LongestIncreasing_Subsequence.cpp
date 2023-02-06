int n = nums.size();
vector<int> dp(n, 0);
// return find(arr,n-1,memo);
dp[0] = 1;
for (int i = 1; i < n; i++)
{
    dp[i] = 1;
    for (int j = i - 1; j >= 0; j--)
    {
        if (nums[i] <= nums[j])
        {
            continue;
        }
        int ans = 1 + dp[j];
        if (dp[i] < ans)
        {
            dp[i] = ans;
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
}
return best;