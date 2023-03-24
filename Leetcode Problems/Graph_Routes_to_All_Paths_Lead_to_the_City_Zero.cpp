class Solution
{
public:
    map<int, vector<int>> adj;
    map<int, vector<int>> check;
    int cnt = 0;

    void dfs(int ind, vector<bool> &visited)
    {

        visited[ind] = true;
        vector<int> k = adj[ind];
        for (int i = 0; i < k.size(); i++)
        {
            if (!visited[k[i]])
            {
                if (check.find(k[i]) == check.end())
                {
                    cnt++;
                }
                else
                {
                    vector<int> l = check[k[i]];
                    bool flag = true;
                    for (auto m : l)
                    {
                        if (m == ind)
                        {
                            flag = false;
                            break;
                        }
                    }
                    if (flag)
                    {
                        cnt++;
                    }
                }
                // visited[k[i]]=true;
                dfs(k[i], visited);
            }
        }
    }

    int minReorder(int n, vector<vector<int>> &connections)
    {
        for (int i = 0; i < connections.size(); i++)
        {
            adj[connections[i][0]].push_back(connections[i][1]);
            adj[connections[i][1]].push_back(connections[i][0]);
            check[connections[i][0]].push_back(connections[i][1]);
        }

        vector<bool> visited(n, false);
        dfs(0, visited);
        return cnt;
    }
};