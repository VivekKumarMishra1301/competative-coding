#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
void ways(int sx, int sy, int dx, int dy, string path)
{
    if (sx == (dx - 1) && sy == (dy - 1))
    {
        cout << path << endl;
        return;
    }
    if (sx >= dx || sy >= dy)
    {
        return;
    }
    ways(sx + 1, sy, dx, dy, path + "D ");
    ways(sx, sy + 1, dx, dy, path + "R ");
}

int main()
{
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int m, n, p = 0, q = 0;
    cin >> m >> n;
    string res = "";
    ways(p, q, m, n, res);
    return 0;
}
