class Solution
{
public:
    bool valid(int r, int c, vector<vector<int>> &grid)
    {

        if (r < 0 || c < 0 || r >= grid.size() || c >= grid[0].size() || grid[r][c] != 1)
        {
            return false;
        }
        return true;
    }

    void dfs(int r, int c, vector<vector<int>> &grid)
    {
        grid[r][c] = 0;

        if (valid(r - 1, c, grid))
            dfs(r - 1, c, grid);
        if (valid(r + 1, c, grid))
            dfs(r + 1, c, grid);
        if (valid(r, c - 1, grid))
            dfs(r, c - 1, grid);
        if (valid(r, c + 1, grid))
            dfs(r, c + 1, grid);
    }

    int numEnclaves(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        for (int i = 0; i < n; i++)
        {
            if (grid[i][0] == 1)
                dfs(i, 0, grid);
            if (grid[i][m - 1] == 1)
                dfs(i, m - 1, grid);
        }

        for (int i = 0; i < m; i++)
        {
            if (grid[0][i] == 1)
                dfs(0, i, grid);
            if (grid[n - 1][i] == 1)
                dfs(n - 1, i, grid);
        }

        int cnt = 0;
        for (int i = 1; i < n - 1; i++)
        {
            for (int j = 1; j < m - 1; j++)
            {
                if (grid[i][j] == 1)
                {
                    cnt++;
                    // dfs(i, j, grid);
                }
            }
        }

        return cnt;
    }
};