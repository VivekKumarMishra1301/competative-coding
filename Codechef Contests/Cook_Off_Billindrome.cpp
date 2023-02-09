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
        string p;
        cin >> p;
        // 	    if (p == string(p.rbegin(), p.rend())) {
        //     // cout << input << " is a palindrome";
        //             cout<<-1<<endl;
        //             continue;
        // }
        map<char, int> meraMap;
        for (auto i : p)
        {
            meraMap[i]++;
        }

        bool flag = false;
        for (auto i : meraMap)
        {
            if (i.second > 1)
            {
                flag = true;
                break;
            }
        }
        if (flag)
        {
            cout << x - 2 << endl;
        }
        else
        {
            cout << -1 << endl;
        }
    }

    return 0;
}
