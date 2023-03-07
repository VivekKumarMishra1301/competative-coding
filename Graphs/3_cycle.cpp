#include <bits/stdc++.h>
#include <iostream>
using namespace std;

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

    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (edges[i][j] && i != j)
            {
                for (int k = 0; k < n; k++)
                {
                    if (edges[k][j] && k != i && edges[k][i])
                    {
                        cnt++;
                    }
                }
            }
        }
    }
    cout << cnt / 6;
}