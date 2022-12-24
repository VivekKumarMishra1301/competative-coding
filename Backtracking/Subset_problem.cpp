#include <bits/stdc++.h>
using namespace std;

int countSubset(long arr[], int n, long k, long sum, int ind)
{
    if (ind >= n)
    {
        return 0;
    }
    int ans = 0;

    int pick = countSubset(arr + 1, n, k, sum, ind + 1);
    sum += arr[0]; // inserting value in the sum
    if (sum == k)
    {
        ans = 1;
    }
    int notpick = countSubset(arr + 1, n, k, sum, ind + 1);
    sum -= arr[0]; // removing the value from the sum for the backtrcking Here the backtracking is occurring by substracting the first index value from the array

    return ans + pick + notpick;
}

int main()
{

    // write your code here
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        long k;
        cin >> n;
        cin >> k;
        long arr[n];
        long sum = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        if (k == 0)
        {
            cout << countSubset(arr, n, k, sum, 0) + 1 << endl;
        }
        else
        {
            cout << countSubset(arr, n, k, sum, 0) << endl;
        }
    }
    return 0;
}