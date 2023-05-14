class Solution
{
public:
    int d(int i, int j, vector<vector<int>> &grid, int cnt, vector<vector<int>> &visited)
    {

        // maxi=max(cnt,maxi);

        //  if(i<0||j<0||i>=grid.size()||j>=grid[0].size()){
        //     return ;
        // }

        if (i >= grid.size() || j >= grid[0].size())
        {
            return 0;
        }
        if (grid[i][j] <= cnt)
        {
            return 0;
        }

        cout << grid[i][j] << endl;

        // visited[i][j]=true;

        if (visited[i][j] != -1)
        {
            return visited[i][j];
        }

        // int temp=cnt;

        // if(val(i-1,j+1,grid,grid[i][j])){
        // cnt++;
        int a = d(i - 1, j + 1, grid, grid[i][j], visited);
        // }

        // if(val(i,j+1,grid,grid[i][j])){
        // cnt++;
        int b = d(i, j + 1, grid, grid[i][j], visited);
        // }
        //  if(val(i+1,j+1,grid,grid[i][j])){
        // cnt++;
        int c = d(i + 1, j + 1, grid, grid[i][j], visited);
        // }

        // visited[i][j]=false;

        return visited[i][j] = 1 + max(a, max(b, c));
    }

    int maxMoves(vector<vector<int>> &grid)
    {

        int cnt = 0;
        vector<vector<int>> visited(grid.size() + 1, vector<int>(grid[0].size() + 1, -1));
        int maxi = 0;

        for (int i = 0; i < grid.size(); i++)
        {
            cout << "h" << endl;
            maxi = max(maxi, d(i, 0, grid, 0, visited) - 1);
            // maxi=max(cnt,maxi);
            cnt = 0;
        }
        return maxi;
    }
};