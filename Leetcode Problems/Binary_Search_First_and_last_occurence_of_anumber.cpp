int findleft(vector<int> &arr, int n, int x)
{
    int st = 0;
    int en = n - 1;
    while (st <= en)
    {
        int mid = (st + en) / 2;
        if (arr[mid] == x)
        {
            if (mid - 1 >= 0 && arr[mid - 1] == x)
            {
                en = mid - 1;
            }
            else
            {
                return mid;
            }
        }
        else if (arr[mid] < x)
        {
            st = mid + 1;
        }
        else
        {
            en = mid - 1;
        }
    }
    return -1;
}

int findright(vector<int> &arr, int n, int x)
{
    int st = 0;
    int en = n - 1;
    while (st <= en)
    {
        int mid = (st + en) / 2;
        if (arr[mid] == x)
        {
            if (mid + 1 <= n && arr[mid + 1] == x)
            {
                st = mid + 1;
            }
            else
            {
                return mid;
            }
        }
        else if (arr[mid] < x)
        {
            st = mid + 1;
        }
        else
        {
            en = mid - 1;
        }
    }
    return -1;
}

pair<int, int> findFirstLastPosition(vector<int> &arr, int n, int x)
{
    // Write your code here.
    pair<int, int> hold;
    hold.first = findleft(arr, n, x);
    hold.second = findright(arr, n, x);
    return hold;
}

// 2nd approach
#include <bits/stdc++.h>
pair<int, int> findFirstLastPosition(vector<int> &arr, int n, int x)
{
    // Write your code here.
    pair<int, int> hold;
    int left = lower_bound(arr.begin(), arr.end(), x) - arr.begin();
    int right = upper_bound(arr.begin(), arr.end(), x) - arr.begin();
    if (left >= n)
    {
        hold.first = -1;
        hold.second = -1;
        return hold;
    }

    if (arr[left] == x)
    {
        hold.first = left;
        hold.second = right - 1;
        return hold;
    }
    hold.first = -1;
    hold.second = -1;
    return hold;
}
