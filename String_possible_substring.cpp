#include <iostream>
#include <cstring>
using namespace std;

void printSubstrings(char input[])
{
    // Write your code here
    int i = 0;
    int k = 0;
    while (input[i] != '\0')
    {

        for (int j = i; j <= k; j++)
        {
            cout << input[j];
        }
        cout << endl;
        k++;
        if (input[k] == '\0')
        {
            i++;
            k = 0;
        }
    }
}

int main()
{
    int size = 1e6;
    char str[size];
    cin >> str;
    printSubstrings(str);
}