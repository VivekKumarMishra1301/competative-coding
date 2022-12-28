#include <iostream>
using namespace std;

int main()
{
    // your code goes here
    int t;
    cin >> t;
    while (t--)
    {
        int x;
        cin >> x;
        int chat1[x];
        int chat2[x];
        for (int i = 0; i < x; i++)
        {
            cin >> chat1[i];
        }
        for (int i = 0; i < x; i++)
        {
            cin >> chat2[i];
        }

        int pagalchodi = 0;
        int max = 0;
        for (int i = 0; i < x; i++)
        {
            if (chat1[i] != 0 && chat2[i] != 0)
            {
                pagalchodi++;
            }
            else
            {
                if (pagalchodi > max)
                {
                    max = pagalchodi;
                }
                pagalchodi = 0;
            }
        }

        if (pagalchodi > max)
        {
            max = pagalchodi;
        }

        cout << max << endl;
    }
    return 0;
}
