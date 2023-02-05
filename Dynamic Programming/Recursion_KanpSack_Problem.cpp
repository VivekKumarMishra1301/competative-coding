#include <iostream>
using namespace std;

#include <bits/stdc++.h>
int prof(int *w, int *p, int ind, int k)
{
    if (k <= 0 || ind < 0)
    {
        return 0;
    }
    int a = INT_MIN;
    if (k >= w[ind])
    {

        a = p[ind] + prof(w, p, ind - 1, k - w[ind]);
    }
    int b = prof(w, p, ind - 1, k);
    return max(a, b);
}

int knapsack(int *weights, int *values, int n, int maxWeight)
{
    // write your code here

    return prof(weights, values, n - 1, maxWeight);
}

int main()
{
    int n;
    cin >> n;

    int *weights = new int[n];
    int *values = new int[n];

    for (int i = 0; i < n; i++)
    {
        cin >> weights[i];
    }

    for (int i = 0; i < n; i++)
    {
        cin >> values[i];
    }

    int maxWeight;
    cin >> maxWeight;

    cout << knapsack(weights, values, n, maxWeight) << endl;

    delete[] weights;
    delete[] values;
}