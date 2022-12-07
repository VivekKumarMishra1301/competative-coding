#include <iostream>
using namespace std;

int main()
{
    // your code goes here
    int t;
    cin >> t;
    while (t--)
    {
        int x, y;
        cin >> x >> y;
        int sum = (x + y);
        if (sum % 2 == 0)
        {
            cout << sum / 2 << endl;
        }
        else
        {
            cout << "-1" << endl;
        }
    }
    return 0;
}
