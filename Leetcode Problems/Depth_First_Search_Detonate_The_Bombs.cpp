class Solution
{
public:
    map<int, vector<int>> adj;

    void dfs(int ind, vector<bool> &visited, int &m)
    {
        if (visited[ind])
        {
            return;
        }
        visited[ind] = true;

        m++;
        for (auto j : adj[ind])
        {
            dfs(j, visited, m);
        }
    }

    int maximumDetonation(vector<vector<int>> &bombs)
    {

        for (int i = 0; i < bombs.size(); i++)
        {
            double x1 = bombs[i][0];
            double y1 = bombs[i][1];
            double r1 = bombs[i][2];
            // cout<<i<<":"<<" ";
            for (int j = 0; j < bombs.size(); j++)
            {
                if (i != j)
                {

                    double x2 = bombs[j][0];
                    double y2 = bombs[j][1];
                    double r2 = bombs[j][2];

                    double dst = (pow(abs(x1 - x2), 2) + pow(abs(y2 - y1), 2));
                    cout << dst << " ";
                    if (dst <= (r1 * r1))
                    {

                        adj[i].push_back(j);
                        // cout<<j<<" ";
                    }
                }
            }
            // cout<<endl;
        }

        int maxi = 0;
        int m = 0;
        vector<bool> visited(bombs.size(), false);

        for (int i = 0; i < bombs.size(); i++)
        {
            if (!visited[i])
            {
                dfs(i, visited, m);
                maxi = max(maxi, m);
                m = 0;
                fill(visited.begin(), visited.end(), 0);
            }
        }
        return maxi;
    }
};