#include <bits/stdc++.h>

bool cmp(pair<int, pair<int, int>> p1, pair<int, pair<int, int>> p2)
{
    if (((double)p1.second.first / (double)p1.second.second) < ((double)p2.second.first / (double)p2.second.second))
    {
        return true;
    }
    else if (((double)p1.second.first / (double)p1.second.second) > ((double)p2.second.first / (double)p2.second.second))
    {
        return false;
    }
    else
    {
        if (p1.first < p2.first)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
}

vector<int> minLoss(int n, vector<int> &time, vector<int> &loss)
{

    // Write your code here.
    vector<pair<int, pair<int, int>>> arr;
    for (int i = 0; i < time.size(); i++)
    {
        pair<int, pair<int, int>> p;
        p.first = i;
        p.second.first = time[i];
        p.second.second = loss[i];
        arr.push_back(p);
    }
    sort(arr.begin(), arr.end(), cmp);
    vector<int> hold;
    for (int i = 0; i < arr.size(); i++)
    {
        hold.push_back(arr[i].first + 1);
    }
    return hold;
}