#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main()
{
    // your code goes here
    int t;
    cin >> t;
    while (t--)
    {
        int p, q, r;
        cin >> p >> q >> r;

        if ((p + q + r) >= 6)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }

        // if(p!=q&&p!=r&&q!=r){
        //     cout<<"YES"<<endl;
        //     continue;
        // }

        // if(p==q&&q==r&&r==1){
        //     cout<<"NO"<<endl;
        //     continue;

        // }else if(p==q&&q==r&&r>1){
        //     cout<<"NO"<<endl;
        //     continue;

        // }

        // if(p==q||p==r||q==r){
        //     int num=min(p,min(q,r));
        //     int num1=max(p,max(q,r));

        // }

        //// if(p==q&&q==r&&r>1){
        ////     cout<<"YES"<<endl;
        ////     continue;
        //// }else if(p==q&&q==r&&r==1){
        ////     cout<<"NO"<<endl;
        ////     continue;
        //// }

        //// if(p==q&&q!=r&&r<q&&r!=1){
        ////    cout<<"YES"<<endl;
        ////    continue;
        //// }else if(p==q&&q!=r&&r<q&&r==1){
        ////     cout<<"NO"<<endl;
        ////     continue;
        //// }

        ////  if(p==r&&q!=r&&r>q&&q!=1){
        ////    cout<<"YES"<<endl;
        ////    continue;
        //// }else if(p==r&&q!=r&&r>q&&q==1){
        ////     cout<<"NO"<<endl;
        ////     continue;
        //// }

        ////   if(q==r&&p!=r&&r>p&&p!=1){
        ////    cout<<"YES"<<endl;
        ////    continue;
        //// }else if(q==r&&p!=r&&r>p&&p!=1){
        ////     cout<<"NO"<<endl;
        ////     continue;
        //// }

        //// if(p==q&&q!=r&&(r-q)>2){
        ////     cout<<"YES"<<endl;
        //// }else{
        ////     cout<<"NO"<<endl;
        //// }
    }
    return 0;
}
