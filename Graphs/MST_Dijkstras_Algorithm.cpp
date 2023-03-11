#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int findmin(vector<int> &distace, vector<bool> &vis, int n)
{
    int minv = -1;
    for (int i = 0; i < n; i++)
    {
        if (!vis[i] && (minv == -1 || distace[i] < distace[minv]))
        {
            minv = i;
        }
    }
    return minv;
}
void dijkstra(vector<vector<int>> &edges, int n)
{
    vector<int> distance(n, INT_MAX);
    vector<bool> visited(n, false);
    // vector<int>parent;
    // for(int i=0;i<n;i++){
    //     parent.push_back(i);
    // }

    distance[0] = 0;
    // parent[0]=0;
    for (int i = 0; i < n; i++)
    {
        int minVertex = findmin(distance, visited, n);
        visited[minVertex] = true;
        for (int j = 0; j < n; j++)
        {
            if (edges[minVertex][j] && !visited[j])
            {
                if (distance[j] > edges[minVertex][j] + distance[minVertex])
                {
                    distance[j] = edges[minVertex][j] + distance[minVertex];
                    // parent[j]=minVertex;
                }
            }
        }
    }

    for (int j = 0; j < n; j++)
    {
        // cout << min(parent[j], j) << " " << max(parent[j], j) << " " << distance[j] << endl;
        cout << j << " " << distance[j] << endl;
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
    dijkstra(edges, n);
}