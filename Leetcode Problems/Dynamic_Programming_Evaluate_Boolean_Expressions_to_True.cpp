#include<bits/stdc++.h>
int mod=1e9+7;
long memo(int i,int j,int isTrue,string &s,vector<vector<vector<int>>>&dp){
    if(i>j){
        return 0;
    }
    if(i==j){
        if(isTrue){
            return s[i]=='T';
        }else{
            return s[i]=='F';
        }
    }
    if(dp[i][j][isTrue]!=-1){
        return dp[i][j][isTrue];
    }

    long ways=0;
    for(int ind=i+1;ind<j;ind=ind+2){
        long lT=memo(i,ind-1,1,s,dp);
        long lF=memo(i,ind-1,0,s,dp);
        long rT=memo(ind+1,j,1,s,dp);
        long rF=memo(ind+1,j,0,s,dp);
        if(s[ind]=='&'){
            if(isTrue){
                ways=(ways+(lT*rT)%mod)%mod;
            }else{
                ways=(ways+(lT*rF)%mod+(lF*rT)%mod+(lF*rF)%mod)%mod;
            }
        }else if(s[ind]=='|'){
            if(isTrue){
                ways=(ways+(lT*rT)%mod+(lF*rT)%mod+(lT*rF)%mod)%mod;
            }else{
                ways=(ways+(lF*rF)%mod)%mod;
            }
        }else if(s[ind]=='^'){
            if(isTrue){
                ways=(ways+(lT*rF)%mod+(lF*rT)%mod)%mod;
            }else{
                ways=(ways+(lT*rT)%mod+(lF*rF)%mod)%mod;
            }
        }
    }
    return dp[i][j][isTrue]=ways;

}

int evaluateExp(string & exp) {
    // Write your code here.
    vector<vector<vector<int>>>dp(exp.size()+1,vector<vector<int>>(exp.size()+1,vector<int>(2,-1)));
    return memo(0,exp.size()-1,1,exp,dp);
}