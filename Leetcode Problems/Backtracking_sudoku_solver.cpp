class Solution
{
public:
    bool findempty(vector<vector<char>> &board, int &row, int &col)
    {
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                if (board[i][j] == '.')
                {
                    row = i;
                    col = j;
                    return true;
                }
            }
        }
        return false;
    }
    bool safeRow(vector<vector<char>> &board, int row, int col, char num)
    {
        for (int i = 0; i < 9; i++)
        {
            if (board[i][col] == num)
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
            if (board[row][i] == num)
            {
                return false;
            }
        }
        return true;
    }
    bool safeGrid(vector<vector<char>> &board, int row, int col, char num)
    {
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (board[i + (row - row % 3)][j + (col - col % 3)] == num)
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

    bool sudoku(vector<vector<char>> &board)
    {
        int row;
        int col;
        if (!findempty(board, row, col))
        {
            return true;
        }

        for (int i = 1; i <= 9; i++)
        {
            char num = i + 48;
            if (safe(board, row, col, num))
            {
                board[row][col] = num;
                if (sudoku(board))
                {
                    return true;
                }
                board[row][col] = '.';
            }
        }

        return false;
    }

    void solveSudoku(vector<vector<char>> &board)
    {
        sudoku(board);
    }
};