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
        int goru[x];
        unordered_map<int, int> meraMap;
        for (int i = 0; i < x; i++)
        {
            cin >> goru[i];
            meraMap[goru[i]]++;
        }

        bool flag = true;
        for (auto i : meraMap)
        {
            if ((i.second) % 2 != 0)
            {
                flag = false;
                break;
            }
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
