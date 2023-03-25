class Solution
{
public:
    bool issafe(int r, int c, vector<vector<char>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        if (r < 0 || c < 0 || r >= n || c >= m || grid[r][c] != 'O')
        {
            return false;
        }
        return true;
    }

    void dfs(int row, int col, vector<vector<bool>> &visited, vector<vector<char>> &grid)
    {
        if (visited[row][col])
        {
            return;
        }
        visited[row][col] = true;
        // if(!issafe(row,col,grid)){
        //     return false;
        // }
        grid[row][col] = '#';
        bool check = false;
        if (issafe(row, col - 1, grid))
        {
            dfs(row, col - 1, visited, grid);
        }
        if (issafe(row, col + 1, grid))
        {
            dfs(row, col + 1, visited, grid);
        }

        if (issafe(row + 1, col, grid))
        {
            dfs(row + 1, col, visited, grid);
        }
        if (issafe(row - 1, col, grid))
        {
            dfs(row - 1, col, visited, grid);
        }
    }

    void solve(vector<vector<char>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (!visited[i][j] && grid[i][j] == 'O' && (i == 0 || j == 0 || i == n - 1 || j == m - 1))
                {
                    dfs(i, j, visited, grid);
                    // cnt++;
                }
            }
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == '#')
                {
                    grid[i][j] = 'O';
                }
                else
                {
                    grid[i][j] = 'X';
                }
            }
        }
        // return cnt;
    }
};