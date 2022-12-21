#include <iostream>
using namespace std;

int main()
{
    // your code goes here
    int t;
    cin >> t;
    while (t--)
    {
        int k;
        cin >> k;
        string bin1, bin2;
        cin >> bin1 >> bin2;
        int ones1 = 0;
        int ones2 = 0;
        for (int i = 0; i < k; i++)
        {
            if (bin1[i] == '1')
            {
                ones1++;
            }
            if (bin2[i] == '1')
            {
                ones2++;
            }
        }
        if (ones1 != ones2)
        {
            cout << "NO" << endl;
        }
        else
        {
            cout << "YES" << endl;
        }
    }
    return 0;
}
