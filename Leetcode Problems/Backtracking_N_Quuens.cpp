class Solution
{
public:
    bool safe(vector<string> &maze, int x, int y, int size)
    {
        for (int i = 0; i <= x; i++)
        {
            if (maze[i][y] == 'Q')
            {
                return false;
            }
        }

        for (int i = x, j = y; i >= 0 && j >= 0; i--, j--)
        {
            if (maze[i][j] == 'Q')
            {
                return false;
            }
        }
        for (int i = x, j = y; i >= 0 && j < size; i--, j++)
        {
            if (maze[i][j] == 'Q')
            {
                return false;
            }
        }
        return true;
    }

    void queen(vector<vector<string>> &hold, vector<string> &hold1, int m, int size)
    {
        if (m >= size)
        {
            hold.push_back(hold1);
        }

        for (int i = 0; i < size; i++)
        {
            if (safe(hold1, m, i, size))
            {
                hold1[m][i] = 'Q';
                queen(hold, hold1, m + 1, size);
                hold1[m][i] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n)
    {
        vector<vector<string>> hold;
        vector<string> hold1;

        for (int i = 0; i < n; i++)
        {
            string str = "";
            for (int j = 0; j < n; j++)
            {
                str += ".";
            }
            hold1.push_back(str);
        }

        queen(hold, hold1, 0, n);
        return hold;
    }
};