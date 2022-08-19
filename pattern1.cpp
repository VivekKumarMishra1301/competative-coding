#include <iostream>
using namespace std;

int main()
{
    int n, i = 1;
    cin >> n;
    int val = 1;
    int k = 1;
    while (i <= n)
    {
        k = 1;
        while (k <= n - i)
        {
            cout << " ";
            k = k + 1;
        }

        int j = 1;
        val = i;
        while (j <= i)
        {

            cout << val;
            val = val + 1;
            j = j + 1;
        }
        i = i + 1;
        cout << endl;
    }
    /*  Read input as specified in the question.
     * Print output as specified in the question.
     */
}
