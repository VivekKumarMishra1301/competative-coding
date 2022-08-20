#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
void sub(string ip, string op)
{

    if (ip.length() == 0)
    {
        if (op != "")
        {

            cout << op << endl;
        }
        return;
    }
    string notpick = op;
    string pick = op + ip[0];

    ip = ip.substr(1);
    sub(ip, notpick);
    sub(ip, pick);
}

int main()
{
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    string ip, op;

    cin >> ip;

    sub(ip, op);

    return 0;
}
