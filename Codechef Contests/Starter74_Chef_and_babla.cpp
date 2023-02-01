#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int kitna;
    cin >> kitna;
    while (kitna--)
    {
        int n;
        cin >> n;
        vector<long long> holdd(n);
        long long temp = 1e9 + 1;
        long long flag = -1e9 - 1;

        for (int i = 0; i < n; i++)
        {
            cin >> holdd[i];
            if (holdd[i] >= 0 && holdd[i] < temp)
            {
                temp = holdd[i];
            }
            if (holdd[i] < 0 && holdd[i] > flag)
            {
                flag = holdd[i];
            }
        }
        long long ans = min(temp, abs(flag));
        cout << ans - 1 << endl;
    }
}