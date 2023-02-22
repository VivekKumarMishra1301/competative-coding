#include <bits/stdc++.h>
#include <iostream>
using namespace std;
void dfs(vector<vector<bool>> &edges, int st, int n, vector<int> &hold1, vector<bool> &visited)
{
    hold1.push_back(st);
    visited[st] = true;
    for (int i = 0; i < n; i++)
    {
        if (edges[st][i] && !visited[i])
        {
            visited[i] = true;
            dfs(edges, i, n, hold1, visited);
        }
    }
}

void allcon(vector<vector<bool>> &edges, int n)
{
    vector<bool> visited(n, false);
    vector<vector<int>> hold;
    for (int i = 0; i < n; i++)
    {
        vector<int> hold1;
        if (!visited[i])
        {
            dfs(edges, i, n, hold1, visited);
            hold.push_back(hold1);
        }
    }
    for (int i = 0; i < hold.size(); i++)
    {
        sort(hold[i].begin(), hold[i].end());
        for (int j = 0; j < hold[i].size(); j++)
        {
            cout << hold[i][j] << " ";
        }
        cout << endl;
    }
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

    allcon(edges, n);
}