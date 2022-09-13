#include <iostream>
#include <cstring>
using namespace std;

void removeConsecutiveDuplicates(char input[])
{
    // Write your code here

    int k = 1;
    int count = 0;
    for (int i = 0; input[i] != '\0'; i++)
    {
        count++;
    }

    for (int i = 1; i <= count; i++)
    {
        if (input[i] != input[i - 1])
        {
            input[k] = input[i];
            k++;
        }
    }
}

int main()
{
    int size = 1e6;
    char str[size];
    cin >> str;
    removeConsecutiveDuplicates(str);
    cout << str;
}