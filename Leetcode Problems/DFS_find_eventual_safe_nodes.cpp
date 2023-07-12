class Solution
{
public:
    bool dfs(int nd, vector<vector<int>> &adj, vector<bool> &vis, vector<bool> &pathvis, vector<int> &hold)
    {
        vis[nd] = true;
        pathvis[nd] = true;
        for (auto i : adj[nd])
        {
            if (!vis[i] && dfs(i, adj, vis, pathvis, hold))
            {
                return true;
            }
            else
            {
                if (pathvis[i])
                {
                    return true;
                }
            }
        }
        pathvis[nd] = false;
        hold.push_back(nd);
        return false;
    }

    vector<int> isCyclic(int v, vector<vector<int>> &adj)
    {
        // code here
        vector<int> hold;
        vector<bool> vis(v, false);
        vector<bool> pathvis(v, false);
        for (int i = 0; i < v; i++)
        {
            if (!vis[i])
            {
                dfs(i, adj, vis, pathvis, hold);
                // return true;
            }
        }
        sort(hold.begin(), hold.end());
        return hold;
    }

    vector<int> eventualSafeNodes(vector<vector<int>> &graph)
    {
        return isCyclic(graph.size(), graph);
    }
};