#include <bits/stdc++.h>
int minSwap(int n, int m, int k, string &s, vector<char> &arr)
{
    // Write your code here

    map<char, int> mp;
    for (auto i : arr)
    {
        mp[i]++;
    }

    vector<vector<int>> fr(k, vector<int>(26, 0));
    int i = 0;
    while (i < k)
    {
        int j = i;
        while (j < n)
        {
            fr[i][s[j] - 'a']++;
            j += k;
        }
        i++;
    }

    int sp = 0;
    for (int i = 0; i < k; i++)
    {
        int maxi = 0;
        int s = 0;
        for (int j = 0; j < 26; j++)
        {
            if (mp.find(j + 'a') != mp.end() && fr[i][j] > maxi)
            {
                maxi = fr[i][j];
            }
            s += fr[i][j];
        }
        sp += (s - maxi);
    }

    return sp;
}