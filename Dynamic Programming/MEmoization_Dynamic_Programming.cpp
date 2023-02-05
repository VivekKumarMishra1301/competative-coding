#include <cstring>
#include <iostream>
using namespace std;

#include <bits/stdc++.h>
int prof(int *w, int *p, int ind, int wt, vector<vector<int>> &memo)
{
    if (ind == 0)
    {
        if (wt >= w[0])
        {
            return p[0];
        }
        return 0;
    }

    if (memo[ind][wt] != -1)
    {
        return memo[ind][wt];
    }
    int notpick = prof(w, p, ind - 1, wt, memo);
    int pick = INT_MIN;
    if (w[ind] <= wt)
    {
        pick = p[ind] + prof(w, p, ind - 1, wt - w[ind], memo);
    }
    return memo[ind][wt] = max(pick, notpick);
}

int knapsack(int *weight, int *value, int n, int maxWeight)
{
    // Write your code here
    vector<vector<int>> memo(n + 1, vector<int>(maxWeight + 1, -1));
    return prof(weight, value, n - 1, maxWeight, memo);
}

int main()
{
    int n;
    cin >> n;
    int *wt = new int[n];
    int *val = new int[n];

    for (int i = 0; i < n; i++)
    {
        cin >> wt[i];
    }

    for (int j = 0; j < n; j++)
    {
        cin >> val[j];
    }

    int w;
    cin >> w;

    cout << knapsack(wt, val, n, w) << "\n";

    delete[] wt;
    delete[] val;
}