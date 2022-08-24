#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int maxi(int arr[], int st, int end)
{
    int maxm = arr[st];
    for (int i = st; i < end; i++)
    {
        if (arr[i] > maxm)
        {
            maxm = arr[i];
        }
    }
    return maxm;
}
void submax(int arr[], int len, int sub, int max, int ind)
{
    if (sub > len)
    {

        return;
    }
    max = maxi(arr, ind, sub);
    cout << max << " ";
    submax(arr, len, sub + 1, max, ind + 1);
}

int main()
{
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n, ind = 0, max = 0, subsize, arr[1000];
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cin >> subsize;
    submax(arr, n, subsize, max, ind);
    return 0;
}
