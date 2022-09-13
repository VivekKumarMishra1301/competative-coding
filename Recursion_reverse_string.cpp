#include <iostream>

using namespace std;
void reverse(string a, int j, int i)
{
    if (i > j)
    {
        cout << a;
        return;
    }
    swap(a[i], a[j]);

    i++;

    j--;
    reverse(a, j, i);
}

int main()
{
    string a;
    cin >> a;
    int j = a.size();
    int i = 0;
    reverse(a, j - 1, i);

    // cout << a;
}