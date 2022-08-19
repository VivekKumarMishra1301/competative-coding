#include <iostream>
using namespace std;

int main()
{

    int n;
    cin >> n;
    int prev;
    cin >> prev;
    bool ch = true;
    int i = 1, c;
    while (i <= n - 1)
    {
        cin >> c;

        if (c > prev)
        {
            /*if(ch == true){
            ch= false;
            }*/
            ch = false;
            prev = c;
        }
        else if (c < prev)
        {
            if (ch == false)
            {
                cout << "false";
                return 0;
            }
            // ch  = true;
            prev = c;
        }
        else
        {
            cout << "false";
            return 0;
        }

        i++;
    }
    cout << "true";

    /*if(ch){
        cout << "true" ;
    } else{
        cout << "false";
    }*/
}