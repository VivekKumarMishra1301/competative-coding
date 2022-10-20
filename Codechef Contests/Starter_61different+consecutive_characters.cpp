#include <iostream>
using namespace std;
void getr()
{
    string st;
    int size;
    cin >> size;
    int counter = 0;
    cin >> st;
    for (int i = 0; i < size; i++)
    {
        if (st[i] == st[i + 1])
        {
            counter++;
        }
    }
    cout << counter << endl;
}
int main()
{
    // your code goes here
    int t;
    cin >> t;
    while (t--)
    {
        getr();
    }
    return 0;
}
