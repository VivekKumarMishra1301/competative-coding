#include <iostream>
using namespace std;
#include <algorithm>
void luigiAndUniformity()
{
    int n;
    cin >> n;
    int arr[n];
    int match[n] = {0};
    int hold[n] = {0};
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int max = arr[0];
    for (int i = 1; i < n; i++)
    {
        max = __gcd(max, arr[i]);
    }
    int div = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == max)
        {
            div++;
        }
    }
    cout << n - div << endl;
}

int main()
{
    // your code goes here
    int t;
    cin >> t;
    while (t--)
    {
        luigiAndUniformity();
    }
    return 0;
}
