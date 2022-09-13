#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n, k;
    int arr[1000];
    cin >> n;
    int dp[n];
    int max = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        dp[i] = 0;
    }
    cin >> k;
    for (int i = 0; i < n; i++)
    {

        for (int j = i; j < n; j++)
        {
            if (j == i)
            {
                dp[j - 1] = 0;
            }
            if ((dp[j - 1] + arr[j]) == k)
            {
                int max2 = j - i + 1;
                if (max2 > max)
                {
                    max = max2;
                }
                break;
            }
            dp[j] = arr[j] + dp[j - 1];
        }
    }

    cout << max;
    return 0;
}
