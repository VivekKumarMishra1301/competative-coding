#include <iostream>
using namespace std;

int main()
{
    // Write your code here
    int n;
    cin >> n;
    int count = 0, i = 0, root;
    if (n >= 0 && n <= 100000000)
    {
        while (i * i <= n)
        {
            i = i + 1;
            count = i;
        }
        root = count - 1;
        cout << root;
    }
    else
        cout << "pagal hai ka be";
}
