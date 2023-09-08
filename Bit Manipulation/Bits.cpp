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
    long long l, r;
    cin >> l >> r;
    long long ans = l;
    for (int i = 0; i < 64; i++)
    {
        if ((ans & (1LL << i)) == 0)
        {

            if ((ans | (1LL << i)) > r)
            {
                break;
            }
            else
            {
                ans = (ans | (1LL << i));
            }
        }
    }
    cout << ans << endl;
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
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        solve();
    }
}