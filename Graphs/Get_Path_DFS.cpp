#include <bits/stdc++.h>
#include <iostream>
using namespace std;
bool get(vector<vector<bool>> &edges, vector<bool> &visited, vector<int> &hold, int n, int st, int end)
{
    if (st == end)
    {
        // hold.push_back(st);
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
            // visited[i]=true;
            if (get(edges, visited, hold, n, i, end))
            {
                ans = ans || true;

                hold.push_back(i);
                return true;
            }
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
    vector<bool> visited(n, false);
    vector<int> hold;
    int st, end;
    cin >> st >> end;
    bool ans = get(edges, visited, hold, n, st, end);
    if (ans)
    {
        hold.push_back(st);
        for (int i = 0; i < hold.size(); i++)
        {
            cout << hold[i] << " ";
        }
    }
}