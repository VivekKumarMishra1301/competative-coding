#include <iostream>
#include <string>
using namespace std;

#include <bits/stdc++.h>

string findWinner(int n, int x, int y)
{
    vector<int> dp(n + 1, 0);
    // dp[0]=false;
    dp[1] = 1;
    dp[x] = true;
    dp[y] = true;
    int a = 0;
    int b = 0;
    int c = 0;
    for (int i = 2; i <= n; i++)
    {
        if (i == x || i == y)
        {
            dp[i] = 1;
            continue;
        }
        if (i - 1 >= 0)
        {
            a = dp[i - 1] ^ 1;
        }
        if (i - x >= 0)
        {
            b = dp[i - x] ^ 1;
        }
        if (i - y >= 0)
        {
            c = dp[i - y] ^ 1;
        }

        dp[i] = max(a, max(b, c));
        // 	bool x,y,z;
        // if(i<=x||i<=y){
        // 	dp[i]=true;
        // }else{
        // 	dp[i]=!dp[i-1];
        // 	dp[i]=!dp[i-x];
        // 	dp[i]=!dp[i-y];
        // }
        // if(i-1>=0&&dp[i-1]==false){

        // 	x=true;

        // }
        //  if(i-x>=0&&dp[i-x]==false){

        // 	y=true;

        // }
        //  if(i-y>=0&&dp[i-y]==false){

        // 	z=true;

        // }

        // if(x||y||z){
        // 	dp[i]=true;
        // }
        // else{
        // 	dp[i]=false;
        // }
    }
    if (dp[n] != 0)
    {
        return "Beerus";
    }
    else
    {
        return "Whis";
    }
    // Write your code here .
}

int main()
{
    int n, x, y;
    cin >> n >> x >> y;
    cout << findWinner(n, x, y);
}