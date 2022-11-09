#include <iostream>
using namespace std;
#include <cstring>
int main()
{
    // your code goes here
    int t;
    cin >> t;
    while (t--)
    {
        string str;
        int n;
        cin >> n;
        cin >> str;
        string match = str;
        string str1 = "";
        string str2 = "";
        for (int i = 0; i < n / 2; i++)
        {
            str1 = str1 + str[i];
        }
        for (int i = n / 2; i < n; i++)
        {
            str2 = str2 + str[i];
        }
        // cout<<str1+str2<<endl;
        // cout<<str2+str1<<endl;
        if ((str1 + str2) == match && (str2 + str1) == match)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
    return 0;
}
