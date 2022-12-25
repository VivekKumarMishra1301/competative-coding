#include <bits/stdc++.h>
using namespace std;

int minCount(int n)
{
    // Write your code here
    if (n <= 0)
    {
        return 0;
    }
    int ans = INT_MAX;
    int i = 1;
    while (i * i <= n)
    {
        ans = 1 + min(ans, minCount(n - i * i));
        i++;
    }
    return ans;
}

int main()
{
    int n;
    cin >> n;
    cout << minCount(n);
}