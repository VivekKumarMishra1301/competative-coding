#include <iostream>
#include <string>
using namespace std;
#include <stack>
bool checkRedundantBrackets(string expression)
{
    // Write your code here
    stack<char> str;
    for (int i = 0; expression[i] != '\0'; i++)
    {
        if (expression[i] < 97 || expression[i] > 122)
        {

            str.push(expression[i]);
        }
    }
    char x;
    if (!str.empty())
    {
        x = str.top();
        str.pop();
    }
    while (!str.empty())
    {

        if (str.top() == '(')
        {
            if (x != '(' && x != ')')
            {
                x = str.top();
                str.pop();
            }
            else
            {
                return true;
            }
        }
        else
        {
            x = str.top();
            str.pop();
        }
    }
    return false;
}

int main()
{
    string input;
    cin >> input;
    cout << ((checkRedundantBrackets(input)) ? "true" : "false");
}