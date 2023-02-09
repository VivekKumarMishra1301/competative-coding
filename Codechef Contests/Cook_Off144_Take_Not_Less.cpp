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
        int x;
        cin >> x;
        //  priority_queue <int> pq;
        vector<int> hold;
        for (int i = 0; i < x; i++)
        {
            int k;
            cin >> k;
            hold.push_back(k);
            // pq.push(k);
        }
        sort(hold.begin(), hold.end());
        map<int, int> meraMap;

        char w = 'm';
        for (int i = hold.size() - 1; i >= 0; i--)
        {
            meraMap[hold[i]]++;
        }
        // int top=pq.top();
        // pq.pop();
        // while(!pq.empty()){
        //     if(pq.top()==top){
        //         w='z';
        //     }else{
        //         break;
        //     }
        //     pq.pop();
        // }
        w = 'z';

        for (auto i : meraMap)
        {
            if (i.second % 2 != 0)
            {
                w = 'm';
            }
        }

        if (w == 'z')
        {
            cout << "Zenyk" << endl;
        }
        else
        {
            cout << "Marichka" << endl;
        }
    }

    return 0;
}
