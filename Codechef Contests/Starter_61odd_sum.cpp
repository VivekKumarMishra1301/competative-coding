#include <iostream>
using namespace std;
void getr()
{
    int p, q, r;
    cin >> p >> q >> r;
    if ((p + q) % 2 != 0)
    {
        cout << "YES" << endl;
        ;
    }
    else if ((q + r) % 2 != 0)
    {
        cout << "YES" << endl;
        ;
    }
    else if ((p + r) % 2 != 0)
    {
        cout << "YES" << endl;
        ;
    }
    else
    {
        cout << "NO" << endl;
        ;
    }
}
int main()
{
    // your code goes here
    int t;
    cin >> t;
    while (t--)
    {
        getr();
    }
    return 0;
}
