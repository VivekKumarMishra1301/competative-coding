#include <iostream>
using namespace std;
void print(int n, int i = 1)
{
    // write your code here
    if (i == n)
    {
        cout << i << " ";
        return;
    }
    cout << i << " ";
    print(n, i + 1);
}

int main()
{
    int n;
    cin >> n;

    print(n);
}
