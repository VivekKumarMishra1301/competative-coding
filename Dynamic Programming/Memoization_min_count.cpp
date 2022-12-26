#include <bits/stdc++.h>
using namespace std;
int findNum(int n, vector<int> &dp)
{
    if (n <= 0)
    {
        return 0;
    }

    if (dp[n] != -1)
    {
        return dp[n];
    }

    int ans = INT_MAX;
    int i = 1;
    while (i * i <= n)
    {
        ans = min(ans, 1 + findNum(n - i * i, dp));
        i++;
    }
    return dp[n] = ans;
}
int minCount(int n)
{
    // Write your code here
    vector<int> dp(n + 1, -1);
    return findNum(n, dp);
}
int main()
{
    int n;
    cin >> n;
    cout << minCount(n);
}