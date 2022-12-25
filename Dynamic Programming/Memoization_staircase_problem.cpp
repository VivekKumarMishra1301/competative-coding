#include <bits/stdc++.h>
using namespace std;

long stair(int n, vector<int> &dp)
{
    if (n == 0 || n == 1)
    {
        return 1;
    }

    if (dp[n] != -1)
    {
        return dp[n];
    }
    return dp[n] = (stair(n - 1, dp) + stair(n - 2, dp) + stair(n - 3, dp)) % 1000000007;
}

int main()
{

    // write your code here
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> dp(n + 1, -1);
        cout << stair(n, dp) << endl;
    }
    return 0;
}