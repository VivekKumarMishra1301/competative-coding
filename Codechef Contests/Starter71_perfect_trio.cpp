#include <iostream>
using namespace std;

int main()
{
    // your code goes here
    int t;
    cin >> t;
    while (t--)
    {
        int admi1, admi2, admi3;
        cin >> admi1 >> admi2 >> admi3;
        if ((admi1 == (admi2 + admi3)) || (admi2 == (admi1 + admi3)) || (admi3 == (admi1 + admi2)))
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
