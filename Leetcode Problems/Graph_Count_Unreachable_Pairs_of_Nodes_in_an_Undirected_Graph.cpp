class Solution
{
public:
    map<int, vector<int>> adj;
    long long hold = 0;

    void dfs(int ind, vector<bool> &visited)
    {
        if (visited[ind])
        {
            return;
        }
        hold++;
        visited[ind] = true;
        vector<int> k = adj[ind];
        for (int i = 0; i < k.size(); i++)
        {
            dfs(k[i], visited);
        }
    }

    long long countPairs(int n, vector<vector<int>> &edges)
    {
        long long cnt = 0;
        for (int i = 0; i < edges.size(); i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        vector<bool> visited(n, false);
        for (int i = 0; i < n; i++)
        {
            if (!visited[i])
            {
                dfs(i, visited);
                cnt += (hold * (n - hold));
                hold = 0;
            }
        }

        // if(edges.size()==0){
        //     return cnt/2;
        // }

        return cnt / 2;
    }
};