class Solution {
public:
    
    int findMinPath(vector<vector<int>>& grid,int x,int y,int m,int n,vector<vector<int>>&dp){
  if (x >= m || y >= n) {
    return INT_MAX;
  }
        
        if(dp[x][y]!=-1){
            return dp[x][y];
        }
        
  int a = findMinPath(grid, x + 1, y, m, n,dp) ;
 
  int b = findMinPath(grid, x, y + 1, m, n,dp) ;
 
 
  

    int ans= min(a,b);
	if(ans==INT_MAX){
		return dp[x][y]=grid[x][y];
	}

        return dp[x][y]=(ans + grid[x][y]);
}
    
    
    int minPathSum(vector<vector<int>>& grid) {
        vector<vector<int>>dp(grid.size()+1,vector<int>(grid[0].size(),-1));
        return findMinPath(grid,0,0,grid.size(),grid[0].size(),dp);
    }
};