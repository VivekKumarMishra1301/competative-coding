#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n;
    cin >> n;
    long long int dp[n + 1];
    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 2;

    for (int i = 3; i < n + 1; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
    }
    cout << dp[n];
    return 0;
}