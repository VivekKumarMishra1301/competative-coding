#include <iostream>
using namespace std;

int main()
{

    // Write your code here
    int n;
    cin >> n;
    int i = 1;
    while (i <= n)
    {
        int j = 1;
        while (j <= n)
        {
            if (j <= n - i + 1)
            {
                cout << j;
                j++;
            }
            else
            {
                cout << "*";
                j++;
            }
        }
        int k = n;
        while (k >= 1)
        {
            int m = n - k + 1;
            if (k > n - i + 1)
            {
                cout << "*";
                k--;
            }
            else
            {
                cout << k;
                k--;
            }
        }

        cout << endl;
        i = i + 1;
    }
}
