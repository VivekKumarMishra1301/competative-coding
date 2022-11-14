#include <iostream>
using namespace std;
#include <algorithm>
#include <map>
bool match(string str, string s1, string s2)
{
    int hold[256] = {0};
    for (int i = 0; i < str.size(); i++)
    {
        hold[str[i]]++;
    }

    for (int i = 0; i < str.size(); i++)
    {
        if (hold[str[i]] % 2 != 0)
        {
            return false;
        }
    }

    return true;
}

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
        string s1 = "";
        string s2 = "";
        // reverse(str.begin(),str.end());
        // while(str.size()>0){
        //     s1=s1+str[str.size()-1];
        //     str.pop_back();
        //     if(str.size()>1){
        //         s2=s2+str[str.size()-2];
        //      str.pop_back();
        //     }
        // }

        if (str.size() % 2 == 0)
        {

            if (match(str, s1, s2))
            {
                cout << "YES" << endl;
            }
            else
            {
                cout << "NO" << endl;
            }
        }
        else
        {
            cout << "NO" << endl;
        }
    }
    return 0;
}
