#include <iostream>
int helper(int *input, int si, int ei, int x)
{
    if (si <= ei)
    {
        int mid = (si + ei) / 2;
        if (input[mid] == x)
            return mid;
        else if (input[mid] < x)
            return helper(input, mid + 1, ei, x);
        else
            return helper(input, si, mid - 1, x);
    }
    return -1;
}

int binarySearch(int input[], int size, int element)
{
    return helper(input, 0, size - 1, element);
}
using namespace std;

int main()
{
    int input[100000], length, element, ans;
    cin >> length;
    for (int i = 0; i < length; i++)
    {
        cin >> input[i];
        ;
    }

    cin >> element;
    ans = binarySearch(input, length, element);
    cout << ans << endl;
}
