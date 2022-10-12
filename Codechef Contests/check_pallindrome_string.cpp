#include <iostream>
using namespace std;
int calc1(char *s, int end)
{
    int count = 0;
    for (int i = 0; i < end; i++)
    {
        if (s[i] == '1')
        {
            count++;
        }
    }
    cout << count;
    return count;
}
int main()
{
    // your code goes here
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        char binary[n];

        for (int i = 0; i < n; i++)
        {
            cin >> binary[i];
        }
        if (n % 2 == 0)
        {
            int length = calc1(binary, n);

            if (length % 2 == 0)
            {
                cout << "YES" << endl;
            }
            else
            {
                cout << "NO" << endl;
            }
        }
        else
        {
            cout << "YES" << endl;
        }
    }
    return 0;
}
