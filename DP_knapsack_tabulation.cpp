#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n, cap;
    cin >> cap;
    cin >> n;
    int sack[1000];
    int val[1000];
    int dp[n + 1][cap + 1];
    for (int i = 0; i < n; i++)
    {
        cin >> sack[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> val[i];
    }
    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < cap + 1; j++)
        {
            dp[i][j] = -1;
        }
    }
    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < cap + 1; j++)
        {
            if (i == 0 || j == 0)
            {
                dp[i][j] = 0;
            }
            else if (sack[i - 1] > j)
            {
                dp[i][j] = dp[i - 1][j];
            }
            else
            {
                dp[i][j] = max((val[i - 1] + dp[i - 1][j - sack[i - 1]]), dp[i - 1][j]);
            }
        }
    }
    cout << dp[n][cap];
    return 0;
}