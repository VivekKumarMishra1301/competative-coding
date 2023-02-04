#include <cstring>
#include <iostream>
using namespace std;

#include <bits/stdc++.h>
int edit(int i, int j, string s, string t, int m, int n)
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

    if (s[i] == t[j])
    {
        return edit(i + 1, j + 1, s, t, m, n);
    }
    else
    {
        int a = 1 + edit(i + 1, j, s, t, m, n);
        int b = 1 + edit(i, j + 1, s, t, m, n);
        int c = 1 + edit(i + 1, j + 1, s, t, m, n);
        return min(a, min(b, c));
    }
}

int editDistance(string s1, string s2)
{
    // Write your code here
    return edit(0, 0, s1, s2, s1.size(), s2.size());
}

int main()
{
    string s1;
    string s2;

    cin >> s1;
    cin >> s2;

    cout << editDistance(s1, s2);
}