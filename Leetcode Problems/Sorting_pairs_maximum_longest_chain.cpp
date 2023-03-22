#include <bits/stdc++.h>
bool cmp(const pair<int, int> &a, const pair<int, int> &b)
{
    return a.second < b.second;
}
int maxLengthChain(vector<pair<int, int>> &p, int n)
{
    // Write your code here.

    sort(p.begin(), p.end(), cmp);
    int ans = 0;
    int last = -1e9;
    for (int i = 0; i < n; i++)
    {
        if (p[i].first > last)
        {
            ans++;
            last = p[i].second;
        }
    }
    return ans;
}