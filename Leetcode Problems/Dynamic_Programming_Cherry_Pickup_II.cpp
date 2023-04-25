class Solution
{
public:
    int pick(int r, int c1, int c2, int n, int m, vector<vector<int>> &grid, vector<vector<vector<int>>> &dp)
    {
        if (c1 < 0 || c2 < 0 || c1 >= m || c2 >= m)
        {
            return -1e9;
        }
        if (r == n - 1)
        {
            if (c1 == c2)
                return grid[r][c1];
            return grid[r][c1] + grid[r][c2];
        }
        if (dp[r][c1][c2] != -1)
        {
            return dp[r][c1][c2];
        }
        int maxi = 0;
        for (int dj1 = -1; dj1 <= 1; dj1++)
        {
            for (int dj2 = -1; dj2 <= 1; dj2++)
            {
                if (c1 == c2)
                {
                    maxi = max(maxi, grid[r][c1] + pick(r + 1, c1 + dj1, c2 + dj2, n, m, grid, dp));
                }
                else
                {
                    maxi = max(maxi, grid[r][c2] + grid[r][c1] + pick(r + 1, c1 + dj1, c2 + dj2, n, m, grid, dp));
                }
            }
        }

        return dp[r][c1][c2] = maxi;
    }

    int cherryPickup(vector<vector<int>> &grid)
    {
        vector<vector<vector<int>>> dp(grid.size(), vector<vector<int>>(grid[0].size(), vector<int>(grid[0].size(), -1)));

        return pick(0, 0, grid[0].size() - 1, grid.size(), grid[0].size(), grid, dp);
    }
};