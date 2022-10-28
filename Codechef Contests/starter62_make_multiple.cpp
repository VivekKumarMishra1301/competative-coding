#include <iostream>
#include <algorithm>
using namespace std;
void check()
{
    int p, q;
    cin >> p >> q;
    if (q % p == 0)
    {
        cout << "YES" << endl;
    }
    else
    {
        if (p <= q / 2)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
}
int main()
{
    // your code goes here
    int t;
    cin >> t;
    while (t--)
    {
        check();
    }
    return 0;
}
