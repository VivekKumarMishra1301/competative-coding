#include <iostream>
using namespace std;

int main()
{
    // your code goes here
    int t;
    cin >> t;
    while (t--)
    {
        int size;
        cin >> size;
        string bin;
        cin >> bin;

        if (bin == "1" || bin == "10")
        {
            cout << "NO" << endl;
            continue;
        }
        int counter = 0;
        for (auto i : bin)
        {
            if (i == '1')
            {
                counter++;
            }
        }
        if (counter <= 3)
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
