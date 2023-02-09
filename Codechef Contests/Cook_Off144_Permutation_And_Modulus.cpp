#include <iostream>
using namespace std;

int main()
{
    // your code goes here
    int t;
    cin >> t;
    while (t--)
    {
        int p;
        cin >> p;
        for (int i = 2; i <= p; i++)
        {
            cout << i << " ";
        }
        cout << 1 << endl;
    }
    return 0;
}
