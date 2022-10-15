#include <iostream>
using namespace std;
int getresult(int m, int n, int p)
{

    int arr[m + 1][n + 1];
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> arr[i][j];
        }
    }
    int min = 0;

    for (int i = 1; i <= n; i++)
    {
        int max = arr[1][i];
        for (int j = 1; j <= m; j++)
        {
            if (j != p)
            {
                if (arr[j][i] > max)
                {
                    max = arr[j][i];
                }
            }
        }
        if (max > arr[p][i])
        {
            min = min + max - arr[p][i];
        }
    }
    return min;
}
int main()
{
    int t;
    cin >> t;
    int ans[t];
    int k = 0;
    while (k < t)
    {
        int m, n, p;
        cin >> m >> n >> p;
        ans[k] = getresult(m, n, p);
        k++;
    }

    for (int i = 0; i < t; i++)
        cout << "Case #" << i + 1 << ": " << ans[i] << endl;
}
