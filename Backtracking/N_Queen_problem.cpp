#include <bits/stdc++.h>
using namespace std;

bool safe(vector<vector<int>> &maze, int x, int y, int size)
{
    int x1 = x;
    while (x1 >= 0)
    {
        if (maze[x1][y] == 1)
        {
            return false;
        }
        x1--;
    }
    int x2 = x, y2 = y;
    while (x2 >= 0 && y2 >= 0)
    {
        if (maze[x2][y2] == 1)
        {
            return false;
        }
        x2--;
        y2--;
    }
    while (x >= 0 && y < size)
    {
        if (maze[x][y] == 1)
        {
            return false;
        }
        x--;
        y++;
    }
    return true;
}

void printMaze(vector<vector<int>> &maze)
{
    for (int i = 0; i < maze.size(); i++)
    {
        for (int j = 0; j < maze[i].size(); j++)
        {
            cout << maze[i][j] << " ";
        }
    }
    cout << endl;
}

void queen(vector<vector<int>> &maze, int m, int n, int size)
{
    if (m >= size)
    {
        printMaze(maze);

        return;
    }

    while (n < size)
    {
        if (safe(maze, m, n, size))
        {

            maze[m][n] = 1;
            queen(maze, m + 1, 0, size);
            maze[m][n] = 0;
        }
        else
        {
            maze[m][n] = 0;
        }
        n++;
    }
}

int main()
{

    // write your code here
    int n;
    cin >> n;
    vector<vector<int>> maze(n, vector<int>(n, 0));
    // printMaze(maze);
    queen(maze, 0, 0, n);
    return 0;
}