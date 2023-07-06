#include <bits/stdc++.h>
using namespace std;

int main()
{
    // your code goes here
    long n;
    cin >> n;
    vector<long> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    long curr = 0;
    long cst = 0;
    while (curr < (n - 1))
    {
        long next = curr + 1;
        while (next < (n - 1))
        {
            if ((abs(arr[curr]) > abs(arr[next])) || ((abs(arr[curr]) == abs(arr[next])) && (arr[curr] > 0)))
            {
                break;
            }
            else
                next++;
        }
        cst += (next - curr) * arr[curr] + (next * next - curr * curr) * arr[curr] * arr[curr];
        curr = next;
    }
    cout << cst;

    return 0;
}
