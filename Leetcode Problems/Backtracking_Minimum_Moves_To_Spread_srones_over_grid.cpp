class Solution
{
public:
    int minimumMoves(vector<vector<int>> &grid)
    {
        int t = 0;
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (grid[i][j] == 0)
                {
                    t++;
                }
            }
        }

        if (t == 0)
        {
            return 0;
        }

        int ans = INT_MAX;
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (grid[i][j] == 0)
                {
                    for (int m = 0; m < 3; m++)
                    {
                        for (int n = 0; n < 3; n++)
                        {
                            if (grid[m][n] > 1)
                            {
                                int d = abs(i - m) + abs(j - n);
                                grid[m][n]--;
                                grid[i][j]++;
                                ans = min(ans, d + minimumMoves(grid));
                                grid[m][n]++;
                                grid[i][j]--;
                            }
                        }
                    }
                }
            }
        }

        return ans;
    }
};