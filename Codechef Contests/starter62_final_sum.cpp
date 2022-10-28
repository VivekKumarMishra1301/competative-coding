#include <iostream>
using namespace std;

int main()
{
    // your code goes here
    int t;
    cin >> t;
    while (t--)
    {
        int size, q;
        cin >> size >> q;
        int arr[size];
        int finalsum = 0;
        for (int i = 0; i < size; i++)
        {
            cin >> arr[i];
            finalsum = finalsum + arr[i];
        }
        while (q--)
        {
            int l, r;
            cin >> l >> r;
            int checkincreament = r - l + 1;
            if (checkincreament % 2 == 1)
            { // checking is increamen is more then decreament or not
                finalsum++;
            }
        }

        cout << finalsum << endl;
    }
    return 0;
}
