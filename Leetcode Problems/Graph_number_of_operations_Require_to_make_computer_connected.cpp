class Solution
{
public:
    int cnt = -1;
    int rnd = 0;
    int maxi = -1;
    map<int, vector<int>> adj;
    void dfs(int ind, vector<bool> &visited)
    {
        if (visited[ind])
        {

            return;
        }
        cout << ind << " ";
        visited[ind] = true;
        vector<int> k = adj[ind];
        for (int i = 0; i < k.size(); i++)
        {
            dfs(k[i], visited);
        }
    }

    int makeConnected(int n, vector<vector<int>> &connections)
    {
        for (int i = 0; i < connections.size(); i++)
        {
            adj[connections[i][0]].push_back(connections[i][1]);
            adj[connections[i][1]].push_back(connections[i][0]);
        }

        vector<bool> visited(n, false);

        for (int i = 0; i < n; i++)
        {
            if (!visited[i])
            {
                cout << i << endl;

                // visited[i]=true;
                dfs(i, visited);
                cnt++;
            }
        }
        if (connections.size() < n - 1)
        {
            return -1;
        }

        return cnt;
        return -1;
    }
};