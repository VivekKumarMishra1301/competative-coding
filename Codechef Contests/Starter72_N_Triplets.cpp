#include <iostream>
using namespace std;

long long tigada(int antar)
{
    if (antar <= 1)
    {
        return false;
    }
    for (int j = 2; j * j < antar; j++)
    {
        if (antar % j == 0)
        {
            return j;
        }
    }
    return -1;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int teen;
        cin >> teen;
        long long val = tigada(teen);
        if (val == -1)
        {
            cout << -1 << endl;
        }
        else
        {
            cout << val << " " << (teen / val) << " " << 1 << endl;
        }
    }

    return 0;
}