class Solution
{
public:
    // bool isval(int r,int c,vector<vector<int>>&grid){
    //     if(min(r,c)<0||r>=grid.size()||c>=grid[0].size()){
    //         return false;
    //     }
    //     return true;
    // }
    int mod = 1000000007;
    int getp(int i, int j, vector<vector<int>> &grid, vector<vector<int>> &dp, int ord)
    {
        if (min(i, j) < 0 || i >= grid.size() || j >= grid[0].size())
        {
            return 0;
        }
        if (grid[i][j] <= ord)
        {
            return 0;
        }
        if (dp[i][j] != -1)
        {
            return dp[i][j];
        }
        long ans = 0;
        // if(isval(i-1,j,grid)){
        ans = (ans + getp(i - 1, j, grid, dp, grid[i][j])) % mod;
        // }
        // if(isval(i+1,j,grid)){
        ans = (ans + getp(i + 1, j, grid, dp, grid[i][j])) % mod;
        // }
        // if(isval(i,j-1,grid)){
        ans = (ans + getp(i, j - 1, grid, dp, grid[i][j])) % mod;
        // }
        // if(isval(i,j+1,grid)){
        ans = (ans + getp(i, j + 1, grid, dp, grid[i][j])) % mod;
        // }

        return dp[i][j] = (1 + ans) % mod;
    }

    int countPaths(vector<vector<int>> &grid)
    {
        vector<vector<int>> dp(grid.size() + 1, vector<int>(grid[0].size() + 1, -1));

        int hold = 0;
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                // cout<<i<<j<<endl;
                hold = (hold + getp(i, j, grid, dp, 0)) % mod;
            }
        }
        return hold;
    }
};