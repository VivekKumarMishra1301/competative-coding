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
        int x, y, z, w;
        cin >> x >> y >> z >> w;
        unordered_map<int, int> meraMap;
        for (int i = x; i <= y; i++)
        {
            meraMap[i]++;
        }
        for (int i = z; i <= w; i++)
        {
            meraMap[i]++;
        }
        int count = 0;
        for (auto i : meraMap)
        {
            count++;
        }
        cout << count << endl;
    }
    return 0;
}
