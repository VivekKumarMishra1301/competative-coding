#include <iostream>
#include <vector>
using namespace std;

#include <queue>
int buyTicket(int *arr, int n, int k)
{
    // Write your code here
    int temp = arr[k];
    priority_queue<int> pq;
    queue<int> q;
    for (int i = 0; i < n; i++)
    {
        pq.push(arr[i]);
        q.push(i);
    }

    int count = 0;
    while (!pq.empty())
    {
        if (arr[q.front()] == pq.top())
        {
            pq.pop();
            count++;
            if (q.front() == k)
            {
                break;
            }
            q.pop();
        }
        else
        {
            int temp = q.front();
            q.pop();
            q.push(temp);
        }
    }
    return count;
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

    cout << buyTicket(arr, n, k);

    delete[] arr;
}