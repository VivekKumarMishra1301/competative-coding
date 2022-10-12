#include <iostream>
using namespace std;
int fib(unsigned long long int n)
{
    if (n == 0 || n == 1)
    {
        return n;
    }
    return fib(n - 1) + fib(n - 2);
}
int main()
{
    unsigned long long int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cout << i << "  " << fib(i) << endl;
    }
}