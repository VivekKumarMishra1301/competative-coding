#include <bits/stdc++.h>
#include <iostream>
using namespace std;

void printBFS(vector<vector<bool>> &edges, vector<bool> &visited, int v, int sv)
{

    //     if(n==0){

    //       return;

    //     }
    // if(e==0){
    //     for(int i=0;i<n;i++){
    //         cout<<i<<" ";
    //     }
    //     return;
    // }
    //     queue<int>q;
    //     q.push(sv);

    //     while(!q.empty()){

    //         int t=q.front();
    //         q.pop();

    //         if(visited[t]){
    //             continue;
    //         }

    //         visited[t]=true;

    //         for(int i=0;i<n;i++){
    //             if(edges[t][i]&&!visited[i]){
    //                 q.push(i);
    //             }
    //         }

    //         cout<<t<<" ";
    // if(n==0){
    //     return;
    // }
    // if(e==0){
    //     for(int i=0;i<n;i++){
    //         cout<<i<<" ";

    //     }
    //     return;
    // }

    // queue<int>q;
    // q.push(0);
    // visited[0]=true;
    // while(!q.empty()){
    //     int front=q.front();
    //     q.pop();
    //     for(int i=0;i<n;i++){
    //         if(i==front){
    //             continue;
    //         }
    //         if(edges[front][i]&&!visited[i]){
    //             q.push(i);
    //             visited[i]=true;
    //         }
    //     }
    //     cout<<front<<" ";
    // }

    // for(int i=0;i<n;i++){
    //     if(!visited[i]){
    //         cout<<i<<" ";
    //     }
    // }

    // vector<bool> visited(v, false);

    queue<int> q;

    // If the graph is a connected component graph
    // We Call BFs for each Component
    for (int i = 0; i < v; i++)
    {
        if (!visited[i])
        {
            q.push(i);
            visited[i] = true;
            while (!q.empty())
            {
                int front = q.front();
                q.pop();
                cout << front << " ";

                for (int i = 0; i < v; i++)
                {
                    if (edges[front][i] and !visited[i])
                    {
                        q.push(i);
                        visited[i] = true;
                    }
                }
            }
        }
    }
}
void BFS(vector<vector<bool>> &edges, int n)
{
    vector<bool> visited(n, false);
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            printBFS(edges, visited, n, i);
        }
    }
}
int main()
{
    // Write your code here
    int n;
    int e;
    cin >> n >> e;
    vector<vector<bool>> edges(n, vector<bool>(n, false));
    for (int i = 0; i < e; i++)
    {
        int f, s;
        cin >> f >> s;
        edges[f][s] = true;
        edges[s][f] = true;
    }

    // vector<bool> visited(n, false);
    BFS(edges, n);
}