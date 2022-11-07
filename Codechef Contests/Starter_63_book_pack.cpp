#include <iostream>
using namespace std;

int main()
{
    // your code goes here
    int t;
    cin >> t;
    while (t--)
    {
        int sh, b, box;
        cin >> sh >> b >> box;
        // if(b<=box){
        //     cout<<sh<<endl;
        //     continue;
        // }
        if (b < box)
        {
            cout << sh << endl;
            continue;
        }
        if (b % box != 0)
        {

            int c = b / box + 1;
            cout << sh * c << endl;
        }
        else
        {
            cout << sh * (b / box) << endl;
        }
    }
    return 0;
}
