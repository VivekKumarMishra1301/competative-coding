#include <iostream>
int sumOfDigits(int n)
{
    // Write your code here
    if (n == 0)
    {
        return 0;
    }
    int sum = n % 10 + sumOfDigits(n / 10);
    return sum;
}

using namespace std;

int main()
{
    int n;
    cin >> n;
    cout << sumOfDigits(n) << endl;
}
