#include <iostream>
using namespace std;

int main()
{
    // your code goes here
    int t;
    cin >> t;
    while (t--)
    {
        int k, l;
        cin >> k >> l;
        int fresh[k];
        int price[l];
        for (int i = 0; i < k; i++)
        {
            cin >> fresh[i];
        }
        int sum = 0;
        for (int i = 0; i < k; i++)
        {
            cin >> price[i];
            if (fresh[i] >= l)
            {
                sum += price[i];
            }
        }
        cout << sum << endl;
    }
    return 0;
}
