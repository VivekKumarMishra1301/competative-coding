#include <bits/stdc++.h>
bool cmp(const pair<int, int> &a, const pair<int, int> &b)
{
    return a.second > b.second;
}
bool checkOverlappingIntervals(long *start, long *end, int n)
{

    // Check all posible combinations.
    vector<pair<long, long>> hold;
    for (int i = 0; i < n; i++)
    {
        hold.push_back({start[i], end[i]});
    }
    sort(hold.begin(), hold.end(), cmp);
    // for(int i=0;i<hold.size();i++){
    //   cout<<hold[i].first<<hold[i].second<<endl;
    // }
    for (int i = 1; i < n; i++)
    {
        int st = hold[i - 1].first;
        int en = hold[i - 1].second;
        int ns = hold[i].first;
        int ne = hold[i].second;
        if ((ns > st && ns < en) || (ne > st && ne < en))
        {
            return true;
        }
    }
    return false;
}