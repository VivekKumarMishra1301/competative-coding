#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
void valid(int op, int cl, string res)
{
    if (op == 0 && cl == 0)
    {
        cout << res << endl;
        return;
    }
    if (op != 0)
    {
        valid(op - 1, cl, res + "(");
    }
    if (cl > op)
    {
        valid(op, cl - 1, res + ")");
    }
}

int main()
{
    /* Enter your code here. Read input from STDIN. Print output
    to STDOUT */
    int n;
    cin >> n;
    string res = "";

    valid(n, n, res);
    return 0;
}
