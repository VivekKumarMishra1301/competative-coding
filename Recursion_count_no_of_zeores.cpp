#include <iostream>
int countZeros(int n)
{
    // Write your code here
    if (n / 10 == 0)
    {
        if (n == 0)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    if (n == 0)
    {
        return 1;
    }
    if (n % 10 == 0)
    {
        return 1 + countZeros(n / 10);
    }
    else
    {
        return countZeros(n / 10);
    }
}

using namespace std;

int main()
{
    int n;
    cin >> n;
    cout << countZeros(n) << endl;
}
