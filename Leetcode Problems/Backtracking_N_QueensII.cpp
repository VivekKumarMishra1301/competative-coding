class Solution
{
public:
    int output = 0;

    bool safe(vector<vector<int>> &maze, int x, int y, int size)
    {
        for (int i = 0; i <= x; i++)
        {
            if (maze[i][y] == 1)
            {
                return false;
            }
        }

        for (int i = x, j = y; i >= 0 && j >= 0; i--, j--)
        {
            if (maze[i][j] == 1)
            {
                return false;
            }
        }
        for (int i = x, j = y; i >= 0 && j < size; i--, j++)
        {
            if (maze[i][j] == 1)
            {
                return false;
            }
        }
        return true;
    }

    void queen(vector<vector<int>> &maze, int m, int size)
    {
        if (m >= size)
        {
            output++;
            return;
        }

        for (int i = 0; i < size; i++)
        {
            if (safe(maze, m, i, size))
            {
                maze[m][i] = 1;
                queen(maze, m + 1, size);
                maze[m][i] = 0;
            }
        }
    }

    int totalNQueens(int n)
    {
        vector<vector<int>> maze(n, vector<int>(n, 0));
        queen(maze, 0, n);
        return output;
    }
};