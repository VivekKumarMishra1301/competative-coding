#include <iostream>
using namespace std;

int main()
{

    int n;
    cin >> n;
    // Write your code here
    int i = 1;
    while (i <= n)
    {
        int j = i;
        int k = n;
        while (k > i)
        {
            cout << " ";
            k--;
        }
        while (j >= 1)
        {
            cout << j;
            j--;
        }
        int m = 2;
        while (m <= i)
        {
            cout << m;
            m = m + 1;
        }
        cout << endl;
        i = i + 1;
    }
}
