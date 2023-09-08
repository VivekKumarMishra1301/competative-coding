vector<int> findRepeatingAndMissingNumbers(vector<int> nums)
{
    // Write your code here.
    int x = 0;
    int y = 0;
    int xo = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        xo = xo ^ nums[i];
        xo = xo ^ (i + 1);
    }

    int setbit = 0;
    while (1)
    {
        if ((xo & (1 << setbit)) != 0)
        {
            break;
        }
        setbit++;
    }

    for (int i = 0; i < nums.size(); i++)
    {
        if ((nums[i] & (1 << setbit)) != 0)
        {
            x ^= nums[i];
        }
        else
        {
            y ^= nums[i];
        }
    }
    for (int i = 1; i <= nums.size(); i++)
    {
        if ((i & (1 << setbit)) != 0)
        {
            x ^= i;
        }
        else
        {
            y ^= i;
        }
    }

    int cnt = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] == x)
        {
            cnt++;
        }
    }
    if (cnt == 2)
        return {x, y};
    else
        return {y, x};
}
// BEST SOLUTION
#include <iostream>
using namespace std;

int main()
{

    int t, n;

    cin >> t;

    while (t--)
    {
        cin >> n;

        int ar[n + 1];

        for (int i = 1; i <= n; i++)
            cin >> ar[i];

        int resultXor = 0;

        for (int i = 1; i <= n; i++)
            resultXor = resultXor ^ ar[i];
        for (int i = 1; i <= n; i++)
            resultXor = resultXor ^ i;

        int setBit = resultXor & ~(resultXor - 1);

        int x = 0, y = 0;

        for (int i = 1; i <= n; i++)
        {
            if (ar[i] & setBit)
            {
                x = x ^ ar[i];
            }
            else
            {
                y = y ^ ar[i];
            }
        }

        for (int i = 1; i <= n; i++)
        {
            if (i & setBit)
            {
                x = x ^ i;
            }
            else
            {
                y = y ^ i;
            }
        }

        bool isXMissing = true;
        for (int i = 1; i <= ar[i]; i++)
        {
            if (ar[i] == x)
            {
                isXMissing = false;
                break;
            }
        }

        if (isXMissing == true)
            cout << "Missing Number = " << x << " repeating number = " << y << endl;
        else
            cout << "Missing Number = " << y << " repeating number = " << x << endl;
    }
}

/*
n          = 101100
n - 1      = 101011
~(n-1)     = 010100
n & ~(n-1) = 000100

*/