class Solution
{
public:
    bool dfs(int nd, vector<int> adj[], vector<bool> &vis, vector<bool> &pathvis)
    {
        vis[nd] = true;
        pathvis[nd] = true;
        for (auto i : adj[nd])
        {
            if (!vis[i] && dfs(i, adj, vis, pathvis))
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
        return false;
    }

    bool isCyclic(int v, vector<int> adj[])
    {
        // code here
        vector<bool> vis(v, false);
        vector<bool> pathvis(v, false);
        for (int i = 0; i < v; i++)
        {
            if (!vis[i])
            {
                if (dfs(i, adj, vis, pathvis))
                {
                    return true;
                }
            }
        }
        return false;
    }

    bool canFinish(int numCourses, vector<vector<int>> &p)
    {
        vector<int> adj[numCourses];
        for (int i = 0; i < p.size(); i++)
        {
            // cout<<p[i].size()<<" ";
            // adj[p[i][0]].push_back(p[i][1]);
            adj[p[i][1]].push_back(p[i][0]);
        }

        return !isCyclic(numCourses, adj);
    }
};