class Solution
{
public:
    bool safe(vector<vector<int>> &obstacleGrid, int m, int n)
    {
        if ((m <= obstacleGrid.size() - 1) && (n <= obstacleGrid[0].size() - 1) && obstacleGrid[m][n] == 0)
        {
            return true;
        }
        return false;
    }
    int countpath(vector<vector<int>> &obstacleGrid, int x, int y, vector<vector<int>> &dp)
    {
        if (x == obstacleGrid.size() - 1 && y == obstacleGrid[0].size() - 1)
        {
            if (obstacleGrid[x][y] == 0)
            {

                return 1;
            }
            return 0;
        }

        if (dp[x][y] != -1)
        {
            return dp[x][y];
        }

        if (safe(obstacleGrid, x, y))
        {

            int m = countpath(obstacleGrid, x + 1, y, dp);
            m += countpath(obstacleGrid, x, y + 1, dp);

            return dp[x][y] = m;
        }
        else
        {
            return dp[x][y] = 0;
        }
    }

    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
    {
        vector<vector<int>> dp(obstacleGrid.size() + 1, vector<int>(obstacleGrid[0].size() + 1, -1));
        return countpath(obstacleGrid, 0, 0, dp);
    }
};