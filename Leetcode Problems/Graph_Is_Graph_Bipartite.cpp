class Solution
{
public:
    bool isBipartite(vector<vector<int>> &graph)
    {
        vector<int> visited(graph.size(), -1);
        for (int i = 0; i < graph.size(); i++)
        {
            if (visited[i] == -1)
            {
                queue<int> q;
                q.push(i);
                visited[i] = 0;
                while (!q.empty())
                {
                    int tp = q.front();
                    q.pop();
                    for (int k = 0; k < graph[tp].size(); k++)
                    {
                        if (visited[graph[tp][k]] == -1)
                        {
                            q.push(graph[tp][k]);
                            if (visited[tp] == 0)
                            {
                                visited[graph[tp][k]] = 1;
                            }
                            else
                            {
                                visited[graph[tp][k]] = 0;
                            }
                        }
                        else if (visited[graph[tp][k]] != visited[tp])
                        {
                            if (visited[tp] == 0)
                            {
                                visited[graph[tp][k]] = 1;
                            }
                            else
                            {
                                visited[graph[tp][k]] = 0;
                            }
                        }
                        else
                        {
                            return false;
                        }
                    }
                }
            }
        }
        return true;
    }
};