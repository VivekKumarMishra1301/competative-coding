#include <bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h>
int count(int n, vector<int> &dp)
{
    dp[0] = 0;
    dp[1] = 0;
    

    for (int i = 2; i <= n; i++)
    {

        int a = 1 + dp[i - 1];
        int c = INT_MAX;
        if (i % 2 == 0)
        {
            c = 1 + dp[i / 2];
        }
        int b = INT_MAX;
        if (i % 3 == 0)
        {
            b = 1 + dp[i / 3];
        }
        dp[i] = min(a, min(b, c));
    }
    return dp[n];
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