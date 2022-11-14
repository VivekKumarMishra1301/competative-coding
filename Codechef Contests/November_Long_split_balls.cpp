#include <iostream>
using namespace std;

int main()
{
    // your code goes here
    int t;
    cin >> t;
    long long int factdp[1000001];
    factdp[0] = 1;
    factdp[1] = 1;
    for (int i = 2; i < 1000001; i++)
    {
        factdp[i] = i * factdp[i - 1];
        factdp[i] = factdp[i] % 1000000007;
    }

    while (t--)
    {
        int n;
        cin >> n;
        long long int balls[n];
        long long maxballs = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> balls[i];
            maxballs = maxballs + factdp[balls[i]];
            maxballs = maxballs % 1000000007;
        }
        cout << maxballs << endl;
    }

    return 0;
}
