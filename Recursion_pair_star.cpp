#include <iostream>
// Change in the given string itself. So no need to return or print the changed string.

void pairStar(char input[])
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
    if (input[0] == input[1])
    {
        for (int j = count + 1; j > 1; j--)
        {
            input[j] = input[j - 1];
        }
        input[1] = '*';
    }

    pairStar(input + 1);
}

using namespace std;

int main()
{
    char input[100];
    cin.getline(input, 100);
    pairStar(input);
    cout << input << endl;
}
