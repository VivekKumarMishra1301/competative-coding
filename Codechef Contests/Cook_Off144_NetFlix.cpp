#include <iostream>
using namespace std;

int main()
{
    // your code goes here
    int t;
    cin >> t;
    while (t--)
    {
        int p, q, r, s, t;
        cin >> p >> q >> r >> s;
        if ((p + q) >= s || (p + r) >= s || (q + r) >= s)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
    return 0;
}
