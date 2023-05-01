#include <bits/stdc++.h>
using namespace std;
int main()
{

    // write your code here
    int n, k, l;
    cin >> n >> k >> l;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    long maxi = (long)arr[n - 1];
    long mini = (long)arr[0];
    long cost = LONG_MAX;
    if (n == 1)
    {
        cout << 0;
        return 0;
    }
    for (int i = mini; i <= maxi; i++)
    {
        long incre = 0;
        long decre = 0;
        for (int j = 0; j < n; j++)
        {
            if (i > arr[j])
            {
                incre += (i - arr[j]);
            }
            if (i < arr[j])
            {
                decre += (arr[j] - i);
            }
        }
        // cout<<incre<<":"<<decre<<endl;
        long ncost = decre * k;
        ncost += ((incre - decre) * l);
        if (decre == 0)
        {
            ncost = incre * l;
        }
        if (incre == 0 || incre < decre)
        {
            ncost = LONG_MAX;
        }
        cost = min(cost, ncost);
    }
    cout << cost;
    return 0;
}