
#include <unordered_map>
vector<int> longestConsecutiveIncreasingSequence(int *arr, int n)
{
    // Your Code goes here
    vector<int> hold;
    unordered_map<int, int> meraMap;
    for (int i = 0; i < n; i++)
    {
        meraMap[arr[i]] = i;
    }
    int max = 0;
    int st = 0;
    int end = 0;
    for (int i = 0; i < n; i++)
    {
        int search = arr[i];
        int count = 1;
        while (meraMap.find(search) != meraMap.end())
        {
            count++;
            search++;
        }

        if (count > max)
        {
            max = count;
            st = arr[i];
            end = search - 1;
            count = 1;
        }
    }
    if (st != end)
    {
        hold.push_back(st);
        hold.push_back(end);
    }
    else
    {
        hold.push_back(st);
    }
    return hold;
}