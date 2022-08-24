#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
void valid(int op, int cl, string res, int m)
{
    if (op == 0 || (op + cl) == m)
    {
        cout << res << endl;
        return;
    }
    if (op != 0)
    {
        valid(op - 1, cl, res + "1", m);
    }
    if (cl > op)
    {
        valid(op, cl - 1, res + "0", m);
    }
}

int main()
{
    /* Enter your code here. Read input from STDIN. Print output
    to STDOUT */
    int n;
    cin >> n;
    string res = "";

    valid(n, n, res, n);
    return 0;
}
