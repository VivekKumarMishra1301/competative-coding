#include <iostream>
void reverseStringWordWise(char input[])
{
    // Write your code here
    int count = 0;
    for (int i = 0; input[i] != '\0'; i++)
    {
        count++;
    }
    int i = 0, j = count - 1;
    while (i < j)
    {
        char temp = input[i];
        input[i] = input[j];
        input[j] = temp;
        i++;
        j--;
    }
    int cn = 0, st = 0;
    for (int i = 0; i < count; i++)
    {
        if (input[i] == ' ' || input[i + 1] == '\0')
        {
            int end;
            if (input[i + 1] == '\0')
            {
                end = cn;
            }
            else
            {
                end = cn - 1;
            }

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
        cn++;
    }
}

using namespace std;

int main()
{
    char input[1000];
    cin.getline(input, 1000);
    reverseStringWordWise(input);
    cout << input << endl;
}
