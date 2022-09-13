#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int lcs(string s1, string s2, int m, int n)
{
    int dp[m + 1][n + 1];
    for (int i = 0; i < m + 1; i++)
    {
        for (int j = 0; j < n + 1; j++)
        {
            dp[i][j] = -1;
        }
    }
    for (int i = 0; i < m + 1; i++)
    {
        for (int j = 0; j < n + 1; j++)
        {
            if (i == 0 || j == 0)
            {
                dp[i][j] = 0;
                continue;
            }
            if (s1[i - 1] == s2[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    return dp[m][n];
}

int main()
{
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    string s1, s2;
    cin >> s1 >> s2;

    int m = s1.size();
    int n = s2.size();

    cout << lcs(s1, s2, m, n);
    return 0;
}
