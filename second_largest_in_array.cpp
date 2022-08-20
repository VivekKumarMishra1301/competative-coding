#include <iostream>
using namespace std;

int findSecondLargest(int *input, int n)
{
    // Write your code here
    int max = -2147483648;
    int max1 = -2147483648;
    for (int i = 0; i < n; i++)
    {

        if (input[i] > max)
        {

            max = input[i];
        }
    }

    for (int i = 0; i < n; i++)
    {

        if (input[i] > max1 && input[i] != max)
        {

            max1 = input[i];
        }
    }
    // if (max == max1 || n <= 1)
    // {
    //     return -2147483648;
    // }
    // else
    // {
    //     return max1;
    // }
    return max1;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        int size;
        cin >> size;
        int *input = new int[size];

        for (int i = 0; i < size; i++)
        {
            cin >> input[i];
        }

        cout << findSecondLargest(input, size) << endl;

        delete[] input;
    }

    return 0;
}