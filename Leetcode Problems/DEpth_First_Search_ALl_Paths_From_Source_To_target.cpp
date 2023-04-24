class Solution
{
public:
    void dfs(int ind, vector<vector<int>> &graph, vector<vector<int>> &hold, vector<int> &hold1, vector<bool> &visited)
    {
        if (ind == graph.size() - 1)
        {
            hold1.push_back(ind);
            hold.push_back(hold1);
            hold1.pop_back();
            return;
        }

        // if(visited[ind]){
        //     return;
        // }
        // visited[ind]=true;
        // vector<int>temp=hold1;
        // temp.push_back(ind);
        hold1.push_back(ind);
        for (auto i : graph[ind])
        {
            dfs(i, graph, hold, hold1, visited);
        }
        hold1.pop_back();
    }

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>> &graph)
    {
        int dst = graph.size() - 1;
        vector<vector<int>> hold;
        vector<int> hold1;
        vector<bool> visited(graph.size(), false);
        dfs(0, graph, hold, hold1, visited);
        return hold;
    }
};