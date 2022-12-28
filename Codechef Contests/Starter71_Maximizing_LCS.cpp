#include <bits/stdc++.h>
#include <iostream>
using namespace std;
int lcs(string shabd1, string shabd2)
{
    int n = shabd1.size();
    int m = shabd2.size();
    vector<int> previous(m + 1, 0);
    vector<int> current(m + 1, 0);
    for (int i = 0; i <= m; i++)
    {
        previous[i] = 0;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (shabd1[i - 1] == shabd2[j - 1])
            {
                current[j] = 1 + previous[j - 1];
            }
            else
            {
                current[j] = max(previous[j], current[j - 1]);
            }
        }
        previous = current;
    }
    return previous[m] / 2;
}
int main()
{

    // your code goes here
    int t;
    cin >> t;
    while (t--)
    {
        int x;
        cin >> x;
        string org;
        cin >> org;
        // string s1=org.substr(0,x-1);
        // string s2=org.substr(x-1);
        // int maxi=0;
        // for(int i=x;i>1;i--){
        string s1 = org;
        string s2 = org;
        reverse(s2.begin(), s2.end());
        // cout<<s1<<" "<<s2<<" ";
        int countlcs = lcs(s1, s2);
        // if(count>maxi){
        //     maxi=count;
        // }

        //}

        // cout<<org<<" "<<s1<<" "<<s2<<endl;
        cout << countlcs << endl;
    }

    return 0;
}
