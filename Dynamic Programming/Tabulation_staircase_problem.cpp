#include <bits/stdc++.h>
using namespace std;

long stair(int n, vector<long> &dp)
{
    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 2;

    for (int i = 3; i <= n; i++)
    {
        dp[i] = (dp[i - 1] + dp[i - 2] + dp[i - 3]) % 1000000007;
    }

    return dp[n];
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
        vector<long> dp(n + 1, -1);
        cout << stair(n, dp) << endl;
    }
    return 0;
}