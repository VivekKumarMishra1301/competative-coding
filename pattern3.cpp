#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int k = 1, i = 0, l = 1;

    if (n >= 0 && n <= 50)
    {

        while (i < n)
        {
            k = 1;
            int j = 1;
            while (j < n - i)
            {
                cout << " ";
                j = j + 1;
            }
            l = 1;
            while (l <= 2 * i + 1)
            {
                cout << "*";
                l = l + 1;
            }
            i = i + 1;
            cout << endl;
        }
    }

    /*  Read input as specified in the question.
     * Print output as specified in the question.
     */
}
