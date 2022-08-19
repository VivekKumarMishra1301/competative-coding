#include <iostream>
#include <algorithm>
using namespace std;

void sortZeroesAndOne(int *input, int size)
{
    // Write your code here
    int beg = 0;
    int end = size - 1;
    int count1 = 0, count2 = 0;
    ;
    for (int i = 0; i < size; i++)
    {
        if (input[i] == 0)
        {
            count1++;
        }
        else
        {
            count2++;
        }
    }

    for (int i = 0; i < count1; i++)
    {
        input[i] = 0;
    }

    for (int i = count1; i < size; i++)
    {

        input[i] = 1;
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

        sortZeroesAndOne(input, size);

        for (int i = 0; i < size; ++i)
        {
            cout << input[i] << " ";
        }

        cout << endl;
        delete[] input;
    }

    return 0;
}