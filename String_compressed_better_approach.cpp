#include <iostream>
#include <cstring>
#include <string>
using namespace std;

string getCompressedString(string &input)
{
    int i = 0;
    string output = "";
    for (i = 0; i < input.length(); ++i)
    {
        int count = 1;
        while (i < input.length() && input[i] == input[i + 1])
        {
            count++;
            i++;
        }
        if (count == 1)
        {
            output += input[i];
        }
        else
        {
            output += input[i];
            output += (count + '0');
        }
    }
    return output;
}

int main()
{
    int size = 1e6;
    string str;
    cin >> str;
    str = getCompressedString(str);
    cout << str << endl;
}