#include <bits/stdc++.h>
using namespace std;
#define n 9

bool findempty(int maze[n][n], int &row, int &col)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (maze[i][j] == 0)
            {
                row = i;
                col = j;
                return true;
            }
        }
    }
    return false;
}

bool safeRow(int maze[n][n], int row, int col, int num)
{
    for (int i = 0; i < n; i++)
    {
        if (maze[i][col] == num)
        {
            return false;
        }
    }
    return true;
}
bool safeCol(int maze[n][n], int row, int col, int num)
{
    for (int i = 0; i < n; i++)
    {
        if (maze[row][i] == num)
        {
            return false;
        }
    }
    return true;
}

bool safeGrid(int maze[n][n], int row, int col, int num)
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {

            if (maze[i + (row - row % 3)][j + (col - col % 3)] == num)
            {
                return false;
            }
        }
    }
    return true;
}

bool checkSafe(int maze[n][n], int row, int col, int num)
{
    if (safeRow(maze, row, col, num) && safeCol(maze, row, col, num) &&
        safeGrid(maze, row, col, num))
    {
        return true;
    }
    return false;
}

bool sudoku(int maze[n][n])
{
    int row;
    int col;
    if (!findempty(maze, row, col))
    {
        return true;
    }

    for (int i = 1; i <= n; i++)
    {
        if (checkSafe(maze, row, col, i))
        {
            maze[row][col] = i;
            if (sudoku(maze))
            {
                return true;
            }
            maze[row][col] = 0;
        }
    }

    return false;
}

int main()
{

    // write your code here
    int maze[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> maze[i][j];
        }
    }
    if (sudoku(maze))
    {
        cout << "true";
    }
    else
    {
        cout << "false";
    }
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<n;j++){
    //         cout<<maze[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    // return 0;
}