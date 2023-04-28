class Solution
{
public:
    vector<int> adj[300];
    void dfs(int ind, vector<bool> &visited)
    {
        if (visited[ind])
        {
            return;
        }
        visited[ind] = true;
        for (auto i : adj[ind])
        {
            dfs(i, visited);
        }
    }

    bool similar(string s, string t)
    {
        int cnt = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] != t[i])
            {
                cnt++;
                if (cnt > 2)
                {
                    return false;
                }
            }
        }
        return true;
    }

    int numSimilarGroups(vector<string> &strs)
    {
        for (int i = 0; i < strs.size() - 1; i++)
        {
            for (int j = i + 1; j < strs.size(); j++)
            {
                if (similar(strs[i], strs[j]))
                {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        int hold = 0;
        vector<bool> visited(300, false);
        for (int i = 0; i < strs.size(); i++)
        {
            if (!visited[i])
            {
                hold++;
                dfs(i, visited);
            }
        }

        return hold;
    }
};