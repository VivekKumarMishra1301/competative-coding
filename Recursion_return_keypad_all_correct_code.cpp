#include <iostream>
#include <string>
#include <string>
using namespace std;

string mapping[] = {" ", " ", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
int keypad(int num, string output[])
{
    if (num == 0)
    {
        output[0] = "";
        return 1;
    }
    int smalloutput = keypad(num / 10, output), len = mapping[num % 10].length();
    string newoutput[1000];
    for (int i = 0; i < smalloutput; i++)
    {
        newoutput[i] = output[i];
    }
    for (int i = 0; i < len; i++)
    {
        for (int j = 0; j < smalloutput; j++)
        {
            output[(smalloutput * i) + j] = newoutput[j] + mapping[num % 10][i];
        }
    }
    return smalloutput * len;
}

using namespace std;

int main()
{
    int num;
    cin >> num;

    string output[10000];
    int count = keypad(num, output);
    for (int i = 0; i < count && i < 10000; i++)
    {
        cout << output[i] << endl;
    }
    return 0;
}
