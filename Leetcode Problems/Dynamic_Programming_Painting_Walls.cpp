class Solution {
public:
    
    int memo(int pnt,int wall,vector<int>& cost, vector<int>& time,vector<vector<int>>&dp){
        if(wall<=0){
            return 0;
        }
        
        if(pnt<0){
            return 1e9;
        }
        if(dp[pnt][wall]!=-1){
            return dp[pnt][wall];
        }
        int paint=cost[pnt]+memo(pnt-1,wall-(1+time[pnt]),cost,time,dp);
        int notPaint=memo(pnt-1,wall,cost,time,dp);
        return dp[pnt][wall]=min(paint,notPaint);   
    }
    
    
    int paintWalls(vector<int>& cost, vector<int>& time) {
        vector<vector<int>>dp(cost.size()+1,vector<int>(cost.size()+1,-1));
        return memo(cost.size()-1,cost.size(),cost,time,dp);
    }
};