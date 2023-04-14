class Solution
{
public:
    bool valid(int r, int c, vector<vector<int>> &grid, vector<vector<bool>> &visited)
    {
        if (r < 0 || c < 0 || r >= grid.size() || c >= grid[r].size() || grid[r][c] != 1 || visited[r][c])
        {
            return false;
        }
        return true;
    }

    //     void dfs(int i,int j,vector<vector<int>>& grid){

    //         grid[i][j]=2;

    //         if(valid(i-1,j,grid)){
    //             dfs(i-1,j,grid);
    //         }

    //         if(valid(i+1,j,grid)){
    //             dfs(i+1,j,grid);
    //         }
    //         if(valid(i,j-1,grid)){
    //             dfs(i,j-1,grid);
    //         }
    //         if(valid(i,j+1,grid)){
    //             dfs(i,j+1,grid);
    //         }

    //     }

    int orangesRotting(vector<vector<int>> &grid)
    {
        vector<vector<bool>> visited(10, vector<bool>(10, false));

        int cnt = 0;
        queue<pair<int, int>> q;
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[i].size(); j++)
            {
                if (grid[i][j] == 2)
                {
                    q.push({i, j});
                }
            }
        }
        q.push({-1, -1});
        while (!q.empty())
        {
            pair<int, int> ind = q.front();
            q.pop();
            int r = ind.first;
            int c = ind.second;

            if (r == -1 && c == -1)
            {
                if (q.size() == 0)
                {
                    break;
                }
                else
                {
                    q.push({-1, -1});
                }
                cnt++;
                continue;
            }

            visited[r][c] = true;
            if (valid(r - 1, c, grid, visited))
            {
                grid[r - 1][c] = 2;
                q.push({r - 1, c});
            }
            if (valid(r + 1, c, grid, visited))
            {
                grid[r + 1][c] = 2;
                q.push({r + 1, c});
            }
            if (valid(r, c - 1, grid, visited))
            {
                grid[r][c - 1] = 2;
                q.push({r, c - 1});
            }
            if (valid(r, c + 1, grid, visited))
            {
                grid[r][c + 1] = 2;
                q.push({r, c + 1});
            }
            // cnt++;
        }

        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[i].size(); j++)
            {
                if (grid[i][j] == 1)
                {
                    return -1;
                }
            }
        }

        return cnt;
        ;
    }
};