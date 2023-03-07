#include <iostream>
#include <vector>
using namespace std;

bool issafe(int i, int j, int n, int m)
{
    if (i < 0 || i >= n || j >= m || j < 0)
    {
        return false;
    }
    return true;
}
bool find(int i, int j, vector<vector<char>> &board, vector<vector<bool>> &visited, string cd, int n, int m, int ind)
{
    // cout<<board[i][j]<<endl;
    visited[i][j] = true;
    // ind++;

    if (ind >= cd.size())
    {
        return true;
    }

    bool check = false;
    if (issafe(i - 1, j - 1, n, m) && board[i - 1][j - 1] == cd[ind] && !visited[i - 1][j - 1] && find(i - 1, j - 1, board, visited, cd, n, m, ind + 1))
    {
        return true;
    }
    if (issafe(i + 1, j + 1, n, m) && board[i + 1][j + 1] == cd[ind] && !visited[i + 1][j + 1] && find(i + 1, j + 1, board, visited, cd, n, m, ind + 1))
    {
        return true;
    }
    if (issafe(i - 1, j, n, m) && board[i - 1][j] == cd[ind] && !visited[i - 1][j] && find(i - 1, j, board, visited, cd, n, m, ind + 1))
    {
        return true;
    }
    if (issafe(i + 1, j - 1, n, m) && board[i + 1][j - 1] == cd[ind] && !visited[i + 1][j - 1] && find(i + 1, j - 1, board, visited, cd, n, m, ind + 1))
    {
        return true;
    }
    if (issafe(i + 1, j, n, m) && board[i + 1][j] == cd[ind] && !visited[i + 1][j] && find(i + 1, j, board, visited, cd, n, m, ind + 1))
    {
        return true;
    }
    if (issafe(i - 1, j + 1, n, m) && board[i - 1][j + 1] == cd[ind] && !visited[i - 1][j + 1] && find(i - 1, j + 1, board, visited, cd, n, m, ind + 1))
    {
        return true;
    }
    if (issafe(i, j - 1, n, m) && board[i][j - 1] == cd[ind] && !visited[i][j - 1] && find(i, j - 1, board, visited, cd, n, m, ind + 1))
    {
        return true;
    }
    if (issafe(i, j + 1, n, m) && board[i][j + 1] == cd[ind] && !visited[i][j + 1] && find(i, j + 1, board, visited, cd, n, m, ind + 1))
    {
        return true;
    }
    visited[i][j] = false;
    return false;
}

bool hasPath(vector<vector<char>> &board, int n, int m)
{
    // Write your code here.
    string cd = "CODINGNINJA";
    vector<vector<bool>> visited(n, vector<bool>(m, false));

    // visited[0]=true;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (board[i][j] == 'C' && find(i, j, board, visited, cd, n, m, 1))
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

    cout << (hasPath(board, n, m) ? 1 : 0);
}