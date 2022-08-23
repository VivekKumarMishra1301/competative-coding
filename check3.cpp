#include <iostream>
#include <math.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int ans = 0;
    int i = 0;
    while (n != 0)
    {
        int lastdigit = n & 1;
        // cout << lastdigit << endl;
        ans = (lastdigit * pow(10, i)) + ans; // this is for reverse the bit and store it into ans
        cout << ans << endl;
        n = n >> 1;

        i++;
    }
    cout << ans;
}