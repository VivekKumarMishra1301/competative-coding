#include <iostream>
#include <string.h>
using namespace std;
void helper(string input, string op)
{
    if (input.length() == 0)
    {
        cout << op << endl;

        return;
    }
    char c1 = (input[0] - 48) + 96;
    if (input[0] == '0')
        return;

    helper(input.substr(1), op + c1);
    if (input.size() > 1)
    {
        int d = (input[0] - 48) * 10 + (input[1] - 48);
        if (d > 26)
            return;
        char c2 = 96 + d;
        helper(input.substr(2), op + c2);
    }
}

void printAllPossibleCodes(string input)
{
    /*
    Given the input as a string, print all its possible combinations. You do not need to return anything.
    */
    string op = "";
    helper(input, op);
}

using namespace std;

int main()
{
    string input;
    cin >> input;

    printAllPossibleCodes(input);
    return 0;
}
