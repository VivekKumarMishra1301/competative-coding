#include <iostream>
using namespace std;

int main()
{
    // your code goes here
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int dabba[n];
        int oddwale = 0;
        int evenwale = 0;
        bool flag = false;
        for (int i = 0; i < n; i++)
        {
            cin >> dabba[i];

            evenwale = evenwale + dabba[i];
            if (dabba[i] % 2 != 0)
            {
                flag = true;
            }
        }
        if (evenwale % 2 == 0 && flag == true)
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
