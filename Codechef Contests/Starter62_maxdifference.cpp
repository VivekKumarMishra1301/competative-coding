#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    // your code goes here
    int t;
    cin >> t;
    while (t--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        cout << max(max(a, b), c) - min(min(a, b), c) << endl;
    }
    return 0;
}
