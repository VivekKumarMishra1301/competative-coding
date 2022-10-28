#include <iostream>
using namespace std;
#include <algorithm>
int maximumProfit(int budget[], int n)
{
    // Write your code here
    sort(budget, budget + n);
    int max = 0;
    for (int i = 0; i < n; i++)
    {
        int profit = budget[i] * (n - i);
        if (profit > max)
        {
            max = profit;
        }
    }
    return max;
}

int main()
{
    int n, *input, i, *cost;
    cin >> n;
    input = new int[n];
    for (i = 0; i < n; i++)
        cin >> input[i];

    cout << maximumProfit(input, n) << endl;
}
