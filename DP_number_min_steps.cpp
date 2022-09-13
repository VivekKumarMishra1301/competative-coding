#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int dp[1000];
int findmin(int n)
{
    if (n <= 1)
    {
        return 0;
    }

    if (n > 1)
    {
        if (n % 3 == 0)
        {
            dp[n] = findmin(n / 3) + 1;
            return dp[n];
        }
        else if ((n - 1) % 3 == 0)
        {
            dp[n] = findmin((n - 1) / 3) + 2;
            return dp[n];
        }
        else if (n % 2 == 0)
        {
            dp[n] = findmin(n / 2) + 1;
            return dp[n];
        }
        else
        {
            dp[n] = findmin(n - 1) + 1;
            return dp[n];
        }
    }
    return dp[n];
}

int main()
{
    int n, min = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        dp[i] = -1;
    }
    int res = findmin(n);
    cout << res;
    return 0;
}