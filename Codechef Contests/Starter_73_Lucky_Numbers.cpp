#include <iostream>
using namespace std;

int main()
{
    // your code goes here
    int t;
    cin >> t;
    while (t--)
    {
        int sankhya;
        cin >> sankhya;
        bool flag = false;
        while (sankhya > 0)
        {
            if (sankhya % 10 == 7)
            {
                flag = true;
                break;
            }
            sankhya /= 10;
        }
        if (flag)
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
