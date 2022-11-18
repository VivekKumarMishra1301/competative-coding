#include <iostream>
using namespace std;

#include <unordered_map>
int highestFrequency(int arr[], int n)
{
    // Write your code here
    if (n == 0)
    {
        return -1;
    }
    unordered_map<int, int> meraMap;
    for (int i = 0; i < n; i++)
    {
        meraMap[arr[i]]++;
    }

    int max = 0;
    int value = 0;
    for (int i = 0; i < n; i++)
    {
        if (meraMap[arr[i]] > value)
        {
            max = arr[i];
            value = meraMap[arr[i]];
        }
    }
    return max;
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

    cout << highestFrequency(arr, n);

    delete[] arr;
}