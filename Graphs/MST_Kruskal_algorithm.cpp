#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class edge
{
    // private:
public:
    int src;
    int dst;
    int wt;
    edge(int s, int d, int w)
    {
        this->src = s;
        this->dst = d;
        this->wt = w;
    }
};

void kruskal(vector<edge> &edges, int n, vector<edge> &hold)
{
    vector<int> parent;
    for (int i = 0; i < n; i++)
    {
        parent.push_back(i);
    }

    int cnt = 0;
    int i = 0;
    while (cnt < n - 1)
    {
        int v1 = edges[i].src;
        int v2 = edges[i].dst;
        int p1 = parent[v1];
        int p2 = parent[v2];
        while (parent[p1] != p1)
        {
            p1 = parent[p1];
        }
        while (parent[p2] != p2)
        {
            p2 = parent[p2];
        }
        if (p1 != p2)
        {
            hold.push_back(edges[i]);
            parent[p1] = p2;
            cnt++;
        }
        i++;
    }
}

int main()
{
    // Write your code here
    int n, e;
    cin >> n >> e;
    vector<edge> edges;
    for (int i = 0; i < e; i++)
    {
        int s, d, w;
        cin >> s >> d >> w;
        // edge e=new edge(s,d,w);
        edge e(s, d, w);
        edges.push_back(e);
        // cout<<e.src<<e.dst<<e.wt<<endl;
    }
    vector<edge> kr;
    sort(edges.begin(), edges.end(), [](const edge &a, const edge &b)
         { return (a.wt < b.wt); });
    //  for(int i=0;i<e;i++){
    //     // int s,d,w;
    //     // cin>>s>>d>>w;
    //     // // edge e=new edge(s,d,w);
    //     // edge e(s,d,w);
    //     // edges.push_back(e);
    //     cout<<edges[i].src<<edges[i].dst<<edges[i].wt<<endl;
    // }
    kruskal(edges, n, kr);
    for (int i = 0; i < kr.size(); i++)
    {
        cout << min(kr[i].src, kr[i].dst) << " " << max(kr[i].dst, kr[i].src) << " " << kr[i].wt << endl;
    }
}