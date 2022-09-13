#include <iostream>
// Change in the given string itself. So no need to return or print anything

void replacePi(char input[])
{
    // Write your code here
    if (input[0] == '\0')
    {
        return;
    }
    int count = 0;
    for (int i = 0; input[i] != '\0'; i++)
    {
        count++;
    }
    if (input[0] == 'p' && input[1] == 'i')
    {
        int i = 1;
        while (i <= 2)
        {
            for (int j = count + i - 1; j >= 2; j--)
            {
                input[j] = input[j - 1];
            }
            i++;
        }
        input[0] = '3';
        input[1] = '.';
        input[2] = '1';
        input[3] = '4';
    }

    replacePi(input + 1);
}

using namespace std;

int main()
{
    char input[10000];
    cin.getline(input, 10000);
    replacePi(input);
    cout << input << endl;
}
