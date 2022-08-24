#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
void permut(string s, int l, int r)
{
    string q = s;
    if (l == r)
    {
        cout << s << " ";

        return;
    }
    for (int i = l; i < r; i++)
    {
        swap(s[i], s[l]);
        permut(s, l + 1, r);
        s = q;
    }
}

int main()
{
    /* Enter your code here. Read input from STDIN. Print output to vSTDOUT */
    string s;
    cin >> s;
    int q = s.size();
    permut(s, 0, q);

    return 0;
}
