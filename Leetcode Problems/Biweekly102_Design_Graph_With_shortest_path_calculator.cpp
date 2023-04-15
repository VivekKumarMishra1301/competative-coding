class Graph
{
public:
    int nn = 0;
    vector<vector<pair<int, int>>> g;

    Graph(int n, vector<vector<int>> &edges)
    {
        nn = n;
        for (int i = 0; i < n; i++)
        {
            vector<pair<int, int>> m;
            g.push_back(m);
        }

        for (int i = 0; i < edges.size(); i++)
        {
            int src = edges[i][0];
            int dst = edges[i][1];
            int wt = edges[i][2];
            g[src].push_back({dst, wt});
        }
    }

    void addEdge(vector<int> edge)
    {
        int src = edge[0];
        int dst = edge[1];
        int wt = edge[2];
        g[src].push_back({dst, wt});
    }

    void kamsekam(int sr, vector<int> &ds)
    {
        int n = g.size();

        ds[sr] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, sr});

        while (!pq.empty())
        {
            int u = pq.top().second;
            pq.pop();

            for (pair<int, int> ngh : g[u])
            {
                int v = ngh.first;
                int weight = ngh.second;

                if (ds[u] + weight < ds[v])
                {
                    ds[v] = ds[u] + weight;
                    pq.push({ds[v], v});
                }
            }
        }
    }

    int shortestPath(int node1, int node2)
    {
        int sr = node1;

        vector<int> ds(nn, INT_MAX);

        kamsekam(sr, ds);
        if (ds[node2] == INT_MAX)
        {
            return -1;
        }
        return ds[node2];
    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */