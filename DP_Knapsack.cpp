#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
int sack[1000];
int val[1000];
int dp[1000][1000];
using namespace std;
int knapsack(int cap, int n)
{
    if (cap == 0 || n == 0)
    {
        return 0;
    }
    if (dp[n][cap] != -1)
    {
        return dp[n][cap];
    }
    if (sack[n - 1] > cap)
    {
        dp[n][cap] = knapsack(cap, n - 1);
        return dp[n][cap];
    }
    else
    {
        dp[n][cap] = max((val[n - 1] + knapsack((cap - sack[n - 1]), n - 1)), knapsack(cap, n - 1));
        return dp[n][cap];
    }
}

int main()
{
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n, cap;
    cin >> cap;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> sack[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> val[i];
    }
    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < cap + 1; j++)
        {
            dp[i][j] = -1;
        }
    }
    int res = knapsack(cap, n);
    cout << res;
    return 0;
}