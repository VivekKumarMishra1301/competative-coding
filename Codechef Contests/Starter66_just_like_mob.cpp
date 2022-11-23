#include <iostream>
using namespace std;

int main()
{
    // your code goes here
    int t;
    cin >> t;
    while (t--)
    {
        int x, y, z;
        long long int w;
        cin >> x >> y >> z >> w;
        int k = y + x;
        int days = x * (z - 1) + k;

        int day = days;
        int rem = w / days;
        int remn = w % days;
        if (remn != 0)
        {

            days = day * rem + day;
        }
        else
        {
            days = day * rem;
        }

        int min = days - k;
        if (w > min && w <= days)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
    return 0;
}
