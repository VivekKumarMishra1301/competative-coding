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
        int k;
        cin >> k;
        string bin;
        cin >> bin;
        int count = 0;
        int res = 0;
        for (int i = 1; i < k; i++)
        {
            if (bin[i] == '1' && bin[i - 1] == '1')
            {
                res = 1;
                break;
            }
        }
        if (res)
        {
            cout << "1" << endl;
            continue;
        }
        int flag = 0;
        vector<int> hold;
        for (int i = 0; i < k; i++)
        {
            if (flag == 1 && bin[i] != '1')
            {
                count++;
            }
            else if (flag == 1 && bin[i] == '1')
            {
                // flag=0;
                hold.push_back(count);
                count = 0;
            }
            else if (flag != 1 && bin[i] == '1')
            {
                flag = 1;
            }
        }
        int res1 = 2;
        for (int i = 0; i < hold.size(); i++)
        {
            if (hold[i] % 2 == 0)
            {
                res1 = 1;
                break;
            }
        }
        cout << res1 << endl;
    }

    return 0;
}
