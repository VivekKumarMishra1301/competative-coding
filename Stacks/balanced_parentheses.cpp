#include <iostream>
#include <string>
using namespace std;

#include <stack>

bool isBalanced(string expression)
{

    // Write your code here
    stack<char> s;
    for (int i = 0; expression[i] != '\0'; i++)
    {
        if (expression[i] == '(')
        {
            s.push(expression[i]);
        }
        else
        {
            if (expression[i] == ')')
            {
                if (s.empty())
                {
                    return false;
                }
                s.pop();
            }
            else
            {
                return false;
            }
        }
    }
    if (s.empty())
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    string input;
    cin >> input;
    cout << ((isBalanced(input)) ? "true" : "false");
}