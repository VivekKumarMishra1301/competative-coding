#include <iostream>
#include <climits>
using namespace std;

int main()
{
    // your code goes here
    int t;
    cin >> t;
    while (t--)
    {
        int n, ek;
        cin >> n;
        cin >> ek;
        int arr[n];
        int xorwa;

        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];

            if (i == 0)
            {
                xorwa = arr[i];
            }
            else
            {
                xorwa |= arr[i];
            }
        }

        if (ek == xorwa)
        {
            cout << 0 << endl;
            continue;
        }

        bool flag = false;
        int i = 0;
        for (i = 0; i <= ek; i++)
        {

            if ((xorwa | i) == ek)
            {
                flag = true;
                break;
            }
        }
        if (flag)
        {
            cout << i << endl;
        }
        else
        {
            cout << -1 << endl;
        }
    }
    return 0;
}
