#include <iostream>
using namespace std;

void sumOfTwoArrays(int *input1, int size1, int *input2, int size2, int *output)
{
    // Write your code here
    int carry = 0, i = size1 - 1, j = size2 - 1;
    int digit;
    int num;
    int size3;
    if (size1 >= size2)
    {
        size3 = size1 + 1;
    }
    else
    {
        size3 = size2 + 1;
    }
    while (size3 != -1)
    {
        if (i != -1 || j != -1)
        {
            if (i <= -1)
            {
                input1[i] = 0;
            }
            if (j <= -1)
            {
                input2[j] = 0;
            }
            num = input1[i] + input2[j] + carry;
        }
        else if (i == -1 && j == -1)
        {
            if (carry != 0)
            {
                num = carry;
            }
            else
            {
                num = carry;
            }
        }
        if (num / 10 == 0)
        {
            carry = 0;
        }
        else
        {
            carry = num / 10;
        }
        digit = num % 10;
        output[size3 - 1] = digit;
        size3--;
        i--;
        j--;
    }
}
int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int size1;
        cin >> size1;

        int *input1 = new int[size1];

        for (int i = 0; i < size1; ++i)
        {
            cin >> input1[i];
        }

        int size2;
        cin >> size2;

        int *input2 = new int[size2];

        for (int i = 0; i < size2; ++i)
        {
            cin >> input2[i];
        }

        int outsize = 1 + max(size1, size2);

        int *output = new int[outsize];

        sumOfTwoArrays(input1, size1, input2, size2, output);

        for (int i = 0; i < outsize; ++i)
        {
            cout << output[i] << " ";
        }

        delete[] input1;
        delete[] input2;
        delete[] output;
        cout << endl;
    }

    return 0;
}