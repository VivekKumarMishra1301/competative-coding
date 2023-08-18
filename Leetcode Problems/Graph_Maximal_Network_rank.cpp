class Solution
{
public:
    void dfs(int ind, vector<int> adj[], vector<int> &vis)
    {
        if (vis[ind])
        {
            return;
        }
        // int cnt=0;
        // cout<<ind<<" ";
        vis[ind] = adj[ind].size();
        for (auto j : adj[ind])
        {
            // if(!vis[j]){
            // cnt++;
            // vis[ind]++;
            dfs(j, adj, vis);
            // }
        }
        cout << vis[ind] << " ";
    }

    int maximalNetworkRank(int n, vector<vector<int>> &roads)
    {
        vector<int> adj[n];
        for (auto i : roads)
        {
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        vector<int> vis(n, 0);
        for (int i = 0; i < n; i++)
        {
            if (!vis[i])
            {
                dfs(i, adj, vis);
            }
        }

        int maxi = 0;
        for (int i = 0; i < n - 1; i++)
        {
            for (int k = i + 1; k < n; k++)
            {
                bool flag = false;
                for (int j = 0; j < adj[i].size(); j++)
                {
                    if (adj[i][j] == k)
                    {
                        flag = true;
                        break;
                    }
                }
                if (flag)
                {
                    maxi = max(maxi, vis[i] + vis[k] - 1);
                }
                else
                {
                    maxi = max(maxi, vis[i] + vis[k]);
                }
            }
        }
        return maxi;
    }
};