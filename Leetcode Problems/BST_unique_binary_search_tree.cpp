class Solution {
public:
    int calculate(int n,vector<int>&holddp){
        if(n<=1){
            return 1;
        }
        if(holddp[n]!=-1){
            return holddp[n];
        }
        int ans=0;
    for(int i=1;i<=n;i++){
        ans=ans+calculate(i-1,holddp)*calculate(n-i,holddp);
    }
        holddp[n]=ans;
        return ans;
    }
  
    
    
    int numTrees(int n) {
      vector<int>holddp(n+1,-1);
        return calculate(n,holddp);
          
    }
};