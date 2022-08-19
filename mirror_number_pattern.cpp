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
            int k = 1;
            int j = 1;
            while (k <= n - i)
            {
                cout << " ";
                k++;
            }
            while (j <= i)
            {
                cout << j;
                j = j + 1;
            }
            i = i + 1;
            cout << endl;
        }
    }
}
