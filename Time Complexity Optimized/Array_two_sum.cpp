#include <iostream>
#include <algorithm>
using namespace std;

int pairSum(int *arr, int n, int num)
{
    // Write your code here
    sort(arr, arr + n);
    int i = 0;
    int k = 0;
    int l = 1;
    int m = 1;

    int flag2 = 0;
    int j = n - 1;

    while (i < j)
    {
        if ((arr[i] + arr[j]) < num)
        {
            i++;
        }
        else if ((arr[i] + arr[j]) > num)
        {
            j--;
        }
        else
        {
            int count = 1;
            int count2 = 1;
            int num = 0;
            int flag = 0;
            if (arr[i] == arr[j])
            {
                num = j - i;
                i = i + j;
            }
            else if (arr[i] == arr[i + 1] || arr[j] == arr[j - 1])
            {
                flag = 1;
                if (arr[i] == arr[i + 1])
                {
                    // int count=0;
                    while (arr[i] == arr[i + 1])
                    {
                        i++;
                        count++;
                    }
                    i++;
                }
                if (arr[j] == arr[j - 1])
                {
                    // int count2=0;
                    while (arr[j] == arr[j - 1])
                    {
                        count2++;
                        j--;
                    }
                    j--;
                }
            }
            else
            {
                k++;
                i++;
                j--;
            }
            if (flag == 1)
            {
                k = k + count * count2;
            }
            while (num > 0)
            {
                k = k + num;
                num--;
            }
        }
    }
    return k;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int size;
        int x;

        cin >> size;
        int *input = new int[size];

        for (int i = 0; i < size; i++)
        {
            cin >> input[i];
        }

        cin >> x;

        cout << pairSum(input, size, x) << endl;

        delete[] input;
    }

    return 0;
}