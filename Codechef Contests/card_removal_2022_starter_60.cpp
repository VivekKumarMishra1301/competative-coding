#include <iostream>
using namespace std;

int main()
{
    // your code goes here
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int arr[1000];
        int freq[10];
        for (int i = 1; i <= 10; i++)
        {
            freq[i] = 0;
        }
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            freq[arr[i]]++;
        }
        int maxfreq = freq[1];
        for (int i = 1; i <= 10; i++)
        {
            if (maxfreq < freq[i])
            {
                maxfreq = freq[i];
            }
        }
        cout << n - maxfreq << endl;
    }
    return 0;
}
