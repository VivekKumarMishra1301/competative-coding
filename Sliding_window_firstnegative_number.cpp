#include <cmath>
#include <cstdio>
#include <vector>
#include <deque>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int arr[10000];
    int n, k, ans;
    deque<int> aux;
    cin >> n;
    for (int i = 0; i < n; i++)
    {

        cin >> arr[i];
    }
    cin >> k;
    for (int i = 0; i < k; i++)
    {
        if (arr[i] < 0)
        {
            aux.push_back(i);
        }
    }
    for (int i = k; i < n; i++)
    {
        if (!aux.empty())
        {
            cout << arr[aux.front()] << " ";
        }
        else
        {
            cout << "0"
                 << " ";
        }
        while ((!aux.empty()) && aux.front() < (i - k + 1))
        {
            aux.pop_front();
        }
        if (arr[i] < 0)
        {
            aux.push_back(i);
        }
        if (!aux.empty())
            cout << arr[aux.front()] << " ";
        else
            cout << "0"
                 << " ";
    }
    return 0;
}