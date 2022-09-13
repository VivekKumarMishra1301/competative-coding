/*Given an integer array A of size n. Find and print all the leaders present in the input array. An array element A[i] is called Leader, if all the elements following it (i.e. present at its right) are less than or equal to A[i].
Print all the leader elements separated by space and in the same order they are present in the input array.*/
#include <iostream>
#include <climits>
using namespace std;
void Leaders(int *arr, int len)
{
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Print your output exactly in the same format as shown.
     * Don't print any extra line.
     */
    int flag = 0;
    for (int i = 0; i < len; i++)
    {
        if (i != len - 1)
        {
            for (int j = i + 1; j < len; j++)
            {

                if (arr[j] <= arr[i])
                {
                    flag = 1;
                }
                else
                {
                    flag = 0;
                    break;
                }
            }
            if (flag == 1)
            {
                cout << arr[i] << " ";
            }
        }
        else
            cout << arr[len - 1];
    }
}

int main()
{
    int len;
    cin >> len;
    int *arr = new int[len + 1];

    for (int i = 0; i < len; i++)
    {
        cin >> arr[i];
    }
    Leaders(arr, len);
}
