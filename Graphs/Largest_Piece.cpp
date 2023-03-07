#include <iostream>
#include <vector>
using namespace std;

#include <bits/stdc++.h>
bool issafe(int i, int j, int n, vector<vector<int>> &cake, vector<vector<bool>> &visited)
{
    if (i < 0 || j < 0 || i >= n || j >= n || cake[i][j] != 1 || visited[i][j])
    {
        return false;
    }
    return true;
}

int dfs(vector<vector<int>> &cake, int i, int j, int n, vector<vector<bool>> &visited)
{
    visited[i][j] = true;
    int ans = 0;
    //  if (issafe(i - 1, j - 1, n,cake,visited )  )
    // {
    //     ans=1+dfs(cake,i-1,j-1,n,visited);
    // }
    // if (issafe(i + 1, j + 1, n,cake,visited )  )
    // {
    //     ans=1+ dfs(cake,i+1,j+1,n,visited);
    // }
    if (issafe(i - 1, j, n, cake, visited))
    {
        ans += dfs(cake, i - 1, j, n, visited);
    }
    // if (issafe(i + 1, j - 1, n, cake,visited)   )
    // {
    //     ans=1+dfs(cake,i+1,j-1,n,visited);
    // }
    if (issafe(i + 1, j, n, cake, visited))
    {
        ans += dfs(cake, i + 1, j, n, visited);
    }
    // if (issafe(i - 1, j + 1, n,cake,visited ) )
    // {
    //     ans=1+dfs(cake,i-1,j+1,n,visited) ;
    // }
    if (issafe(i, j - 1, n, cake, visited))
    {
        ans += dfs(cake, i, j - 1, n, visited);
    }
    if (issafe(i, j + 1, n, cake, visited))
    {
        ans += dfs(cake, i, j + 1, n, visited);
    }
    // visited[i][j] = false;
    return ans + 1;
}

int getBiggestPieceSize(vector<vector<int>> &cake, int n)
{
    // Write your code here
    vector<vector<bool>> visited(n, vector<bool>(n, false));
    int hold = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (cake[i][j] == 1 && !visited[i][j])
            {
                hold = max(hold, dfs(cake, i, j, n, visited));
            }
        }
    }
    return hold;
}

int main()
{
    int n;
    cin >> n;

    vector<vector<int>> cake(n, vector<int>(n));

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cin >> cake[i][j];
        }
    }

    cout << getBiggestPieceSize(cake, n);
}