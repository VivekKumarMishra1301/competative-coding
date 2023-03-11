#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int find(vector<int> &weight, vector<bool> &vis, int n)
{
    int minv = -1;
    for (int i = 0; i < n; i++)
    {
        if (!vis[i] && (minv == -1 || weight[i] < weight[minv]))
        {
            minv = i;
        }
    }
    return minv;
}

void prims(vector<vector<int>> &edges, int n)
{
    vector<int> weight(n, INT_MAX);
    vector<bool> visited(n, false);
    vector<int> parent;
    for (int i = 0; i < n; i++)
    {
        parent.push_back(i);
    }
    weight[0] = 0;
    parent[0] = -1;
    for (int i = 0; i < n; i++)
    {
        int minVertex = find(weight, visited, n);
        visited[minVertex] = true;
        for (int j = 0; j < n; j++)
        {
            if (edges[minVertex][j] && !visited[j])
            {
                if (weight[j] > edges[minVertex][j])
                {
                    weight[j] = edges[minVertex][j];
                    parent[j] = minVertex;
                }
            }
        }
    }

    for (int j = 1; j < n; j++)
    {
        cout << min(parent[j], j) << " " << max(parent[j], j) << " " << weight[j] << endl;
    }
}
int main()
{
    // Write your code here
    int n;
    int e;
    cin >> n >> e;
    vector<vector<int>> edges(n, vector<int>(n, 0));
    for (int i = 0; i < e; i++)
    {
        int f, s, w;
        cin >> f >> s >> w;
        edges[f][s] = w;
        edges[s][f] = w;
    }
    prims(edges, n);
}