#include <iostream>
#include <string>
using namespace std;

#include <stack>
int countBracketReversals(string input)
{
    // Write your code here
    stack<char> str;
    if (input.size() % 2 != 0)
    {
        return -1;
    }
    for (int i = 0; input[i] != '\0'; i++)
    {
        if (input[i] == '{')
        {
            str.push(input[i]);
        }
        else
        {
            if (str.empty())
            {
                str.push(input[i]);
            }
            else if (!str.empty() && str.top() == '{')
            {
                str.pop();
            }
            else if (!str.empty() && str.top() == '}')
            {
                str.push(input[i]);
            }
            // if(str.top()=='{'){
            //     str.pop();
            // }else if(str.empty()||str.top()=='}'){
            //     str.push(input[i]);
            // }
        }
    }
    char c1;
    char c2;
    int count = 0;
    while (!str.empty())
    {
        c1 = str.top();
        str.pop();
        c2 = str.top();
        str.pop();
        if (c1 == c2)
        {
            count += 1;
        }
        else
        {
            count += 2;
        }
    }
    return count;
}

int main()
{
    string input;
    cin >> input;
    cout << countBracketReversals(input);
}