#include <iostream>
using namespace std;
int cards()
{
    int n, a[10] = {0}, pos, max = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> pos;
        a[pos - 1] = a[pos - 1] + 1;
    }

    for (int i = 0; i < 10; i++)
    {
        if (max < a[i])
            max = a[i];
    }
    cout << (n - max) << endl;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        cards();
    }

    return 0;
}