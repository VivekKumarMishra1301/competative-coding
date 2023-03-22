class Solution
{
public:
    map<int, map<int, int>> adj;

    void dfs(vector<bool> &visited, int n, int ind, int &mn)
    {
        if (visited[ind])
        {
            return;
        }
        visited[ind] = true;
        for (auto i : adj[ind])
        {
            mn = min(mn, i.second);
            dfs(visited, n, i.first, mn);
        }
    }

    int minScore(int n, vector<vector<int>> &roads)
    {
        for (int i = 0; i < roads.size(); i++)
        {
            adj[roads[i][0]].insert(make_pair(roads[i][1], roads[i][2]));
            adj[roads[i][1]].insert(make_pair(roads[i][0], roads[i][2]));
        }
        int mn = 1e5;
        vector<bool> visited(n + 1, false);
        dfs(visited, n, 1, mn);
        return mn;
    }
};