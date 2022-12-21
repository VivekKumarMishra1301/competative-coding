#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main()
{
    // your code goes here
    int t;
    cin >> t;
    while (t--)
    {
        int x;
        cin >> x;
        int possible[x];
        int sum = 0;
        int sum2 = 0;
        // bool flag=false;
        for (int i = 0; i < x; i++)
        {
            cin >> possible[i];
        }
        sort(possible, possible + x);
        int count = 0;
        bool flag = false;
        for (int i = 0; i < x; i++)
        {
            if (possible[i] < (i + 1))
            {
                count = count + (i + 1) - possible[i];
            }
            else if (possible[i] == (i + 1))
            {
                count = count;
            }
            else
            {
                flag = true;
                break;
            }
        }
        if (flag)
        {
            cout << "-1" << endl;
            continue;
        }
        else
        {
            cout << count << endl;
        }
    }
    return 0;
}
