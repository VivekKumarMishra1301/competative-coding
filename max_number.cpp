#include <iostream>
using namespace std;
int main()
{
    int max = 0, max1, a, flag = 0, n;
    cout << "enter the size of input" << endl;
    cin >> n;
    max1 = max;
    cin >> a;
    if (a >= 0)
    {
        flag = 1;
        max = a;
    }
    else
    {
        max1 = a;
    }
    for (int i = 1; i < n; i++)
    {
        cin >> a;
        if (a >= 0)
        {
            flag = 1;
        }
        if (flag != 1)
        {
            if (a > max1)
            {
                max1 = a;
            }
        }
        else
        {
            if (a > max)
            {
                max = a;
            }
        }
    }
    if (flag != 1)
    {
        cout << max1;
    }
    else
    {
        cout << max;
    }
}