#include <iostream>
using namespace std;

#include <unordered_map>
int pairSum(int *arr, int n)
{
    // Write your code here
    unordered_map<int, int> hold;
    for (int i = 0; i < n; i++)
    {
        hold[arr[i]]++;
    }
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 0 && hold[arr[i]] > 0)
        {
            count += (hold[arr[i]] * (hold[arr[i]] - 1)) / 2;
            hold[arr[i]] = 0;
        }
        else if (hold[-arr[i]] > 0)
        {
            int a = hold[arr[i]] * hold[-arr[i]];
            count += a;
            hold[-arr[i]] = 0;
            hold[arr[i]] = 0;
        }
    }
    return count;
}

int main()
{
    int n;
    cin >> n;

    int *arr = new int[n];

    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }

    cout << pairSum(arr, n);

    delete[] arr;
}