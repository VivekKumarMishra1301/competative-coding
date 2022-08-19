#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    // Write your code here
    int ba, allow;
    double hra, da, pf;
    char c;
    cin >> ba >> c;

    if (ba >= 0 && ba <= 7500000)
    {
        hra = ba * (0.2);
        da = ba * (0.5);
        pf = ba * (0.11);
        if (c == 'A')
        {
            allow = 1700;
        }
        else if (c == 'B')
        {
            allow = 1500;
        }
        else if (c == 'C')
        {
            allow = 1300;
        }
        else
        {
            allow = 1300;
        }

        double total = ba + hra + da + allow - pf;
        int tot = int(round(total)); /*this is important line it is used to round off thr value of floating number but according to question it should be round off to int type so typecast it and store it in the integer type value*/
        cout << tot;
    }
}
