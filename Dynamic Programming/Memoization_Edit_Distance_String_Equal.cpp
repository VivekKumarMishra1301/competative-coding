#include <iostream>
#include <cstring>
using namespace std;

#include <bits/stdc++.h>
int edit(int i, int j, string s, string t, int m, int n, vector<vector<int>> &memo)
{
    if (i == m && j == n)
    {
        return 0;
    }
    else if (i < m && j == n)
    {
        return (m - i);
    }
    else if (i == m && j < n)
    {
        return (n - j);
    }

    if (memo[i][j] != -1)
    {
        return memo[i][j];
    }

    int ans;
    if (s[i] == t[j])
    {
        ans = edit(i + 1, j + 1, s, t, m, n, memo);
    }
    else
    {
        int a = 1 + edit(i + 1, j, s, t, m, n, memo);
        int b = 1 + edit(i, j + 1, s, t, m, n, memo);
        int c = 1 + edit(i + 1, j + 1, s, t, m, n, memo);
        ans = min(a, min(b, c));
    }
    return memo[i][j] = ans;
}

int editDistance(string s1, string s2)
{
    // Write your code here
    vector<vector<int>> memo(s1.size() + 1, vector<int>(s2.size() + 1, -1));
    return edit(0, 0, s1, s2, s1.size(), s2.size(), memo);
}

int main()
{
    string s1;
    string s2;

    cin >> s1;
    cin >> s2;

    cout << editDistance(s1, s2) << endl;
}