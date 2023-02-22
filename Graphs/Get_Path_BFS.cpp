#include <bits/stdc++.h>
#include <iostream>
using namespace std;
void findBFS(vector<vector<bool>> &edges, int st, int en, int n)
{
    vector<bool> visited(n, false);
    queue<int> q;
    q.push(st);
    visited[st] = true;
    bool flag = false;
    unordered_map<int, int> meraMap;
    meraMap[st] = -1;
    while (!q.empty())
    {
        int front = q.front();
        q.pop();
        for (int i = 0; i < n; i++)
        {
            // if(i==en){
            //     flag=true;

            //   meraMap[front] = en;
            //   break;
            // }
            if (edges[front][i] && !visited[i])
            {
                q.push(i);
                visited[i] = true;
                meraMap[i] = front;
                if (i == en)
                {
                    flag = true;
                    break;
                }
            }
        }
        if (flag)
        {
            break;
        }
    }
    if (!flag)
    {
        return;
    }

    // for(auto i:meraMap){
    //     cout<<i.first<<":"<<i.second<<" ";
    // }

    while (en != -1)
    {
        cout << en << " ";
        en = meraMap[en];
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

    int st, en;
    cin >> st >> en;
    findBFS(edges, st, en, n);
}