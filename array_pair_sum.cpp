#include <iostream>
using namespace std;

int pairSum(int *input, int size, int x)
{
    // Write your code here
    int count = 0;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if ((input[i] + input[j]) == x)
            {
                count++;
            }
            if (j == (size - 1))
            {
                input[i] = (-100000000);
            }
        }
    }
    return count;
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