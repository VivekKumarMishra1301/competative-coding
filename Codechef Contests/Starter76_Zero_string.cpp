#include <iostream>
using namespace std;

int main()
{
    // your code goes here
    int t;
    cin >> t;
    while (t--)
    {
        int x;
        cin >> x;
        string st;
        cin >> st;
        int ones = 0;
        int zeroes = 0;
        for (int i = 0; i < x; i++)
        {
            if (st[i] == '1')
            {
                ones++;
            }
            else
            {
                zeroes++;
            }
        }

        if (ones == 0)
        {
            cout << 0 << endl;
            continue;
        }
        else if (zeroes == 0)
        {
            cout << 1 << endl;
            continue;
        }

        if (zeroes == 1 && x != 2)
        {
            cout << 2 << endl;
            continue;
        }
        else if (ones == 1)
        {
            cout << 1 << endl;
            continue;
        }
        if (zeroes >= ones)
        {
            cout << ones << endl;
        }
        else
        {
            cout << zeroes + 1 << endl;
        }
    }
    return 0;
}
