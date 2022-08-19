#include <iostream>
using namespace std;

int findUnique(int *arr, int size)
{
    int count = 0;
    // Write your code here
    for (int i = 0; i < size; i++)
    {
        count = 0;
        for (int j = 0; j < size; j++)
        {

            if (arr[i] == arr[j] && i != j)
            {
                count = 1;
                // continue;
            }
        }
        if (count == 0)
        {
            return arr[i];
        }
    }
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

        for (int i = 0; i < size; ++i)
        {
            cin >> input[i];
        }

        cout << findUnique(input, size) << endl;
    }

    return 0;
}