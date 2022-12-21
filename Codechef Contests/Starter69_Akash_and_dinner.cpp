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
        int x, y;
        cin >> x >> y;

        int bhojan[x];
        int milwan[x];
        unordered_map<int, int> meraMap;

        for (int i = 0; i < x; i++)
        {
            cin >> bhojan[i];
            meraMap[bhojan[i]]++;
        }
        for (int i = 0; i < x; i++)
        {
            cin >> milwan[i];
        }

        int count = 0;
        for (auto i : meraMap)
        {
            count++;
        }
        if (count < y)
        {
            cout << "-1" << endl;
            continue;
        }

        unordered_map<int, int> meal;
        for (int i = 0; i < x; i++)
        {
            if (meal.count(bhojan[i]) == 0)
            {
                meal[bhojan[i]] = milwan[i];
            }
            else
            {
                if (meal[bhojan[i]] > milwan[i])
                {
                    meal[bhojan[i]] = milwan[i];
                }
            }
        }

        vector<int> hold;
        for (auto i : meal)
        {
            hold.push_back(i.second);
        }
        sort(hold.begin(), hold.end());

        long long int mincount = 0;
        int z = 0;
        while (z < y)
        {
            mincount += hold[z];
            z++;
        }
        cout << mincount << endl;
    }
    return 0;
}
