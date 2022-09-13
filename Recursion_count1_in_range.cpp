#include <iostream>
using namespace std;
int countDigitOne(int n)
{
    if (n == 0)
    {
        return 0;
    }
    int count = 0;
    int t = n;
    while (t > 0)
    {
        if (t % 10 == 1)
        {
            count++;
        }
        t = t / 10;
    }
    return count + countDigitOne(n - 1);
}
int main()
{
    int n;
    cin >> n;
    cout << countDigitOne(n);
}