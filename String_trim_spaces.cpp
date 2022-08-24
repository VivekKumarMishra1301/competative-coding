#include <iostream>
#include <cstring>
using namespace std;

void trimSpaces(char input[])
{
    // Write your code here
    int j = 0;
    char st[100000];
    for (int i = 0; input[i] != '\0'; i++)
    {
        if (input[i] != ' ')
        {
            st[j++] = input[i];
        }
    }

    for (int i = 0; st[i] != '\0'; i++)
    {
        input[i] = st[i];
        input[i + 1] = '\0';
    }
}

int main()
{
    char input[1000000];
    cin.getline(input, 1000000);
    trimSpaces(input);
    cout << input << endl;
}
