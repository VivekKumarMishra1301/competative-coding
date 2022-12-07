#include <iostream>
using namespace std;

int main()
{
    // your code goes here
    int t;
    cin >> t;
    while (t--)
    {
        int p, q, r;
        cin >> p >> q >> r;
        int arr[p];
        int sum = 0;
        int cost = 0;
        for (int i = 0; i < p; i++)
        {
            cin >> arr[i];
            int diff = q - arr[i];
            if (diff > r)
            {
                sum = sum + q;
                cost += r;
            }
            else
            {
                sum = sum + arr[i];
            }
        }

        cout << sum - cost << endl;
    }
    return 0;
}
