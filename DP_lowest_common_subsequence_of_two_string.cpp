#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int lcs(string s1, string s2, int m, int n)
{
    if (n == 0 || m == 0)
    {
        return 0;
    }
    if (s1[m - 1] == s2[n - 1])
    {
        return (1 + lcs(s1, s2, m, n));
    }
    else
    {
        return max(lcs(s1, s2, m - 1, n), lcs(s1, s2, m, n - 1));
    }
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
