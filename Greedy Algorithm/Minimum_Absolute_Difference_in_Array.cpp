#include <bits/stdc++.h>
using namespace std;
int main()
{

    // write your code here
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        int mini = INT_MAX;
        sort(arr.begin(), arr.end());
        for (int i = 1; i < n; i++)
        {
            if (arr[i] - arr[i - 1] < mini)
            {
                mini = arr[i] - arr[i - 1];
            }
        }
        cout << mini << endl;
    }
    return 0;
}