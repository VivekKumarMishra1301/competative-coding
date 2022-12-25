#include <bits/stdc++.h>
void permut(string s, vector<string> &hold, int l, int r)
{
    string q = s;
    if (l == r)
    {
        hold.push_back(s);

        return;
    }
    for (int i = l; i < r; i++)
    {
        swap(s[i], s[l]);
        permut(s, hold, l + 1, r);
        s = q;
    }
}
vector<string> findPermutations(string &s)
{
    // Write your code here.
    vector<string> hold;
    permut(s, hold, 0, s.size());
    return hold;
}