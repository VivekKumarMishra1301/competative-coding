#include <bits/stdc++.h>
#include <iostream>
using namespace std;
bool find(vector<vector<bool>> &edges, int st, int end, vector<bool> &visited, int n)
{
    if (st == end)
    {
        return true;
    }

    visited[st] = true;
    bool ans = false;
    for (int i = 0; i < n; i++)
    {
        if (i == st)
        {
            continue;
        }
        if (edges[st][i])
        {
            if (visited[i])
            {
                continue;
            }
            visited[i] = true;
            ans = ans || find(edges, i, end, visited, n);
        }
    }
    return ans;
}
int main()
{
    // Write your code here
    int n, e;
    cin >> n >> e;
    vector<vector<bool>> edges(n, vector<bool>(n, false));
    for (int i = 0; i < e; i++)
    {
        int f, s;
        cin >> f >> s;
        edges[f][s] = true;
        edges[s][f] = true;
    }
    int st, end;
    cin >> st >> end;
    vector<bool> visited(n, false);
    bool ans = find(edges, st, end, visited, n);
    if (ans)
    {
        cout << "true";
    }
    else
    {
        cout << "false";
    }
}