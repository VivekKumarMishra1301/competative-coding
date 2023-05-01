#include <iostream>
#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long int
using namespace std;
void precal()
{
}
void solve()
{
    int n;
    cin >> n;
    Ij
        string s;
    string t;
    cin >> s >> t;
    int mincost = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] != t[i])
        {
            if (i + 1 < n && s[i + 1] != s[i] && s[i + 1] != t[i + 1])
            {
                swap(s[i], s[i + 1]);
                mincost++;
            }
            else
            {
                mincost++;
            }
        }
    }
    cout << mincost << endl;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout << fixed;
    cout << setprecision(10);
    precal();
    int t = 1;
    // cin>>t;
    for (int i = 1; i <= t; i++)
    {
        solve();
    }
}
