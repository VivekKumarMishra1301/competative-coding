#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int mat[1000][1000], smat[1000][1000];
bool safe(int x, int y, int n)
{
    if (x < n && y < n && mat[x][y] == 1)
    {
        return true;
    }
    else
    {
        return false;
    }
};
bool rat(int x, int y, int n)
{
    if (x == n - 1 && y == n - 1)
    {
        smat[x][y] = 1;
        return true;
    }
    if (safe(x, y, n))
    {
        smat[x][y] = 1;
        if (rat(x + 1, y, n))
        {
            return true;
        }
        if (rat(x, y + 1, n))
        {
            return true;
        }
        smat[x][y] = 0;
        return false;
    }
    else
    {
        return false;
    }
};

int main()
{
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n;

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> mat[i][j];
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            smat[i][j] = 0;
        }
    }
    rat(0, 0, n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << smat[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
