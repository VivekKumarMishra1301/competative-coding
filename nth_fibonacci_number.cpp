#include <iostream>
using namespace std;

int main()
{

    // Write your code here.
    int n;
    cin >> n;
    int fib, fib1, fib2;
    if (n >= 1 && n <= 10000)
    {
        for (int i = 1; i <= n; i++)
        {
            if (i == 1)
            {
                fib = 1;
            }
            else if (i == 2)
            {
                fib1 = 1;
                fib2 = 1;
                fib = fib2;
            }
            else
            {
                fib = fib1 + fib2;
                fib1 = fib2;
                fib2 = fib;
            }
        }
        cout << fib;
    }
}
