#include <iostream>
#include <cstring>
using namespace std;

bool checkPalindrome(char str[])
{
    // Write your code here
    int count = 0;
    char check[1000000];
    for (int i = 0; str[i] != '\0'; i++)
    {
        count++;
    }
    int cn = count;
    for (int i = 0; i < count; i++)
    {
        check[cn - 1] = str[i];
        cn--;
    }
    for (int i = 0; i < count; i++)
    {
        if (check[i] != str[i])
        {
            return false;
        }
    }
    return true;
}

int main()
{
    int size = 1e6;
    char str[size];
    cin >> str;
    cout << (checkPalindrome(str) ? "true" : "false");
}