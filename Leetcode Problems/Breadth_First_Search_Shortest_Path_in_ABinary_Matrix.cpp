class Solution
{
public:
    //     bool isval(int r,int c,vector<vector<int>>&grid,vector<vector<bool>>&visited){
    //         if(r<0||c<0||r>=grid.size()||c>=grid[0].size()||grid[r][c]!=0||visited[r][c]){
    //             return false;
    //         }
    //         return true;
    //     }
    //     int traverse(int r,int c,vector<vector<int>>& grid,vector<vector<bool>>&visited,vector<vector<int>>&dp){
    //         // cout<<r<<":"<<c<<endl;
    //         if(r==grid.size()-1&&c==grid[0].size()-1&&grid[r][c]==0){
    //             return 1;
    //         }
    //         // visited[r][c]=true;

    //         if(r>=grid.size()||c>=grid[0].size()||r<0||c<0){
    //             return INT_MAX;
    //         }

    //         // if(visited[r][c]!=0){
    //         //     return visited[r][c];
    //         // }
    //         if(dp[r][c]!=-1){
    //             return dp[r][c];
    //         }
    //         visited[r][c]=true;
    //        int ans=INT_MAX;
    //         if(isval(r+1,c+1,grid,visited)){
    //             ans=min(ans,traverse(r+1,c+1,grid,visited,dp));
    //         }
    //          if(isval(r+1,c,grid,visited)){
    //             ans=min(ans,traverse(r+1,c,grid,visited,dp));
    //         }
    //          if(isval(r,c+1,grid,visited)){
    //             ans=min(ans,traverse(r,c+1,grid,visited,dp));
    //         }
    //          if(isval(r-1,c+1,grid,visited)){
    //             ans=min(ans,traverse(r-1,c+1,grid,visited,dp));
    //         }
    //          if(isval(r-1,c-1,grid,visited)){
    //             ans=min(ans,traverse(r-1,c-1,grid,visited,dp));
    //         }
    //          if(isval(r,c-1,grid,visited)){
    //             ans=min(ans,traverse(r,c-1,grid,visited,dp));
    //         }
    //          if(isval(r+1,c+1,grid,visited)){
    //             ans=min(ans,traverse(r+1,c-1,grid,visited,dp));
    //         }
    //          if(isval(r-1,c,grid,visited)){
    //             ans=min(ans,traverse(r-1,c,grid,visited,dp));
    //         }

    //         visited[r][c]=false;
    //         cout<<r<<" "<<c<<":"<<" "<<ans<<endl;
    //         if(ans==INT_MAX){
    //             return  dp[r][c]=ans;
    //         }
    //         cout<<r<<" "<<c<<":"<<ans<<endl;
    //         return  dp[r][c]=ans+1;
    //         // 1+min(,min(traverse(r+1,c,grid),traverse(r,c+1,grid)));
    //     }

    int shortestPathBinaryMatrix(vector<vector<int>> &grid)
    {
        if (grid[0][0] != 0)
        {
            return -1;
        }
        if (grid[grid.size() - 1][grid[0].size() - 1] != 0)
        {
            return -1;
        }
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), 0));
        // vector<vector<int>>dp(grid.size(),vector<int>(grid[0].size(),-1));
        // int hold=traverse(0,0,grid,visited,dp);
        // if(hold==INT_MAX){
        //     return -1;
        // }
        // return hold;
        queue<pair<int, int>> q;
        q.push({0, 0});
        int hold = 0;
        while (!q.empty())
        {
            int s = q.size();
            for (int i = 0; i < s; i++)
            {
                auto [r, c] = q.front();
                q.pop();
                if (r < 0 || c < 0 || r >= grid.size() || c >= grid[0].size() || grid[r][c] == 1 || visited[r][c])
                {
                    continue;
                }
                if (r == grid.size() - 1 && c == grid[0].size() - 1)
                {
                    // if(grid[r][c]==)
                    return hold + 1;
                }

                visited[r][c] = true;
                q.push({r - 1, c - 1});
                q.push({r + 1, c + 1});
                q.push({r, c - 1});
                q.push({r - 1, c});
                q.push({r + 1, c - 1});
                q.push({r - 1, c + 1});
                q.push({r, c + 1});
                q.push({r + 1, c});
            }
            hold++;
        }
        return -1;
    }
};