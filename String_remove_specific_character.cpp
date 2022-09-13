#include <iostream>
#include <cstring>
using namespace std;

void removeAllOccurrencesOfChar(char input[], char c)
{
    // Write your code here
    int k = 0;
    int count = 0;
    for (int i = 0; input[i] != '\0'; i++)
    {
        count++;
    }
    int l = 0;
    while (l <= count)
    {
        if (input[l] != c)
        {
            input[k] = input[l];
            k++;
        }
        l++;
    }
}

int main()
{
    int size = 1e6;
    char str[size];
    cin.getline(str, size);
    char c;
    cin >> c;
    removeAllOccurrencesOfChar(str, c);
    cout << str;
}