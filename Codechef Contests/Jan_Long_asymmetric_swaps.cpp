#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main()
{
    // your code goes here
    int t;
    cin >> t;
    while (t--)
    {
        int x;
        cin >> x;
        vector<int> arr;
        // vector<int>brr;
        for (int i = 0; i < x; i++)
        {
            int take;
            cin >> take;
            arr.push_back(take);
        }
        for (int i = 0; i < x; i++)
        {
            int take;
            cin >> take;
            arr.push_back(take);
        }

        sort(arr.begin(), arr.end());
        int hold = INT_MAX;
        for (int i = 0; i <= x; i++)
        {
            hold = min(hold, arr[x + i - 1] - arr[i]);
        }

        cout << hold << endl;
    }
    return 0;
}
