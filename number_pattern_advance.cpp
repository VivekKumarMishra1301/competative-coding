#include <iostream>
using namespace std;

int main()
{
    /*  Read input as specified in the question.
     * Print output as specified in the question.
     */
    int n;
    cin >> n;
    int i = 1;
    if (n >= 0 && n <= 50)
    {
        while (i <= n)
        {
            int j = 1;
            while (j <= n - i)
            {
                cout << " ";
                j = j + 1;
            }
            int k = i;
            int l = 1;
            while (l <= i)
            {
                cout << k;
                k = k + 1;
                l = l + 1;
            }
            int m = k - 2;
            while (m >= i)
            {
                cout << m;
                m = m - 1;
            }
            i = i + 1;
            cout << endl;
        }
    }
}
