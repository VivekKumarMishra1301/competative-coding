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
        int climbed = x / y;
        if (x % y != 0)
        {
            climbed = climbed + x % y;
        }
        cout << climbed << endl;
    }
    return 0;
}
