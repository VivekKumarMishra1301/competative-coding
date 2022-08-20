#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
using namespace std;
// set<string> a;
vector<string> a;
void sub(string ip, string op)
{

    if (ip.length() == 0)
    {
        if (op != "")
        {
            int flag = 0;
            for (int i = 0; i < a.size(); i++)
            {
                if (a[i] == op)
                {
                    flag = 1;
                    break;
                }
            }
            if (flag == 0)
            {
                a.push_back(op);
            }
        }
        return;
    }
    char small;
    char cap;

    small = tolower(ip[0]);
    cap = toupper(ip[0]);

    ip = ip.substr(1);

    sub(ip, op + small);

    sub(ip, op + cap);
}
int main()
{
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    string ip, op;

    cin >> ip;

    sub(ip, op);

    for (int i = 0; i < a.size(); i++)
    {
        cout << a[i] << endl;
    }

    return 0;
}
