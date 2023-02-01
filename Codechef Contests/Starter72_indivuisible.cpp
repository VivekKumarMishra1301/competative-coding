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
        for (int i = 2; i < 100; i++)
        {
            if (x % i != 0 && y % i != 0 && z % i != 0)
            {
                cout << i << endl;
                break;
            }
        }
    }
    return 0;
}
