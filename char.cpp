#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    char x = 'A';
    for (int i = 0; i < n; i++)
    {
        x = 'A';
        x = x + i;
        cout << x;
    }
}