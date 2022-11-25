#include <iostream>
using namespace std;

#include <unordered_map>
int lengthOfLongestSubsetWithZeroSum(int *arr, int n)
{
    // Write your code here
    unordered_map<int, int> meraMap;
    int sum = 0;
    int length = 1;
    for (int i = 0; i < n; i++)
    {
        sum = sum + arr[i];
        if (sum == 0)
        {
            length = i + 1;
            continue;
        }
        if (meraMap.find(sum) == meraMap.end())
        {
            meraMap[sum] = i;
        }
        else
        {
            int len = i - (meraMap[sum]);
            if (len > length)
            {
                length = len;
            }
        }
    }
    return length;
}

int main()
{
    int size;
    cin >> size;

    int *arr = new int[size];

    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }

    cout << lengthOfLongestSubsetWithZeroSum(arr, size);

    delete[] arr;
}