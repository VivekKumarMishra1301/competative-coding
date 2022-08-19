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
    if (n >= 0 && n <= 13)
    {

        while (i <= n)
        {
            char a = 'A' + i - 1;
            int j = 1;
            while (j <= i)
            {
                cout << a;
                a = a + 1;
                j = j + 1;
            }
            i = i + 1;
            cout << endl;
        }
    }
}
