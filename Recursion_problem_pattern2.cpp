#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
void pat(int n)
{
    if (n == 0)
    {
        return;
    }
    for (int i = 0; i < n; i++)
    {
        cout << "*";
    }
    cout << endl;
    pat(n - 1);
};

int main()
{
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n;
    cin >> n;
    pat(n);
    return 0;
}
