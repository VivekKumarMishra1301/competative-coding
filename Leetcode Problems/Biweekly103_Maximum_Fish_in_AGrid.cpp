class Solution
{
public:
    bool isv(int r, int c, vector<vector<int>> &grid)
    {
        if (r < 0 || c < 0 || r >= grid.size() || c >= grid[0].size() || grid[r][c] == 0)
        {
            return false;
        }
        return true;
    }

    void dfs(int &cnt, int ind1, int ind2, vector<vector<int>> &grid)
    {
        cnt = cnt + grid[ind1][ind2];
        grid[ind1][ind2] = 0;
        if (isv(ind1, ind2 + 1, grid))
        {
            dfs(cnt, ind1, ind2 + 1, grid);
        }
        if (isv(ind1 + 1, ind2, grid))
        {
            dfs(cnt, ind1 + 1, ind2, grid);
        }
        if (isv(ind1 - 1, ind2, grid))
        {
            dfs(cnt, ind1 - 1, ind2, grid);
        }
        if (isv(ind1, ind2 - 1, grid))
        {
            dfs(cnt, ind1, ind2 - 1, grid);
        }
    }

    int findMaxFish(vector<vector<int>> &grid)
    {
        // vector<vector<int>>ghu(grid.size(),grid[0].size());
        int hold = 0;
        for (int i = 0; i < grid.size(); i++)
        {
            int cnt = 0;
            if (grid[i][0] != 0)
            {
                dfs(cnt, i, 0, grid);
                hold = max(cnt, hold);
            }
        }
        for (int i = 0; i < grid[0].size(); i++)
        {
            int cnt = 0;
            if (grid[0][i] != 0)
            {
                dfs(cnt, 0, i, grid);
                hold = max(cnt, hold);
            }
        }
        for (int i = 0; i < grid.size(); i++)
        {
            int cnt = 0;
            if (grid[i][grid[0].size() - 1] != 0)
            {
                dfs(cnt, i, grid[0].size() - 1, grid);
                hold = max(cnt, hold);
            }
        }
        for (int i = 0; i < grid[0].size(); i++)
        {
            int cnt = 0;
            if (grid[grid.size() - 1][i] != 0)
            {
                dfs(cnt, grid.size() - 1, i, grid);
                hold = max(cnt, hold);
            }
        }
        for (int i = 1; i < grid.size() - 1; i++)
        {
            for (int j = 1; j < grid[0].size() - 1; j++)
            {
                if (grid[i][j] != 0)
                {
                    int cnt = 0;
                    dfs(cnt, i, j, grid);
                    hold = max(cnt, hold);
                }
            }
        }
        return hold;
    }
};