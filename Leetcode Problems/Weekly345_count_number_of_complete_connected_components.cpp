class Solution
{
public:
    map<int, vector<int>> adj;

    void dfs(int ind, int &nd, int &e, vector<bool> &visited)
    {
        if (visited[ind])
        {
            return;
        }

        nd++;
        visited[ind] = true;
        for (auto i : adj[ind])
        {
            e++;
            dfs(i, nd, e, visited);
        }
    }

    int countCompleteComponents(int n, vector<vector<int>> &edges)
    {
        for (auto i : edges)
        {
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }

        int cnt = 0;
        vector<bool> visited(n, false);
        for (int i = 0; i < n; i++)
        {
            int nd = 0;
            int e = 0;
            if (!visited[i])
            {
                dfs(i, nd, e, visited);
                if (((nd * (nd - 1)) / 2) == e / 2)
                {
                    cout << nd << " " << e << endl;
                    cnt++;
                }
            }
        }
        return cnt;
    }
};