#include <iostream>
#include <vector>
using namespace std;
#include <queue>
vector<int> kLargest(int arr[], int n, int k)
{

    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Return output and don't print it.
     * Taking input and printing output is handled automatically.
     */

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
    return hold;
}

int main()
{

    int size;
    cin >> size;
    int *input = new int[1 + size];

    for (int i = 0; i < size; i++)
        cin >> input[i];

    int k;
    cin >> k;

    vector<int> output = kLargest(input, size, k);
    for (int i = 0; i < output.size(); i++)
        cout << output[i] << endl;

    return 0;
}