class Solution
{
public:
    void dfs(int ind, vector<bool> &visited, vector<int> adj[])
    {
        visited[ind] = true;
        for (auto i : adj[ind])
        {
            if (!visited[i])
            {
                dfs(i, visited, adj);
            }
        }
    }

    int findCircleNum(vector<vector<int>> &isConnected)
    {
        vector<int> adj[isConnected.size() + 1];
        for (int i = 0; i < isConnected.size(); i++)
        {
            for (int j = 0; j < isConnected[0].size(); j++)
            {
                if (isConnected[i][j])
                {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        int cnt = 0;
        vector<bool> visited(isConnected.size() + 1, false);
        for (int i = 0; i < isConnected.size(); i++)
        {
            if (!visited[i])
            {
                dfs(i, visited, adj);
                cnt++;
            }
        }
        return cnt;
    }
};