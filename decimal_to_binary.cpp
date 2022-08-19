#include <iostream>
using namespace std;

int main()
{
    // Write your code here
    int n;
    cin >> n;
    int long num = 0, place_value = 1, mul = 1;
    if (n >= 0 && n <= 100000)
    {
        while (n != 0)
        {
            int rem = n % 2;
            num = num + rem * place_value;
            place_value = place_value * 10;
            n = n / 2;
        }
        cout << num;
    }
}
