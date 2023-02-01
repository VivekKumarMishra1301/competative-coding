#include <iostream>
using namespace std;

int main()
{
    // your code goes here
    int t;
    cin >> t;
    while (t--)
    {
        double p, q, r;
        cin >> p >> q >> r;
        double s1 = 400 / p;
        double s2 = 400 / q;
        double s3 = 400 / r;
        if (s1 > s2 && s1 > s3)
        {
            cout << "ALICE" << endl;
        }
        else if (s2 > s1 && s2 > s3)
        {
            cout << "BOB" << endl;
        }
        else if (s3 > s2 && s3 > s1)
        {
            cout << "CHARLIE" << endl;
        }
    }
    return 0;
}
