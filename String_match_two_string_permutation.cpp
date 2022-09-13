#include <iostream>
#include <cstring>
using namespace std;

bool isPermutation(char input1[], char input2[])
{
    // Write your code here
    int arr[256];
    for (int i = 0; i < 256; i++)
    {
        arr[i] = 0;
    }

    for (int i = 0; input1[i] != '\0'; i++)
    {
        arr[input1[i]]++;
    }
    for (int i = 0; input2[i] != '\0'; i++)
    {
        arr[input2[i]]--;
    }

    for (int i = 0; input1[i] != '\0'; i++)
    {
        if (arr[input1[i]] != 0)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    int size = 1e6;
    char str1[size];
    char str2[size];
    cin >> str1 >> str2;
    cout << (isPermutation(str1, str2) ? "true" : "false");
}