#include <iostream>
#include <cstring>
using namespace std;

void reverseEachWord(char input[])
{
    // Write your code here
    int st = 0;
    int end = 0;
    for (int i = 0; input[i] != '\0'; i++)
    {
        if (input[i] == ' ' || input[i + 1] == '\0')
        {
            if (input[i + 1] == '\0')
            {
                end = i;
            }
            else
                end = i - 1;
            while (st < end)
            {
                char temp = input[st];
                input[st] = input[end];
                input[end] = temp;
                st++;
                end--;
            }
            st = i + 1;
        }
    }
}

int main()
{
    int size = 1e6;
    char str[size];
    cin.getline(str, size);
    reverseEachWord(str);
    cout << str;
}