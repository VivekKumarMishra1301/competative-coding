#include <bits/stdc++.h>
int longestBitonicSubsequence(vector<int> &arr, int n)
{
    // Write your code here.
    vector<int> dp1(n, 1);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (arr[i] > arr[j] && dp1[j] + 1 > dp1[i])
            {
                dp1[i] = 1 + dp1[j];
            }
        }
    }
    reverse(arr.begin(), arr.end());
    int maxi = 1;

    vector<int> dp2(n, 1);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (arr[i] > arr[j] && dp2[j] + 1 > dp2[i])
            {
                dp2[i] = 1 + dp2[j];
            }
        }
    }
    reverse(dp2.begin(), dp2.end());
    for (int i = 0; i < n; i++)
    {
        maxi = max(maxi, dp1[i] + dp2[i] - 1);
    }
    return maxi;
}
