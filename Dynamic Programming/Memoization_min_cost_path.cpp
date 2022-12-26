#include <bits/stdc++.h>
using namespace std;
int findMinPath(int **input, int x, int y, int m, int n, vector<vector<int>> &dp)
{
    if (x >= m || y >= n)
    {
        return INT_MAX;
    }
    if (dp[x][y] != -1)
    {
        return dp[x][y];
    }
    int a = findMinPath(input, x + 1, y, m, n, dp);

    int b = findMinPath(input, x, y + 1, m, n, dp);

    int c = findMinPath(input, x + 1, y + 1, m, n, dp);

    int ans = min(a, min(b, c));
    if (ans == INT_MAX)
    {
        return dp[x][y] = input[x][y];
    }

    return dp[x][y] = (ans + input[x][y]);
}
int minCostPath(int **input, int m, int n)
{
    // Write your code here

    vector<vector<int>> dp(m, vector<int>(n, -1));

    return findMinPath(input, 0, 0, m, n, dp);
}

int main()
{
    int **arr, n, m;
    cin >> n >> m;
    arr = new int *[n];
    for (int i = 0; i < n; i++)
    {
        arr[i] = new int[m];
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }
    cout << minCostPath(arr, n, m) << endl;
}