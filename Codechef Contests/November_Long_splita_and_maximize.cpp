#include <iostream>
using namespace std;

int main()
{
    // your code goes here
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        long long int split[n];
        long long int maxSum = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> split[i];
            maxSum = maxSum + split[i];
            maxSum = maxSum % 998244353;
        }

        maxSum = maxSum * (maxSum - 1);
        maxSum = maxSum % 998244353;
        cout << maxSum << endl;
    }
    return 0;
}
