#include <iostream>
using namespace std;

int main()
{
    int n, num, sum1 = 0, sum2 = 0;
    cin >> n;
    if (n >= 0 && n <= 100000000)
    {
        while (n != 0)
        {
            num = n % 10;
            if (num % 2 == 0)
            {
                sum1 = sum1 + num;
            }
            else
            {
                sum2 = sum2 + num;
            }
            n = n / 10;
        }
        cout << sum1 << " " << sum2;
    }
}
