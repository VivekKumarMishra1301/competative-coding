#include <iostream>
using namespace std;

void insertionSort(int *input, int size)
{
    // Write your code here
    for (int i = 1; i < size; i++)
    {
        int temp = input[i];
        int j = i - 1;
        while (input[j] > temp && j >= 0)
        {
            input[j + 1] = input[j];
            j--;
        }
        input[j + 1] = temp;
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

        for (int i = 0; i < size; i++)
        {
            cin >> input[i];
        }

        insertionSort(input, size);

        for (int i = 0; i < size; i++)
        {
            cout << input[i] << " ";
        }

        delete[] input;
        cout << endl;
    }

    return 0;
}