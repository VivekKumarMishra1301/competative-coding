#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int dp[1000];
int findmin(int n, int min)
{
    if (n <= 1)
    {
        return 0;
    }

    if (n % 3 == 0)
    {
        if (dp[n / 3] != -1)
        {
            return dp[n * 3];
        }
    }
    else if (n % 2 == 0)
    {
        if (dp[n / 2] != -1)
        {
            return dp[n * 2];
        }
    }
    else
    {

        if (dp[n + 1] != -1)
        {
            return dp[n - 1];
        }
    }

    if (n > 1)
    {
        if (n % 2 == 0)
        {
            dp[n] = findmin(n / 2, min++) + 1;
            // dp[n]= min;
            return dp[n];
        }
        if (n % 3 == 0)
        {
            dp[n] = findmin(n / 3, min++) + 1;
            // dp[n]= min;
            return dp[n];
        }
        else
        {
            dp[n] = findmin(n - 1, min++) + 1;
            // dp[n]= min;
            return dp[n];
        }
    }
    return dp[n];
}

int main()
{
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n, min = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        dp[i] = -1;
    }
    int res = findmin(n, min);
    cout << res;
    return 0;
}