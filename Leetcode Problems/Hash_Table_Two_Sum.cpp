#include <iostream>
#include <vector>

using namespace std;

#include <bits/stdc++.h>
vector<pair<int, int>> twoSum(vector<int> &arr, int target, int n)
{
    // Write your code here.
    vector<pair<int, int>> hold;
    unordered_map<int, int> meraMap;
    for (auto i : arr)
    {
        meraMap[i]++;
    }

    for (int i = 0; i < arr.size(); i++)
    {
        if (meraMap.find(arr[i]) == meraMap.end())
        {
            continue;
        }
        if (meraMap.find(target - arr[i]) != meraMap.end())
        {
            if (target - arr[i] == arr[i] && meraMap[arr[i]] == 1)
            {
                continue;
            }
            hold.push_back({arr[i], target - arr[i]});
            meraMap[arr[i]]--;
            meraMap[target - arr[i]]--;
            if (meraMap[arr[i]] == 0)
            {
                meraMap.erase(arr[i]);
            }
            if (meraMap[target - arr[i]] == 0)
            {
                meraMap.erase(target - arr[i]);
            }
        }
    }
    if (hold.size() == 0)
    {
        hold.push_back({-1, -1});
    }
    return hold;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        int n, target;
        cin >> n >> target;
        vector<int> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }

        vector<pair<int, int>> ans = twoSum(v, target, n);
        for (auto i : ans)
        {
            if (i.first < i.second)
                cout << i.first << " " << i.second << "\n";
            else
                cout << i.second << " " << i.first << "\n";
        }
    }
}