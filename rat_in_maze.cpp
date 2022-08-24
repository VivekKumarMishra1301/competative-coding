#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
int arr[1000][1000];
int arr2[1000][1000];
using namespace std;
void maze(int p, int q, int n)
{
    if (p == n - 1 && q == n - 1)
    {
        arr2[p][q] = 1;
        return;
    }
    if (p >= n || q >= n)
    {
        return;
    }
    if (arr[p + 1][q] != 0)
    {
        arr2[p][q] = 1;
        maze(p + 1, q, n);
    }
    if (arr[p][q + 1] != 0)
    {
        arr2[p][q] = 1;
        maze(p, q + 1, n);
    }
    if (arr[p + 1][q] != 1 && arr[p][q + 1] != 1)
    {
        if (arr[p - 1][q] == 1)
        {
            arr2[p][q] = 0;
            maze(p - 1, q, n);
        }
        if (arr[p][q - 1] == 1)
        {
            arr2[p][q] = 0;
            maze(p, q - 1, n);
        }
    }
}

int main()
{
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n, p = 0, q = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            arr2[i][j] = 0;
        }
    }

    maze(p, q, n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << arr2[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
