#include <bits/stdc++.h>
using namespace std;
int main()
{

    // write your code here
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int bit;
        cin >> bit;
        if ((n & (1 << bit)) != 0)
            cout << (n ^ (1 << bit)) << endl;
        else
        {
            cout << n << endl;
        }
    }
    return 0;
}

// SECOND approach
#include <bits/stdc++.h>
using namespace std;
int main()
{

    // write your code here
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int bit;
        cin >> bit;
        cout << (n & (~(1 << bit)));
    }
    return 0;
}