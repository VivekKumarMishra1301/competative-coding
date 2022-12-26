#include <bits/stdc++.h>
using namespace std;

int findMinPath(int **input, int x, int y, int m, int n)
{
    if (x >= m || y >= n)
    {
        return INT_MAX;
    }
    int a = findMinPath(input, x + 1, y, m, n);

    int b = findMinPath(input, x, y + 1, m, n);

    int c = findMinPath(input, x + 1, y + 1, m, n);

    int ans = min(a, min(b, c));
    if (ans == INT_MAX)
    {
        return input[x][y];
    }

    return ans + input[x][y];
}
int minCostPath(int **input, int m, int n)
{
    // Write your code here
    return findMinPath(input, 0, 0, m, n);
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