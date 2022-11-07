#include <iostream>

using namespace std;
bool isperf(int x)
{
    int i = 1;
    while (i * i <= x)
    {
        if (i * i == x)
        {
            return true;
        }
        i++;
    }
    return false;
}
int main()
{
    // your code goes here
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int t = n;
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            arr[i] = t--;
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = n - 1; j >= 0; j--)
            {
                if (arr[i] != 0)
                {
                    if (!isperf(arr[i] * arr[j]))
                    {
                        cout << arr[i] << " ";
                        arr[i] = 0;
                        break;
                    }
                }
            }
        }
        cout << endl;
    }
    return 0;
}
