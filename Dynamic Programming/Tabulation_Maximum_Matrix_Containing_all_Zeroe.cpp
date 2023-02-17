#include <iostream>
using namespace std;

#include <bits/stdc++.h>
int findMaxSquareWithAllZeros(int **arr, int n, int m)
{
    // Write your code here
    if (n == 0 && m == 0)
    {
        return 0;
    }
    vector<vector<int>> dp(n, vector<int>(m, 0));
    for (int i = 0; i < m; i++)
    {
        if (arr[0][i] == 0)
        {
            dp[0][i] = 1;
        }
        else
        {
            dp[0][i] = 0;
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (arr[i][0] == 0)
        {
            dp[i][0] = 1;
        }
        else
        {
            dp[i][0] = 0;
        }
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < m; j++)
        {
            if (arr[i][j] == 0)
            {
                dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) + 1;
            }
            else
            {
                dp[i][j] = 0;
            }
        }
    }

    int maxi = dp[0][0];
    // return dp[n-1][m-1];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (dp[i][j] > maxi)
            {
                maxi = dp[i][j];
            }
        }
    }
    return maxi;
}

int main()
{
    int **arr, n, m, i, j;
    cin >> n >> m;
    arr = new int *[n];

    for (i = 0; i < n; i++)
    {
        arr[i] = new int[m];
    }

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }

    cout << findMaxSquareWithAllZeros(arr, n, m) << endl;

    delete[] arr;

    return 0;
}