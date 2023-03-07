#include <bits/stdc++.h>
#include <iostream>
using namespace std;

void dfs(vector<vector<bool>> &edges, vector<bool> &visited, int n, int st)
{
    visited[st] = true;
    for (int i = 0; i < n; i++)
    {
        if (edges[st][i] && !visited[i])
        {
            dfs(edges, visited, n, i);
        }
    }
}

int count(int n, vector<vector<bool>> &edges)
{
    int cnt = 0;
    vector<bool> visited(n, false);
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            cnt++;
            dfs(edges, visited, n, i);
        }
    }
    return cnt;
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
    cout << count(n, edges);
}