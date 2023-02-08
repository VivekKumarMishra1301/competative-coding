#include <iostream>
using namespace std;
#include <bits/stdc++.h>

int ways(int num, int a, int b, vector<int> &memo)
{
    int res = pow(num, b);
    if (res == a)
    {
        return 1;
    }
    if (a < res)
    {
        return 0;
    }

    int x = ways(num + 1, a - res, b, memo);

    int y = ways(num + 1, a, b, memo);
    return x + y;
}

int getAllWays(int a, int b)
{
    // Write your code here
    vector<int> memo(a, -1);

    return ways(1, a, b, memo);
}

int main()
{
    int a, b;
    cin >> a >> b;
    cout << getAllWays(a, b);
}