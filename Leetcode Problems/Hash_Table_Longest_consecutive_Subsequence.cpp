#include <bits/stdc++.h>
vector<int> longestConsecutiveIncreasingSequence(int *nums, int n)
{
    // Your Code goes here

    vector<int> ans;

    if (n == 0)
    {
        return ans;
    }
    map<int, int> teraMap;
    map<int, int> meraMap;

    for (int i = 0; i < n; i++)
    {
        meraMap[nums[i]]++;
        teraMap[nums[i]] = i;
    }

    int hold = 1;
    bool flag = true;
    int cnt = 1;
    int st;
    int en;
    int fst;
    int fen;
    for (auto i : meraMap)
    {
        if (flag)
        {
            st = i.first;
            en = i.first;
            fst = st;
            fen = en;
            flag = false;
            continue;
        }
        int k = i.first - 1;
        if (meraMap.find(k) != meraMap.end())
        {
            en = i.first;
            cnt++;
        }
        else
        {
            if (hold < cnt)
            {
                fst = st;
                fen = en;
            }
            if (hold == cnt)
            {
                if (teraMap[st] < teraMap[fst])
                {
                    fst = st;
                    fen = en;
                }
            }

            hold = max(hold, cnt);
            st = i.first;
            en = i.first;
            cnt = 1;
        }
    }
    if (hold < cnt)
    {
        fst = st;
        fen = en;
    }
    if (hold == cnt)
    {
        if (teraMap[st] < teraMap[fst])
        {
            fst = st;
            fen = en;
        }
    }
    hold = max(hold, cnt);

    ans.push_back(fst);
    ans.push_back(fen);
    if (fst == fen)
        ans.pop_back();

    return ans;
}