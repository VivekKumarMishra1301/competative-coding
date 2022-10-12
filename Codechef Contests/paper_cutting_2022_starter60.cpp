#include <iostream>
using namespace std;

int main()
{
    // your code goes here
    int t;
    cin >> t;
    while (t--)
    {
        int lsq;
        int smq;
        cin >> lsq >> smq;
        int length = 0;
        int sq1 = 0;
        int breadth = 0;
        int sq2 = 0;
        while ((length + smq) <= lsq && (breadth + smq) <= lsq)
        {
            length = length + smq;
            breadth = breadth + smq;
            sq1++;
            sq2++;
        }
        cout << sq1 * sq2 << endl;
    }
    return 0;
}
