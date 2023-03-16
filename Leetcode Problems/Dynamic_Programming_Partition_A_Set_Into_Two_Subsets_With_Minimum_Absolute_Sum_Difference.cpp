#include <bits/stdc++.h>
int minSubsetSumDifference(vector<int> &arr, int n)
{
    // Write your code here.

    vector<vector<bool>> dp(arr.size() + 1, vector<bool>(20001, false));
    int totalsum = 0;
    for (auto i : arr)
    {
        totalsum += i;
    }

    for (int i = 0; i <= arr.size(); i++)
    {
        dp[i][0] = true;
    }
    dp[0][arr[0]] = true;
    for (int i = 1; i < arr.size(); i++)
    {
        for (int j = 1; j <= totalsum; j++)
        {
            bool notpick = dp[i - 1][j];
            bool pick = false;
            if (j >= arr[i])
            {
                pick = dp[i - 1][j - arr[i]];
            }
            dp[i][j] = pick || notpick;
        }
    }

    int mini = 1e9;
    for (int i = 0; i <= totalsum / 2; i++)
    {
        if (dp[arr.size() - 1][i])
        {
            mini = min(mini, abs(i - (totalsum - i)));
        }
    }
    return mini;
}
