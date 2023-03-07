#include <iostream>
#include <vector>
using namespace std;

bool dfs(vector<vector<char>> &board, char col, int pi, int pj, int i, int j, int n, int m, vector<vector<bool>> &visited)
{
    bool d1 = (i + 1 < n && !(i + 1 == pi && j == pj) && visited[i + 1][j]);
    bool d2 = (j + 1 < m && !(i == pi && j + 1 == pj) && visited[i][j + 1]);
    bool d3 = (i - 1 >= 0 && !(i - 1 == pi && j == pj) && visited[i - 1][j]);
    bool d4 = (j - 1 >= 0 && !(i == pi && j - 1 == pj) && visited[i][j - 1]);

    if (d1 || d2 || d3 || d4)
        return true;

    visited[i][j] = true;
    if (i + 1 < n && board[i + 1][j] == col && !visited[i + 1][j] && dfs(board, col, i, j, i + 1, j, n, m, visited))
        return true;

    if (j + 1 < m && board[i][j + 1] == col && !visited[i][j + 1] && dfs(board, col, i, j, i, j + 1, n, m, visited))
        return true;

    if (i - 1 >= 0 && board[i - 1][j] == col && !visited[i - 1][j] && dfs(board, col, i, j, i - 1, j, n, m, visited))
        return true;

    if (j - 1 >= 0 && board[i][j - 1] == col && !visited[i][j - 1] && dfs(board, col, i, j, i, j - 1, n, m, visited))
        return true;
    visited[i][j] = false;
    return false;
}

bool hasCycle(vector<vector<char>> &board, int n, int m)
{
    // Write your code here.
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (!visited[i][j] && dfs(board, board[i][j], i, j, i, j, n, m, visited))
            {
                return true;
            }
        }
    }
    return false;
}

int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<char>> board(n, vector<char>(m));

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            cin >> board[i][j];
        }
    }

    cout << (hasCycle(board, n, m) ? "true" : "false");
}