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
        vector<int> hold1;
        vector<int> hold2;
        for (int i = 0; i < 2 * x; i++)
        {
            int a;
            cin >> a;
            hold1.push_back(a);
            hold2.push_back(a);
        }
        sort(hold2.begin(), hold2.end());
        int s = hold2[x - 1];
        int ind = x;
        long hold3 = 0;
        for (int i = 0; i < ind; i++)
        {
            if (hold1[i] > s)
            {
                hold3 += ind - i;
                ind++;
            }
        }
        cout << hold3 << endl;
    }
    return 0;
}
