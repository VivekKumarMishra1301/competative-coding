class Solution
{
public:
    int minJumps(vector<int> &arr)
    {
        int n = arr.size();
        unordered_map<int, vector<int>> edges;
        for (int i = 0; i < n; i++)
        {
            edges[arr[i]].push_back(i);
        }
        vector<bool> visited(n, false);
        visited[0] = true;
        queue<int> q;
        q.push(0);
        int st = 0;
        while (!q.empty())
        {
            for (int sz = q.size(); sz > 0; --sz)
            {
                int i = q.front();
                q.pop();
                if (i == n - 1)
                {
                    return st;
                }
                vector<int> &nxt = edges[arr[i]];
                nxt.push_back(i - 1);
                nxt.push_back(i + 1);
                for (int j : nxt)
                {
                    if (j >= 0 && j < n && !visited[j])
                    {
                        visited[j] = true;
                        q.push(j);
                    }
                }
                edges.erase(arr[i]);
            }
            st++;
        }
        return 0;
    }
};