#include <iostream>
using namespace std;

#include <bits/stdc++.h>
int prof(int *arr, int ind, vector<int> &memo)
{
    if (ind < 0)
    {
        return 0;
    }

    if (memo[ind] != -1)
    {
        return memo[ind];
    }

    return memo[ind] = max(arr[ind] + prof(arr, ind - 2, memo),
                           prof(arr, ind - 1, memo));
}

int maxMoneyLooted(int *arr, int n)
{
    // Write your code here
    vector<int> memo(n + 1, -1);
    return prof(arr, n - 1, memo);
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

    cout << maxMoneyLooted(arr, n);

    delete[] arr;
}