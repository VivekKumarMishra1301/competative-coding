class Solution
{
public:
    bool isSafe(vector<vector<int>> &grid, int i, int j, int num, int n)
    {
        if (i < 0 || j < 0 || i >= n || j >= n || grid[i][j] != num)
        {
            return false;
        }
        return true;
    }

    bool find(vector<vector<int>> &grid, int i, int j, int num, int larg, int n)
    {
        cout << i << j << endl;
        if (num == larg)
            return true;
        if (isSafe(grid, i - 2, j - 1, num + 1, n))
        {
            return find(grid, i - 2, j - 1, num + 1, larg, n);
        }
        if (isSafe(grid, i - 2, j + 1, num + 1, n))
        {
            return find(grid, i - 2, j + 1, num + 1, larg, n);
        }
        if (isSafe(grid, i - 1, j - 2, num + 1, n))
        {
            return find(grid, i - 1, j - 2, num + 1, larg, n);
        }
        if (isSafe(grid, i - 1, j + 2, num + 1, n))
        {
            return find(grid, i - 1, j + 2, num + 1, larg, n);
        }
        if (isSafe(grid, i + 1, j - 2, num + 1, n))
        {
            return find(grid, i + 1, j - 2, num + 1, larg, n);
        }
        if (isSafe(grid, i + 2, j - 1, num + 1, n))
        {
            return find(grid, i + 2, j - 1, num + 1, larg, n);
        }
        if (isSafe(grid, i + 2, j + 1, num + 1, n))
        {
            return find(grid, i + 2, j + 1, num + 1, larg, n);
        }
        if (isSafe(grid, i + 1, j + 2, num + 1, n))
        {
            return find(grid, i + 1, j + 2, num + 1, larg, n);
        }
        return false;
    }

    bool checkValidGrid(vector<vector<int>> &grid)
    {
        if (grid[0][0] != 0)
        {
            return false;
        }
        // int k=0;
        // int l=0;
        int larg = grid.size() * grid.size() - 1;
        // for( int i=0;i<grid.size();i++){
        //     bool flag=false;
        //     for(int j=0;j<grid[i].size();j++){
        //         if(grid[i][j]==0){
        //             k=i;
        //             l=j;
        //             flag=true;
        //             break;
        //         }
        //     }
        //     if(flag)break;
        // }
        // cout<<larg<<k<<l;

        return find(grid, 0, 0, 0, larg, grid.size());
    }
};