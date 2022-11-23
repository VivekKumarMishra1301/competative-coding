#include <iostream>
using namespace std;

int main()
{
    // your code goes here
    int t;
    cin >> t;
    while (t--)
    {
        long long int x;
        int y;
        int z;
        cin >> x >> y >> z;
        int count = 0;
        int sum = 0;
        while (x > 1)
        {
            sum = sum + y;
            count++;
            x /= 2;
        }
        sum = sum + (z * (count - 1));
        cout << sum << endl;
    }
    return 0;
}
