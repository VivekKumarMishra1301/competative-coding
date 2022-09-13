#include <iostream>
#include <cstring>
#include <string>
using namespace std;

string getCompressedString(string &input)
{
    // Write your code here.
    int count = 0;
    for (int i = 0; input[i] != '\0'; i++)
    {
        count++;
    }
    string cs;
    int lc = 0;
    char cc;
    for (int i = 0; i <= count; i++)
    {
        cc = input[i];
        lc = 0;
        for (int j = i; j <= count; j++)
        {
            if (cc == input[j])
            {
                lc++;
            }
            else
            {
                i = j - 1;
                break;
            }
        }
        if (lc == 1)
        {
            cs.push_back(cc);
        }
        else
        {
            cs.push_back(cc);

            if (lc == 2)
            {
                cs.push_back('2');
            }
            else if (lc == 3)
            {
                cs.push_back('3');
            }
            else if (lc == 4)
            {
                cs.push_back('4');
            }
            else if (lc == 5)
            {
                cs.push_back('5');
            }
            else if (lc == 6)
            {
                cs.push_back('6');
            }
            else if (lc == 7)
            {
                cs.push_back('7');
            }
            else if (lc == 8)
            {
                cs.push_back('8');
            }
            else if (lc == 9)
            {
                cs.push_back('9');
            }
        }
    }

    return cs;
}

int main()
{
    int size = 1e6;
    string str;
    cin >> str;
    str = getCompressedString(str);
    cout << str << endl;
}