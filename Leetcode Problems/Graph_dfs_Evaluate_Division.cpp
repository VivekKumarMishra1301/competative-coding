class Solution
{
public:
    map<string, vector<pair<string, double>>> adj;

    double dfs(string a, string b, map<string, int> &visited)
    {
        if (adj.find(a) == adj.end())
        {
            return -1;
        }
        if (a == b)
        {
            return 1;
        }
        visited[a]++;
        for (auto g : adj[a])
        {
            if (visited.find(g.first) != visited.end())
            {
                continue;
            }
            else
            {
                double ans = dfs(g.first, b, visited);
                if (ans != -1)
                {
                    return ans * g.second;
                }
            }
        }
        return -1;
    }

    vector<double> calcEquation(vector<vector<string>> &equations, vector<double> &values, vector<vector<string>> &queries)
    {
        for (int i = 0; i < equations.size(); i++)
        {
            string a = equations[i][0];
            string b = equations[i][1];
            adj[a].push_back({b, values[i]});
            adj[b].push_back({a, 1 / values[i]});
        }

        vector<double> hold;
        for (auto q : queries)
        {
            map<string, int> visited;
            hold.push_back(dfs(q[0], q[1], visited));
        }

        return hold;
    }
};