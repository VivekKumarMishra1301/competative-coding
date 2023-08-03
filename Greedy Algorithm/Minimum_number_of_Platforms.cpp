#include <bits/stdc++.h>
int calculateMinPatforms(int at[], int dt[], int n)
{
    // Write your code here.
    sort(at, at + n);
    sort(dt, dt + n);
    int ai = 1;
    int di = 0;
    int cp = 1;
    int mp = 1;
    while (ai < n and di < n)
    {
        if (dt[di] >= at[ai])
        {
            cp++;
            ai++;
        }
        else
        {
            cp--;
            di++;
        }
        mp = max(mp, cp);
    }
    return mp;
}