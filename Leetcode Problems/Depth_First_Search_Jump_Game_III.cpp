class Solution
{
public:
    bool dfs(int ind, vector<int> &arr, vector<bool> &visited)
    {
        if (ind >= arr.size() || visited[ind])
        {
            return false;
        }

        if (arr[ind] == 0)
        {
            return true;
        }

        visited[ind] = true;
        bool ans = dfs(ind + arr[ind], arr, visited);
        if (ans)
        {
            return true;
        }
        ans = ans || dfs(ind - arr[ind], arr, visited);
        return ans;
    }

    bool canReach(vector<int> &arr, int start)
    {
        vector<bool> visited(arr.size(), false);
        if (start >= arr.size())
        {
            return false;
        }

        return dfs(start, arr, visited);
    }
};