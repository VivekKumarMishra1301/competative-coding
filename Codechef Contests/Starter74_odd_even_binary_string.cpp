#include <iostream>
using namespace std;

int main()
{
    // your code goes here
    int tt;
    cin >> tt;
    while (tt--)
    {
        int baar;
        cin >> baar;
        int pp[baar];
        int ss0 = 0;
        for (int j = 0; j < baar; j++)
        {
            cin >> pp[j];
            if (pp[j] == 0)
                ss0++;
        }
        if (ss0 % 2 == 0)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    return 0;
}
