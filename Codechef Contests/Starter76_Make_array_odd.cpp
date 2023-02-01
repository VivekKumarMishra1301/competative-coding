#include <iostream>
using namespace std;

int main()
{
    // your code goes here
    int t;
    cin >> t;
    while (t--)
    {
        int p, q;
        cin >> p >> q;

        int ev = 0;
        int od = 0;
        int arr[p];
        for (int i = 0; i < p; i++)
        {
            cin >> arr[i];
            if (arr[i] % 2 == 0)
            {
                ev++;
            }
            else
            {
                od++;
            }
        }

        if (q % 2 != 0)
        {
            if (ev % 2 != 0)
            {
                cout << ev / 2 + 1 << endl;
            }
            else
            {
                cout << ev / 2 << endl;
            }
        }
        else
        {
            if (ev == p)
            {
                cout << -1 << endl;
            }
            else
            {
                cout << ev << endl;
            }
        }
    }
    return 0;
}
