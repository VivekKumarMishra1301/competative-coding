#include <iostream>
using namespace std;

int main()
{
    // Write your code here
    int n;
    cin >> n;
    int sum = 0, rev = 0, count = 0;
    if (n >= 0 && n < 100000000)
    {
        while (n != 0)
        {
            int q = n % 10;
            // if (q != 0)
            //{
            rev = rev * 10 + q;
            // }
            // else
            /*{
            count = 1;
            count = count * 10;
            */
            n = n / 10;
        }
        cout << rev;
    }
}
