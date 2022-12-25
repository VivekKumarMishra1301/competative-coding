#include <bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h>
int count(int n, vector<int> &dp)
{
    if (n <= 1)
    {
        return 0;
    }

    if (dp[n] != -1)
    {
        return dp[n];
    }

    int a = 1 + count(n - 1, dp);
    int c = INT_MAX;
    if (n % 2 == 0)
    {
        c = 1 + count(n / 2, dp);
    }
    int b = INT_MAX;
    if (n % 3 == 0)
    {
        b = 1 + count(n / 3, dp);
    }
    return dp[n] = min(a, min(b, c));
}
int countMinStepsToOne(int n)
{
    // Write your code here

    vector<int> dp(n + 1, -1);
    return count(n, dp);
}

int main()
{
    int n;
    cin >> n;
    cout << countMinStepsToOne(n);
}