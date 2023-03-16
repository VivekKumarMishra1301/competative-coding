#include <bits/stdc++.h>
using namespace std;
bool CheckSumPairs(int ar[], int n, int k, int m)
{
    /*Write your code here.
     *Don't write main().
     *Don't take input, it is passed as function argument.
     *Don't print output.
     *Taking input and printing output is handled automatically.
     */
    unordered_map<int, int> meraMap;
    for (int i = 0; i < n; i++)
    {
        meraMap[ar[i]]++;
    }

    int ele = ar[0];
    for (int i = 0; i < n; i++)
    {
        if (ar[i] > ele)
        {
            ele = ar[i];
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (meraMap.find(ar[i]) == meraMap.end())
        {
            continue;
        }
        int l = 0;
        bool flag = false;
        while (1)
        {
            // cout << l;
            int num = k * l + m - ar[i];
            if (num > ele)
            {
                break;
            }
            if (meraMap.find(num) != meraMap.end())
            {
                meraMap[num]--;
                meraMap[ar[i]]--;
                if (meraMap[ar[i]] == 0)
                {
                    meraMap.erase(ar[i]);
                }
                if (meraMap[num] == 0)
                {
                    meraMap.erase(num);
                }
                flag = true;
                break;
            }
            l++;
        }

        // cout << ar[i] << " ";
        if (!flag)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int k, m;
    cin >> k >> m;
    if (CheckSumPairs(arr, n, k, m))
        cout << "true";
    else
        cout << "false";
}
