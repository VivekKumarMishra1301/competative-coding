#include<bits/stdc++.h>
using namespace std;
int make(int n){
    if(n<=0){
        return 0;
    }
    int a=0;
    while(pow(a,2)<=n){
        a++;
    }
    return 1+make(n-pow(a-1,2));

};
int main(){
    int x;
    cin>>x;
    cout<<make(x)<<endl;
}