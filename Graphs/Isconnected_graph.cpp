#include <bits/stdc++.h>
#include <iostream>
using namespace std;
void bfs(vector<vector<bool>> &edges, int st, int n, vector<bool> &visited)
{
    queue<int> q;
    q.push(st);
    visited[st] = true;
    while (!q.empty())
    {
        int front = q.front();
        q.pop();
        for (int i = 0; i < n; i++)
        {
            if (edges[front][i] && !visited[i])
            {
                q.push(i);
                visited[i] = true;
            }
        }
    }
}

bool iscon(vector<vector<bool>> &edges, int n)
{
    vector<bool> visited(n, false);
    bfs(edges, 0, n, visited);
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            return false;
        }
    }
    return true;
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
        edges[f][s] = 1;
        edges[s][f] = 1;
    }
    if (iscon(edges, n))
    {
        cout << "true";
    }
    else
    {
        cout << "false";
    }
}