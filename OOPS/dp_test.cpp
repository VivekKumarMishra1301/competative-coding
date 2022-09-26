#include <iostream>

using namespace std;
int dp[10000];
int fib(long long n)
{
    if (n == 0 || n == 1)
    {
        return n;
    }
    if (dp[n] != -1)
    {
        return dp[n];
    }
    dp[n] = dp[n - 1] + dp[n - 2];
    return dp[n];
}
int main()
{
    long long n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        dp[i] = -1;
    }
    for (int i = 0; i < n; i++)
    {
        cout << i << "= " << fib(i) << endl;
    }
}