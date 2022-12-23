class Solution
{
public:
    bool safeRow(vector<vector<char>> &board, int row, int col, char num)
    {
        for (int i = 0; i < 9; i++)
        {
            if (board[i][col] == num && i != row)
            {
                return false;
            }
        }
        return true;
    }
    bool safeCol(vector<vector<char>> &board, int row, int col, char num)
    {
        for (int i = 0; i < 9; i++)
        {
            if (board[row][i] == num && i != col)
            {
                return false;
            }
        }
        return true;
    }
    bool safeGrid(vector<vector<char>> &board, int row, int col, char num)
    {
        int rowfact = row - row % 3;
        int colfact = col - col % 3;
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                int r = i + (row - row % 3);
                int c = j + (col - col % 3);
                if (board[r][c] == num && r != row && c != col)
                {
                    return false;
                }
            }
        }
        return true;
    }

    bool safe(vector<vector<char>> &board, int row, int col, char num)
    {
        if (safeRow(board, row, col, num) && safeCol(board, row, col, num) && safeGrid(board, row, col, num))
        {
            return true;
        }
        return false;
    }

    bool isValidSudoku(vector<vector<char>> &board)
    {
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                if (board[i][j] == '.')
                {
                    continue;
                }
                char num = board[i][j];
                if (!safe(board, i, j, num))
                {
                    return false;
                }
            }
        }
        return true;
    }
};