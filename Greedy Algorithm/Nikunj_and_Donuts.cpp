#include <bits/stdc++.h>
using namespace std;
int main()
{

    // write your code here
    int t;
    cin >> t;
    while (t--)
    {
        long n;
        cin >> n;
        vector<long> arr(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        sort(arr.begin(), arr.end(), greater<int>());
        long p = 1;
        long walk = 0;
        for (int i = 0; i < n; i++)
        {
            walk += (p * arr[i]);
            p *= 2;
        }
        cout << walk << endl;
    }
    return 0;
}