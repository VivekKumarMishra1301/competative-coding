#include <iostream>
using namespace std;

int main()
{

    /* Read input as specified in the question.
     * Print output as specified in the question.

     */
    int n;
    cin >> n;
    bool prime = true;
    if (n >= 1 && n <= 100)
    {
        for (int i = 2; i <= n; i++)
        {
            if (i == 2)
            {
                cout << i << endl;
            }
            else
            {
                for (int j = 2; j < i; j++)
                {
                    if (i % j == 0)
                    {

                        prime = false;
                        break;
                    }
                    else
                    {
                        prime = true;
                    }
                }
                if (prime)
                {
                    cout << i << endl;
                }
            }
        }
    }
}
