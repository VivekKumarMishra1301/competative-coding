#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<string> d;
void sub(string ip, string op)
{

    if (ip.length() == 0)
    {
        if (op != "")
        {

            d.push_back(op);

            // cout<<op<<endl;
        }
        return;
    }
    string notpick = op;
    string pick = op + ip[0];

    ip = ip.substr(1);
    sub(ip, notpick);
    sub(ip, pick);

    //     for(int j=0;j<1000;j++){
    //         if(str[j]!=""){
    //             cout<<str[i]<<endl;
    //         }
    //     }
}
int main()
{
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    string ip, op;

    cin >> ip;

    sub(ip, op);
    sort(d.begin(), d.end());
    for (int i = 0; i < d.size(); i++)
        cout << d[i] << '\n';

    return 0;
}
