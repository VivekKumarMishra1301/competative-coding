#include <iostream>
#include <cstring>
using namespace std;

char highestOccurringChar(char input[])
{
    // Write your code here
    int arr[256];
    for (int i = 0; i < 256; i++)
    {
        arr[i] = 0;
    }
    for (int i = 0; input[i] != '\0'; i++)
    {
        arr[input[i]]++;
    }

    int max = 0;
    int ind = 0;
    for (int i = 0; input[i] != '\0'; i++)
    {
        if (arr[input[i]] > max)
        {
            max = arr[input[i]];
            ind = i;
        }
    }

    return input[ind];
}

int main()
{
    int size = 1e6;
    char str[size];
    cin >> str;
    cout << highestOccurringChar(str);
}