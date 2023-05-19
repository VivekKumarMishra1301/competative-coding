#include <bits/stdc++.h>
using namespace std;
int main()
{

    // write your code here
    int n;
    cin >> n;
    vector<pair<int, int>> arr(n, {0, 0});
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        arr[i].second = a;
        arr[i].first = b;
    }
    sort(arr.begin(), arr.end());
    int cnt = 1;
    int pre = arr[0].first;
    for (int i = 1; i < n; i++)
    {
        if (arr[i].second >= pre)
        {
            cnt++;
            pre = arr[i].first;
        }
    }

    cout << cnt;
    return 0;
}