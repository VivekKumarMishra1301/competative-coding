#include <iostream>
using namespace std;

int main()
{
    // Write your code here
    int n;
    cin >> n;
    int num = 0, count = 0, mul = 1;
    if (n >= 0 && n <= 1000000000)
    {
        while (n != 0)
        {
            mul = 1;
            int q = n % 10;
            if (count == 0)
            {
                num = q;
                count++;
            }
            else
            {

                for (int i = 1; i <= count; i++)
                {
                    mul = mul * 2;
                }
                num = num + mul * q;
                count++;
            }
            n = n / 10;
        }
        cout << num;
    }
}
