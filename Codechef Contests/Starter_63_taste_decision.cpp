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
        int ch = x * 2;
        int can = y * 5;
        if (ch > can)
        {
            cout << "Chocolate" << endl;
        }
        else if (can > ch)
        {
            cout << "Candy" << endl;
        }
        else
        {
            cout << "Either" << endl;
        }
    }
    return 0;
}
