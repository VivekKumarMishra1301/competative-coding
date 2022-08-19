#include <iostream>
using namespace std;

int main()
{

    /*  Read input as specified in the question.
     * Print output as specified in the question.
     */
    int n;
    cin >> n;
    int i = 1, l = n / 2, m = 1;
    int n1 = (n + 1) / 2;
    if (n >= 1 && n <= 49)
    {
        for (int i = 1; i <= n1; i++)
        {
            for (int j = 1; j <= n1 - i; j++)
            {
                cout << " ";
            }
            for (int j = 1; j <= 2 * i - 1; j++)
            {
                cout << "*";
            }
            cout << endl;
        }
        for (int i = n1 - 1; i >= 1; i--)
        {
            for (int j = 1; j <= n1 - i; j++)
            {
                cout << " ";
            }
            for (int j = 1; j <= 2 * i - 1; j++)
            {
                cout << "*";
            }
            cout << endl;
        }
    }
}
