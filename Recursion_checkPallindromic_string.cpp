#include <iostream>
bool checkPalindrome(char input[])
{
    // Write your code here
    if (input[0] == '\0')
    {
        return true;
    }
    int k = 0;
    for (int i = 0; input[i] != '\0'; i++)
    {
        k++;
    }
    if (input[0] == input[k - 1])
    {
        input[k - 1] = '\0';

        return checkPalindrome(input + 1);
    }
    else
    {

        return false;
    }

    // bool check=checkPalindrome(input+1);
    // return check;
}

using namespace std;

int main()
{
    char input[50];
    cin >> input;

    if (checkPalindrome(input))
    {
        cout << "true" << endl;
    }
    else
    {
        cout << "false" << endl;
    }
}
