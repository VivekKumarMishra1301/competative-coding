#include <bits/stdc++.h>
using namespace std;

bool cmpY(const pair<int, int> &a, const pair<int, int> &b)
{
    return a.second < b.second;
}
long dist(pair<int, int> p, pair<int, int> q)
{
    int x1 = p.first;
    int y1 = p.second;
    int x2 = q.first;
    int y2 = q.second;

    return pow(x1 - x2, 2) + pow(y1 - y2, 2);
}

long bruteforce(vector<pair<int, int>> pt, int n)
{

    long mini = LONG_MAX;
    for (int i = 0; i < n; ++i)
    {
        for (int j = i + 1; j < n; ++j)
        {
            if (dist(pt[i], pt[j]) < mini)
                mini = dist(pt[i], pt[j]);
        }
    }

    return mini;
}

long stripClose(vector<pair<int, int>> st, long d)
{
    long minimum = d;
    sort(st.begin(), st.end(), cmpY);
    for (int i = 0; i < st.size(); ++i)
    {
        for (int j = i + 1; j < st.size(); ++j)
        {
            long tmp = (long)st[j].second - st[i].second;
            minimum = min(minimum, dist(st[i], st[j]));
        }
    }

    return minimum;
}

long findClose(vector<pair<int, int>> pt, int n)
{
    if (n <= 3)
    {
        return bruteforce(pt, n);
    }

    int mid = n / 2;

    pair<int, int> midPoint = pt[mid];
    // from here we will create 2 parts of the vector ptLeft and ptRIght represents the same
    int indexLeft = 0, indexRight = 0;

    vector<pair<int, int>> ptLeft(mid + 1);
    vector<pair<int, int>> ptRight(n - mid - 1);
    for (int i = 0; i < n; i++)
    {
        if (i < ptLeft.size())
            ptLeft[indexLeft++] = pt[i];
        else
            ptRight[indexRight++] = pt[i];
    }

    long dl = findClose(ptLeft, mid + 1);
    long dr = findClose(ptRight, n - mid - 1);

    long d;
    if (dl < dr)
    {
        d = dl;
    }
    else
    {
        d = dr;
    }
    vector<pair<int, int>> strip;

    for (int i = 0; i < n; i++)
    {
        long tmp = abs((long)pt[i].first - midPoint.first);
        if (tmp < d)
        {
            strip.push_back(pt[i]);
        }
    }

    return min(d, stripClose(strip, d));
}

long closestPair(pair<int, int> *coordinates, int n)
{

    vector<pair<int, int>> points(n);
    for (int i = 0; i < n; i++)
    {
        points[i] = coordinates[i];
    }
    sort(points.begin(), points.end());

    return findClose(points, n);
}