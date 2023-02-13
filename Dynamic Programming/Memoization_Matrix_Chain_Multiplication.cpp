#include <iostream>
using namespace std;

#include <bits/stdc++.h>
int multi(int i, int j, vector<vector<int>> &dp, int *arr)
{
    if (i == j)
    {
        return 0;
    }
    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }
    int mini = 1e9;
    for (int k = i; k < j; k++)
    {
        int steps = arr[i - 1] * arr[k] * arr[j] + multi(i, k, dp, arr) + multi(k + 1, j, dp, arr);
        mini = min(mini, steps);
    }
    return dp[i][j] = mini;
}

int matrixChainMultiplication(int *arr, int n)
{
    // Write your code here
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
    return multi(1, n, dp, arr);
}

int main()
{
    int n;
    cin >> n;
    int *arr = new int[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << matrixChainMultiplication(arr, n);

    delete[] arr;
}