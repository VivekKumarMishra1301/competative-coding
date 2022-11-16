#include <iostream>
#include <vector>
using namespace std;

#include <queue>

int kthLargest(int *arr, int n, int k)
{
    // Write your code here

    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < k; i++)
    {
        pq.push(arr[i]);
    }

    for (int i = k; i < n; i++)
    {
        int top = pq.top();
        if (top < arr[i])
        {
            pq.pop();
            pq.push(arr[i]);
        }
    }
    vector<int> hold;
    while (!pq.empty())
    {
        hold.push_back(pq.top());
        pq.pop();
    }
    return hold[0];
}

int main()
{
    int n;
    cin >> n;

    int *arr = new int[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int k;
    cin >> k;

    cout << kthLargest(arr, n, k);

    delete[] arr;
}