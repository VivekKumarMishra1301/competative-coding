#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int arr[1000];
int dp[10000][10000];
int c=0;

int  subset(int sum, int n){
    if(sum ==0){
        c++;
        return c ;
    }
    if(n == 0){
        return 0;
    }
    if(dp[n][sum]!=-1){
        return dp[n][sum];
    }
  
      if(arr[n-1]>sum)
      {
       dp[n][sum]=subset(sum-arr[n-1], n-1)+subset(sum, n-1); ;
       return dp[n][sum];
      }
    
    return c ;
}

int main() {
      
    int n, s;
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    cin>>s;
    for(int i=0;i<n+1;i++){
        for(int j=0;j<s+1;j++){
            dp[i][j]=-1;
        }
    }
   
    cout<< subset(s, n);
   
    return 0;
}