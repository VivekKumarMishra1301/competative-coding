#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
int arr[1000][1000];
using namespace std;
bool issafe(int r, int c, int n)
{
    for (int i = 0; i < r; i++)
    {
        if (arr[i][c] == 1)
        {
            return false;
        }
    }
    int r1 = r;
    int c2 = c;
    while (r1 >= 0 && c2 >= 0)
    {

        if (arr[r1][c2] == 1)
        {
            return false;
        }
        r1--;
        c2--;
    }
    r1 = r;
    c2 = c;
    while (r1 >= 0 && c2 < n)
    {

        if (arr[r1][c2] == 1)
        {
            return false;
        }
        r1--;
        c2++;
    }
    return true;
}
bool queen(int x, int y, int n, int q)
{
    if (x >= n)
    {
        return true;
    }
    for (int i = 0; i < n; i++)
    {
        if (issafe(x, i, n))
        {
            arr[x][i] = 1;
            if (queen(x + 1, y, n, q))
            {
                return true;
            }
            arr[x][i] = 0;
        }
    }
    return false;
}

int main()
{
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int x = 0, y = 0, q = 0;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            arr[i][j] = 0;
        }
    }
    queen(x, y, n, q);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
