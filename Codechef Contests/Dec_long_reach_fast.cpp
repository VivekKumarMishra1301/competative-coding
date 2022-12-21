#include <iostream>
using namespace std;

int main()
{
    // your code goes here
    int t;
    cin >> t;
    while (t--)
    {
        int x, y, z;
        cin >> x >> y >> z;
        int shesh = abs(x - y);
        if (shesh % z == 0)
        {
            cout << shesh / z << endl;
        }
        else
        {
            cout << (shesh / z) + 1 << endl;
        }
    }
    return 0;
}
