#include <iostream>
#include <cmath>
using namespace std;
int total(int ba, char c)
{
    double hra, da, total, pf;
    int allow, ans;
    if (ba >= 0 && ba <= 7500000)
    {

        hra = 0.2 * ba;
        da = 0.5 * ba;
        if (c == 'A')
            allow = 1700;
        else if (c == 'B')
            allow = 1500;
        else
        {
            allow = 1300;
        }
        pf = 0.11 * ba;
        total = ba + hra + da + allow - pf;
        ans = round(total);
        return ans;
    }
}
int main()
{
    int basic;
    char grade;
    cin >> basic >> grade;
    cout << (total(basic, grade));
}